#!/usr/bin/env python3
# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

import collections
import fcntl
import io
import os
import re
import signal
import subprocess
import sys
import time

import hbt.common
import uptime


class Tracer:
    def __init__(self, cpus, pid, event_filter=""):
        self.cpus = cpus
        self.pid = pid
        self.event_filter = event_filter
        self.popen_record = None
        self.popen_script = None

    def __del__(self):
        if self.popen_record:
            self.stop()

    def cmd_record(self, output_path):
        event_filter_str = self.event_filter if self.event_filter else ""
        cmd = [
            "sudo",
            "perf.real",
            "record",
            "-m512,1024",
            "-S",
            # XXX: For some unknown reason, branch=0 suddenly
            # gives a invalid argument error. Has perf tool updated?
            # Disable ret compression to avoid decoder errors.
            "-e",
            # f"intel_pt/branch=1,noretcomp=1/{event_filter_str}"
            f"intel_pt//{event_filter_str}",
        ]

        if self.cpus:
            cmd += ["-C", self.cpus]
        if self.pid:
            cmd += ["-p", str(self.pid)]
        if output_path:
            cmd += ["-o", output_path]

        return cmd

    def cmd_script(self, input_path):
        cmd = [
            "sudo",
            "perf.real",
            "script",
            "--itrace=cre",
            "-F+ip,+pid,+tid,+flags,+callindent,-event,-period",
            "--ns",
        ]
        if input_path:
            cmd += ["-i", input_path]
        return cmd

    def sudo_signal(self, sig, pid):
        # Do cmd instead of send_signal to use sudo.
        cmd = f"sudo kill -s {sig} {pid}"
        subprocess.check_output(cmd, text=True, shell=True)

    def start(self):
        assert self.popen_record is None
        assert self.popen_script is None

        self.last_segment = None

        cmd_record = self.cmd_record("-")
        cmd_script = self.cmd_script("-")

        print(f"to run record \"{' '.join(cmd_record)}\"")
        print(f"to run script \"{' '.join(cmd_script)}\"")

        self.popen_record = subprocess.Popen(
            cmd_record, stdout=subprocess.PIPE, stderr=subprocess.PIPE
        )
        self.popen_script = subprocess.Popen(
            cmd_script,
            universal_newlines=True,
            stdin=self.popen_record.stdout,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
        )

        # Make reads non-blocking
        def make_non_blocking(pipe):
            fd = pipe.fileno()
            fl = fcntl.fcntl(fd, fcntl.F_GETFL)
            fcntl.fcntl(fd, fcntl.F_SETFL, fl | os.O_NONBLOCK)

        make_non_blocking(self.popen_record.stderr)
        make_non_blocking(self.popen_script.stdout)
        make_non_blocking(self.popen_script.stderr)

        # Sleep to let perf subprocesses iniitialize.
        time.sleep(5.0)
        self.assert_perf_record_is_running()

    def stop(self):
        assert self.popen_record
        assert self.popen_script

        self.popen_record.stdout.close()
        self.popen_record.stderr.close()
        self.popen_script.stdout.close()
        self.popen_script.stderr.close()

        if self.popen_record.poll() is None:
            print("sending signal to perf record")
            self.sudo_signal(signal.SIGTERM, self.popen_record.pid)
        print("waiting for perf record")
        self.popen_record.wait()

        if self.popen_script.poll() is None:
            print("sending signal to perf script")
            self.sudo_signal(signal.SIGTERM, self.popen_script.pid)
        print("waiting for perf script")
        self.popen_script.wait()
        self.popen_record = None
        self.popen_script = None
        print("stop done")

    def assert_perf_record_is_running(self):
        ret = self.popen_record.poll()
        if ret is not None:
            if ret == 255:
                d = {
                    "type": hbt.common.EnvironmentErrorType.MissingPerfEventCaps,
                    "what": self.read_perf_record_errors(),
                }
                raise hbt.common.EnvironmentError(d)
            raise RuntimeError(self.read_perf_record_errors())

    def read_perf_record_errors(self):
        assert self.popen_record
        assert self.popen_record.poll() is None
        with io.TextIOWrapper(self.popen_record.stderr) as h:
            return "".join(h)

    def read_perf_script_errors(self):
        assert self.popen_script
        return "".join(self.popen_script.stderr)

    err_line_re = re.compile(
        r"""\s*instruction trace error """
        r"""type (?P<err_type>\d+) """
        r"""time (?P<tstamp>\d+\.?\d*) """
        r"""cpu (?P<cpu>\d+) """
        r"""pid (?P<pid>\-?\d+) """
        r"""tid (?P<tid>\-?\d+) """
        r"""ip (?P<ip>[\S]+) """
        r"""code (?P<err_code>\d+)\: """
        r"""(?P<err_msg>.*)"""
    )

    # Regex to parse each line. Memoized by re.
    line_re = re.compile(
        # Process name. If preceded by ":" it is tid.
        r"""^\s*(?P<comm>.*\S)"""
        # Process and Thread ID.
        r"""\s+(?P<pid>\-?\d+)/(?P<tid>\-?\d+)"""
        # CPU
        r"""\s+(?:\[(?P<cpu>\d+)\])"""
        # Timestamp event happened. More than one event may have the same.
        r"""\s+(?P<tstamp>\d+\.?\d*)\:\s"""
        # flags are always 19 characters with 2 spaces at the left
        # and one at the right.
        # See linux/tools/perf/builtin-script.c perf_sample__fprint_flags.
        # See linux/tools/perf/util/evsel_fprintf.c sample__fprintf_sym.
        r"""\s\s(?P<flags>.{19})\s"""
        # indent and symbol. Symbol can be all kind of crazy stuff, like "operator new"
        # or "constructor bla bla bla", so just check for at least 3 spaces at the end.
        r"""(?P<indent>\s*)"""
        # Following string is too complex. Try simpler.
        # r"""(?P<sym>(?:(?:\<.*\>)|(?:\(.*\))|(?:\S*operator (?:\S+ ?))|\S| const| &)+|(?:(?:global |constructors |(?:non-)?virtual thunk to |TLS init function for |J_I2C/C2I adapters )+.+\s{3}))?"""
        # Simpler version, at least three spaces.
        r"""(?P<sym>(?:\S+\s+)|(?:\S.*\s{3,})|\s)"""
        # Instruction Pointer.
        r"""(?P<ip>[\w|\d]+)"""
        # Call-site function name and offset.
        r"""\s(?:(?:\[unknown\])|"""
        # Following string is too complex. Try simpler.
        # r"""(?:(?P<func>(?:(?:\<.*\>)|(?:\(.*\))|(?:\S*operator (?:\S+ ?))|\S| const| &)+|(?:(?:global |constructors |(?:non-)?virtual thunk to |TLS init function for |J_I2C/C2I adapters )+.*))\+(?P<offset>[\d|\w]+)))"""
        # Simpler version, stop at last +.
        r"""(?:(?P<func>(?:\S(?:[^\+]|(?:operator\+\+?))*))"""
        r"""\+(?P<offset>[\d|\w]+)))"""
        # Source File.
        r"""\s+\((?P<src_file>\S+)\)"""
        # Unmatched remainder, should be empty.
        r"""(?P<unmatched>.*)$"""
    )

    @staticmethod
    def parse_line(s):
        g = Tracer.line_re.match(s)
        if g is None:
            # Try to match error line.
            g = Tracer.err_line_re.match(s)
            if g is None:
                print("did not match: ", s)
                return None

            err_type, tstamp, cpu, pid, tid, ip, err_code, err_msg = g.groups()
            # Return error
            return {
                "err_type": int(err_type),
                "tstamp": float(tstamp),
                "cpu": int(cpu),
                "pid": int(pid),
                "tid": int(tid),
                "ip": ip.strip(),
                "err_code": int(err_code),
                "err_msg": err_msg,
            }

        g = g.groups()

        (
            comm,
            pid,
            tid,
            cpu,
            tstamp,
            flags,
            indent,
            sym,
            ip,
            func,
            offset,
            src_file,
            unmatched,
        ) = g

        if unmatched:
            print(f"unmatched: {unmatched}")
            return None

        flags = flags.strip()

        if len(indent) % 4 != 0:
            # Handle special case where symbol is a short hexadecimal address.
            try:
                int(sym, base=16)
            except ValueError:
                pass
            except Exception:
                raise ValueError(
                    f"indent: {len(indent)} not a multiple of four"
                    f"\nstr: {s} \ngroup: {g}"
                )

        return {
            "comm": comm,
            "pid": int(pid),
            "tid": int(tid),
            "cpu": int(cpu),
            "tstamp": float(tstamp),
            "flags": flags,
            "src_file": src_file,
            # Remove initial tab and divide by four.
            # XXX: This is brittle because relies on tab settings in perf.
            "level": len(indent) // 4,
            "ip": ip.strip(),
            "sym": sym.strip(),
            "func": func,
            "offset": int(offset, base=16) if offset else None,
        }

    def is_running(self):
        if self.popen_record.poll() is not None:
            assert self.popen_record.poll() is not None

        return self.popen_script.poll() is None

    def trigger_snapshot(self):
        assert self.popen_record is not None
        assert self.popen_record.poll() is None
        # Find perf.real process inside shell.
        real_pid = subprocess.check_output(
            f"pgrep -P {self.popen_record.pid} perf.real", text=True, shell=True
        ).strip()
        # Send SIGUSR2 to trigger a collection of AUX data.
        self.sudo_signal(signal.SIGUSR2, real_pid)

    def snapshot(self, max_batch, max_retries=2):
        """Process up to max_batch entries."""
        # Avoid getting incomplete lines due to EOF by checking
        # that last readline has a trailing '\n', and if it does not,
        # saving the partial read value in self.last_segment.
        # See answer to:
        # https://stackoverflow.com/questions/45019304/what-value-does-readline-return-when-reaching-the-end-of-the-file-in-python/45019413#45019413

        end_time = uptime.uptime()

        print(f"Start collecting Intel PT snapshot until {end_time:3f} secs from boot")

        def sleep_a_bit():
            time.sleep(0.2)

        retries = 0
        parsed_lines = []
        for i in range(max_batch):
            if i and i % 50000 == 0:
                print(f"Processing {i}-th event")
            line = self.popen_script.stdout.readline()

            if len(line) == 0:
                print("Found empty line.")
                retries += 1
                if retries > max_retries:
                    break
                sleep_a_bit()
                continue

            if line[-1] != "\n":
                print("Found incomplete line.")
                if self.last_segment is None:
                    self.last_segment = line
                else:
                    self.last_segment += line

                retries += 1
                if retries > max_retries:
                    break
                else:
                    sleep_a_bit()
                    continue

            if self.last_segment:
                line = self.last_segment + line
                self.last_segment = None
            assert line[-1] == "\n"

            d = Tracer.parse_line(line)
            assert d is not None, f"{line}, {d}"
            parsed_lines.append(d)

            if d["tstamp"] >= end_time:
                print("Found end_time.")
                break

        return parsed_lines

    @staticmethod
    def to_catapult(d_lines):
        c = CatapultEmitter()
        c.process(d_lines)
        return c.events


class CatapultEmitter:
    def __init__(self):
        self.last_tstamp = None
        # {level: list of events}
        self.uncommited_evs = collections.defaultdict(list)
        self.events = []

    def emit_until_level(self, new_tstamp, last_stack, level, reasons):
        """Emit until level (inclusive)"""
        num_drop = max(0, min(len(last_stack), len(last_stack) - level))
        assert num_drop >= 0

        # print('num_drop: ', num_drop)
        # print('stack before dropping ', last_stack)

        reasons = " ".join(reasons)
        if reasons:
            reasons = f"[ended by {reasons}] "

        for i in reversed(range(num_drop)):
            # print(last_stack)
            i_level = len(last_stack) - i - 1
            s = last_stack[i_level]
            assert s is not None

            dur = new_tstamp - s["tstamp"]
            assert dur >= 0, f"negative duration: {dur}, {new_tstamp} stack: {s}"

            if s["func"] and s["offset"]:
                loc = f"at {s['func']}+{s['offset']}"
            else:
                loc = ""

            if "sym" in s:
                name = " ".join([s["sym"], loc, reasons])
            else:
                name = "<NA>"

            ts = s["tstamp"]
            new_ev = {
                "ph": "X",
                "cpu": s["cpu"],
                "pid": f"{s['comm']} pid={s['pid']}",
                "tid": s["tid"],
                "ts": ts,
                "dur": dur if dur > 0 else None,
                # "displayTimeUnit": "ns",
                "name": name + f" level {i_level}",
                "cat": "PT",
                "level": i_level,
            }

            if dur == 0 and self.last_tstamp is None:
                self.last_tstamp = ts
                # print("\n\nStarting tstamp interval ", new_ev)

            if self.last_tstamp is not None and self.last_tstamp == ts:
                # Means that we are in the middle of an timestamp interval
                self.uncommited_evs[i_level].append(new_ev)
                # print('new uncommited_evs: ', self.uncommited_evs)
            else:
                self.events.append(new_ev)

        return num_drop

    def append_nas(self, s, d, target_level):
        """Push NAs on top of s until stack reaches <target_level>."""
        target_num_levels = target_level + 1
        # print("append_nas for target_level: ", target_level)
        # print('stack', s)
        if target_num_levels <= len(s) or target_num_levels <= 0:
            return
        for _ in range(len(s), target_num_levels):
            s.append(
                {
                    "tstamp": d["tstamp"],
                    "cpu": d["cpu"],
                    "pid": d["pid"],
                    "tid": d["tid"],
                    "comm": d["comm"],
                    #'flags': d['flags'],
                    "func": None,
                    "offset": None,
                }
            )

    @staticmethod
    def flags_to_strs(flags):
        pre = []
        if "syscall" in flags:
            pre.append("syscall")
        elif "sysret" in flags:
            pre.append("syscall ret")

        if "tr start" in flags:
            pre.append("trace start")
        elif "tr end" in flags:
            pre.append("trace end")

        if "hw int" in flags:
            pre.append("hw int")
        elif "iret" in flags:
            pre.append("hw int ret")
        return pre

    def process(self, d_lines):
        """To Chrome Trace Viewer (Catapult)."""

        # One tid per CPU.
        per_cpu_active_thread = collections.defaultdict(lambda: None)

        # One last_stack per (pid, tid)
        last_stacks = collections.defaultdict(list)

        for d in d_lines:
            # print("d:", d)
            if d is None:
                continue

            d = d.copy()
            # Scale from seconds to nanoseconds.
            # Note that Chrome Trace thinks we are giving it microseconds but we are
            # really giving it nanoseconds, so there is a 1000 scale.
            d["tstamp"] = d["tstamp"] * 1_000_000_000
            ts = d["tstamp"]
            assert ts is not None

            tid = d["tid"]
            cpu = d["cpu"]

            cpu_last_tid = per_cpu_active_thread[cpu]
            if cpu_last_tid and cpu_last_tid != tid:
                # CPU is getting a new thread.
                cpu_last_stack = last_stacks[cpu_last_tid]
                n = self.emit_until_level(ts, cpu_last_stack, 0, ["ctxt switch"])
                assert len(cpu_last_stack) == n
                cpu_last_stack.clear()

            per_cpu_active_thread[cpu] = tid

            # print('doing: ', d)
            last_stack = last_stacks[tid]

            # If any change on what's going with trace, then finish all pending traces.
            if "err_type" in d.keys():
                # If there is an error we don't know what happened to the stack
                # meanwhile, so just assume that's still there.
                pass
            elif "tr strt" in d["flags"]:
                pass
            elif "tr end" in d["flags"]:
                n = self.emit_until_level(ts, last_stack, 0, ["trace end"])
                assert n == len(last_stack)
                last_stack.clear()
            elif (
                "call" in d["flags"]
                or "syscall" in d["flags"]
                or "hw int" in d["flags"]
            ):
                if len(last_stack) > d["level"]:
                    # There have been unrecorded returns.
                    flags_str = CatapultEmitter.flags_to_strs(d["flags"])
                    n = self.emit_until_level(ts, last_stack, d["level"] - 1, flags_str)
                    del last_stack[-n:]
                # Appends NAs if there has been unrecorded calls.
                self.append_nas(last_stack, d, d["level"] - 1)

                # Append new stack.
                last_stack.append(d)
                # print('\ncall: ', d)
                # print('\nafter call: ', last_stack)

            elif (
                "return" in d["flags"] or "sysret" in d["flags"] or "iret" in d["flags"]
            ):
                assert d["level"] >= 0
                # print('before ret', last_stack)
                # self.append_nas(last_stack, d, d['level'] - 2)

                if len(last_stack) > d["level"]:
                    flags_str = CatapultEmitter.flags_to_strs(d["flags"])
                    n = self.emit_until_level(ts, last_stack, d["level"], flags_str)
                    if n > 0:
                        del last_stack[-n:]
                # print('after ret', last_stack)

            # print('uncommited_evs: ', self.uncommited_evs, 'last_tstamp: ', self.last_tstamp)
            # last_tstamp is only set for uncommited events.
            assert (len(self.uncommited_evs) == 0) == (
                self.last_tstamp is None
            ), f"{self.uncommited_evs}, {self.last_tstamp}"

            # If this a new tstamp interval, then add uncommited_evs
            if self.last_tstamp is not None and self.last_tstamp != ts:
                if ts < self.last_tstamp:
                    print(
                        f"out of order events? last_tstamp: {self.last_tstamp}, {d}",
                        file=sys.stderr,
                    )

                # print(f'\n\nhandling events between {self.last_tstamp} and {ts}')
                # All functions at each level of the stack splits the time in the interval equally.
                for _l, evs in sorted(self.uncommited_evs.items()):
                    # Finish a tstamp interval, commit events. Equally split duration.
                    per_ev_dur = (ts - self.last_tstamp) / len(evs)
                    prev_ev_tstamp = self.last_tstamp
                    for ev in evs:
                        assert ev["ts"] == self.last_tstamp, f"{self.last_tstamp}, {ev}"
                        ev["ts"] = prev_ev_tstamp
                        ev["dur"] = per_ev_dur
                        prev_ev_tstamp += per_ev_dur
                        self.events.append(ev)

                self.uncommited_evs.clear()
                self.last_tstamp = None
