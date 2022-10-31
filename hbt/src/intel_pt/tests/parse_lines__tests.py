#!/usr/bin/env python3
# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

from __future__ import absolute_import, division, print_function, unicode_literals

import collections
import unittest

from hbt.intel_pt.tracer import Tracer


class ParseLinesTest(unittest.TestCase):
    def test_stress(self):
        sym_calls = collections.defaultdict(int)
        sym_rets = collections.defaultdict(int)

        with open("hbt/src/intel_pt/examples/perf_script_output__stress.txt") as h:
            last_tstamp = -1
            exp_next_level = None

            for l in h.readlines():
                p = Tracer.parse_line(l)
                self.assertTrue(p is not None, l)
                # print(p.keys())
                self.assertEqual(p["comm"], "stress")
                self.assertLessEqual(last_tstamp, p["tstamp"])
                last_tstamp = p["tstamp"]

                level = p["level"]
                if "call" in p["flags"]:
                    if exp_next_level is not None:
                        # Calls may increase callstack by two levels but only
                        # record one symbol. Ignore the unrecorded symbols.
                        self.assertGreaterEqual(
                            level,
                            exp_next_level,
                            f"exp_next_level: {exp_next_level} with {p} str: {l}",
                        )

                    exp_next_level = level

                    if p["sym"] is not None:
                        sym_calls[p["sym"]] += 1

                elif "return" in p["flags"]:
                    if exp_next_level is not None:
                        # perf script seems to do whatever it wants with the indent.
                        self.assertLessEqual(
                            level,
                            exp_next_level + 1,
                            f"exp_next_level: {exp_next_level} with {p} str: {l}",
                        )
                    exp_next_level = level - 1
                    if p["sym"] is not None:
                        sym_rets[p["sym"]] += 1
                else:
                    exp_next_level = None

        for k, c in sym_calls.items():

            # Due to multiple reasons, the return symbol does not
            # necessarily matches the call symbol for all functions.
            # So currently just ignore return symbols in general.
            # Only validate for well behaved functions.
            # XXX: Address this issue.
            if k not in ["strcmp", "strdup", "__random", "__random_r"]:
                continue

            self.assertLessEqual(sym_rets[k], c, f"sym: {k}")

            self.assertGreaterEqual(
                sym_rets[k] + 2, c, f'sym "{k}" # calls {c} and # returns {sym_rets[k]}'
            )

        self.assertGreater(sym_calls["strcmp"], 100)
        self.assertGreater(sym_calls["strdup"], 1)
        self.assertGreater(sym_calls["rand@plt"], 1000)
        self.assertGreater(sym_calls["__random"], 1000)
        self.assertGreater(sym_calls["__random_r"], 1000)

    def test_stress_ushort(self):
        sym_calls = collections.defaultdict(int)
        sym_rets = collections.defaultdict(int)

        parsed_lines = []
        with open(
            "hbt/src/intel_pt/examples/perf_script_output__stress_ushort.txt"
        ) as h:
            last_tstamp = -1
            exp_next_level = None

            for l in h.readlines():
                p = Tracer.parse_line(l)
                self.assertTrue(p is not None, l)
                # print(p.keys())
                self.assertEqual(p["comm"], "stress")
                self.assertLessEqual(last_tstamp, p["tstamp"])
                last_tstamp = p["tstamp"]

                level = p["level"]
                if "call" in p["flags"]:
                    if exp_next_level is not None:
                        # Calls may increase callstack by two levels but only
                        # record one symbol. Ignore the unrecorded symbols.
                        self.assertGreaterEqual(
                            level,
                            exp_next_level,
                            f"exp_next_level: {exp_next_level} with {p} str: {l}",
                        )

                    exp_next_level = level

                    if p["sym"] is not None:
                        sym_calls[p["sym"]] += 1

                elif "return" in p["flags"]:
                    if exp_next_level is not None:
                        # perf script seems to do whatever it wants with the indent.
                        self.assertLessEqual(
                            level,
                            exp_next_level + 1,
                            f"exp_next_level: {exp_next_level} with {p} str: {l}",
                        )
                    exp_next_level = level - 1
                    if p["sym"] is not None:
                        sym_rets[p["sym"]] += 1
                else:
                    exp_next_level = None

                parsed_lines += [p]

        self.assertEqual(sym_calls["_IO_iter_file"], 1)
        self.assertEqual(sym_calls["_IO_iter_next"], 1)
        self.assertEqual(sym_calls["_IO_iter_end"], 1)
        self.assertEqual(sym_calls["_IO_list_resetlock"], 1)
        self.assertEqual(sym_calls["alarm@plt"], 1)
        self.assertEqual(sym_calls["usleep@plt"], 1)
        self.assertEqual(sym_calls["__GI___libc_nanosleep"], 1)
        self.assertEqual(sym_calls["rand@plt"], 5)
        self.assertEqual(sym_calls["__random"], 5)
        self.assertEqual(sym_calls["__random_r"], 5)

        trace_data = Tracer.to_catapult(parsed_lines)

        for i, d in enumerate(trace_data):
            print(f"\nEvent {i}: {d}")

        #
        # First chunk of calls are at 2nd level, with <NA> in first level.
        #

        # 3974.0 with one NA at first level and 4 calls at next level.
        dur_int = 25717334364525.0 - 25717334360551.0

        d = trace_data[0]
        self.assertEqual(d["pid"], "stress pid=1507506")
        self.assertEqual(d["ts"], 25717334360551.0)
        self.assertEqual(d["dur"], dur_int)
        self.assertTrue("<NA>" in d["name"])

        d = trace_data[1]
        self.assertEqual(d["pid"], "stress pid=1507506")
        self.assertEqual(d["ts"], 25717334360551.0 + 0 * dur_int / 4)
        self.assertEqual(d["dur"], dur_int / 4)
        self.assertTrue("_IO_iter_file" in d["name"])

        d = trace_data[2]
        self.assertEqual(d["pid"], "stress pid=1507506")
        self.assertEqual(d["ts"], 25717334360551.0 + 1 * dur_int / 4)
        self.assertEqual(d["dur"], dur_int / 4)
        self.assertTrue("_IO_iter_next" in d["name"])

        d = trace_data[3]
        self.assertEqual(d["pid"], "stress pid=1507506")
        self.assertEqual(d["ts"], 25717334360551.0 + 2 * dur_int / 4)
        self.assertEqual(d["dur"], dur_int / 4)
        self.assertTrue("_IO_iter_end" in d["name"])

        d = trace_data[4]
        self.assertEqual(d["pid"], "stress pid=1507506")
        self.assertEqual(d["ts"], 25717334360551.0 + 3 * dur_int / 4)
        self.assertEqual(d["dur"], dur_int / 4)
        self.assertTrue("_IO_list_resetlock" in d["name"])

        #
        # Next chunk of calls are at 2nd level, with <NA> at first level.
        #

        # 3125 units of time.
        dur_int = 25717334372545.0 - 25717334369420.0

        d = trace_data[5]
        self.assertEqual(d["pid"], "stress pid=1507506")
        self.assertEqual(d["ts"], 25717334369420.0)
        self.assertEqual(d["dur"], dur_int)
        self.assertTrue("<NA>" in d["name"])

        # 15 and there were 4 events at each level
        # the levels of rand@plt, __random and __random_r.
        dur_int = 25717337524020.0 - 25717337524005.0

        for i in range(4):
            d = trace_data[22 + i]
            print(i, d)
            self.assertEqual(d["pid"], "stress pid=1507506")
            self.assertTrue("rand@plt" in d["name"])
            self.assertEqual(d["ts"], 25717337524005.0 + i * dur_int / 4)
            self.assertEqual(d["dur"], dur_int / 4)

        for i in range(4):
            print(i)
            d = trace_data[26 + i]
            self.assertEqual(d["pid"], "stress pid=1507506")
            self.assertTrue("__random" in d["name"])
            self.assertEqual(d["ts"], 25717337524005.0 + i * dur_int / 4)
            self.assertEqual(d["dur"], dur_int / 4)

        for i in range(4):
            print(i)
            d = trace_data[30 + i]
            self.assertEqual(d["pid"], "stress pid=1507506")
            self.assertTrue("__random_r" in d["name"])
            self.assertEqual(d["ts"], 25717337524005.0 + i * dur_int / 4)
            self.assertEqual(d["dur"], dur_int / 4)

        self.assertEqual(len(trace_data), 34)

    def test_to_catapult_cpu_wide_tiny(self):
        trace_data = None
        with open(
            "hbt/src/intel_pt/examples/perf_script_output__cpu_wide_tiny.txt"
        ) as h:
            trace_data = Tracer.to_catapult(
                [Tracer.parse_line(l) for l in h.readlines()]
            )

        print(trace_data)

        d = trace_data[0]
        self.assertEqual(d["pid"], ":1686527 pid=1686527")
        self.assertEqual(d["ts"], 25738668928000.0)
        self.assertEqual(d["dur"], 4000.0)
        self.assertTrue("do_syscall_64" in d["name"])

        d = trace_data[1]
        self.assertEqual(d["pid"], ":1686527 pid=1686527")
        self.assertEqual(d["ts"], 25738668928000.0)
        self.assertEqual(d["dur"], 4000.0)
        self.assertTrue("__fentry__" in d["name"])

        self.assertEqual(len(trace_data), 2)

    def test_to_catapult_cpu_wide_short(self):
        trace_data = None
        with open(
            "hbt/src/intel_pt/examples/perf_script_output__cpu_wide_short.txt"
        ) as h:
            trace_data = Tracer.to_catapult(
                [Tracer.parse_line(l) for l in h.readlines()]
            )

        # No NAs because lower three levels never complete.
        print(trace_data)

        d = trace_data[0]
        self.assertEqual(d["pid"], ":1686527 pid=1686527")
        self.assertEqual(d["ts"], 25738668928000.0)
        self.assertTrue("__x86_indirect_thunk_rax" in d["name"])

        d = trace_data[1]
        self.assertEqual(d["pid"], ":1686527 pid=1686527")
        self.assertEqual(d["ts"], 25738668928000.0)
        self.assertTrue("__fentry__" in d["name"])

        d = trace_data[2]
        self.assertEqual(d["pid"], ":1686527 pid=1686527")
        self.assertEqual(d["ts"], 25738668928000.0)
        self.assertTrue("__fentry__" in d["name"])

        self.assertEqual(len(trace_data), 3)

    def test_to_catapult_cpu_wide(self):
        trace_data = None
        with open("hbt/src/intel_pt/examples/perf_script_output__cpu_wide.txt") as h:
            trace_data = Tracer.to_catapult(
                [Tracer.parse_line(l) for l in h.readlines()]
            )
        print(len(trace_data))
        print(trace_data[0:10])
        self.assertEqual(len(trace_data), 11704)

    def test_to_catapult_cpu_wide2(self):
        trace_data = None
        with open("hbt/src/intel_pt/examples/perf_script_output__cpu_wide2.txt") as h:
            trace_data = [Tracer.parse_line(l) for l in h.readlines()]
        print(len(trace_data))
        print(trace_data[0:10])
        self.assertEqual(len(trace_data), 20017)

    def test_to_catapult_tstamp_interval(self):
        s = (
            """  stress 1507505/1507505  [006] 1:   call                    sbrk     myIP mysym+0x0A (myfile)\n"""
            """  stress 1507505/1507505 [006] 1:   return                  sbrk     03 bb+0x1 (XX)\n"""
            """  stress 1507505/1507505 [006] 1:   call                    sbrk     03 bb+2 (XX)\n"""
            """  stress 1507505/1507505 [006] 2:   return               end      03 bb+0xA8 (XX)"""
        )

        parsed = [Tracer.parse_line(l) for l in s.split("\n")]
        print(parsed)
        t = Tracer.to_catapult(parsed)

        print("Trace: ", t)
        self.assertIsNotNone(t)

        # evna0 is <NA>s
        evna0, ev0, ev1 = t

        self.assertEqual(evna0["ts"], 1_000_000_000)
        self.assertEqual(evna0["dur"], 1_000_000_000)

        self.assertEqual(ev0["ts"], 1_000_000_000)
        self.assertEqual(ev0["dur"], 500_000_000)

        self.assertEqual(ev1["ts"], 1_500_000_000)
        self.assertEqual(ev1["dur"], 500_000_000)

    def test_to_catapult(self):
        with open("hbt/src/intel_pt/examples/perf_script_output__stress.txt") as h:
            c = Tracer.to_catapult([Tracer.parse_line(l) for l in h.readlines()])
            print(c[0:10])

    def test_problematic_ones(self):
        d = Tracer.parse_line(
            r"""        stress 1507505/1507505 [006] 25717.333433167:   call                            sbrk                                                     7fb22ed48f03 _dl_sysdep_start+0x183 (/usr/lib64/ld-2.17.so)"""
        )
        self.assertEqual(d["comm"], "stress")
        self.assertEqual(d["tstamp"], 25717.333433167)

        d = Tracer.parse_line(
            r"""       dbus-daemon  1136/1136  [010] 64697.683016740:   tr strt                 7f33cf65448f  0 [unknown] ([unknown])"""
        )
        self.assertEqual(d["comm"], "dbus-daemon")
        self.assertEqual(d["tstamp"], 64697.683016740)

        d = Tracer.parse_line(
            r"""                   hbt_cli 341466/341466 [010] 76962.196244568:   return                                          __sanitizer::AddrHashMap<CommonInterceptorMetadata, 31051ul>::acquire                                    7fc8c574e6b9 __sanitizer::AddrHashMap<CommonInterceptorMetadata, 31051ul>::acquire+0x249 (/data/users/davidca/fbsource-fbcode/fbcode/buck-out/dev/gen/tools/build/sanitizers/asan-ubsan-py#platform007-clang,shared/libtools_build_sanitizers_asan-ubsan-py.so)"""
        )
        self.assertEqual(d["comm"], "hbt_cli")
        self.assertEqual(d["tstamp"], 76962.196244568)

        d = Tracer.parse_line(
            r"""    TierUpdNotify 323074/323147 [010] 90836.776788973:   call                                                            operator new                  2213f1d [unknown] (/mnt/xarfuse/uid-173922/9ba26c1e-ns-4026531840/servicerouter/client/python/srproxy/srclient)"""
        )
        self.assertEqual(d["comm"], "TierUpdNotify")
        self.assertEqual(d["tstamp"], 90836.776788973)

        d = Tracer.parse_line(
            r"""                    smcc 1243972/1243972 [010] 91411.392966865:   tr end                          global constructors keyed to 000101                            465137 global constructors keyed to 000101+0x7 (/usr/local/bin/smcc)"""
        )
        self.assertEqual(d["comm"], "smcc")
        self.assertEqual(d["tstamp"], 91411.392966865)

        d = Tracer.parse_line(
            r"""TierUpdEvb 60000/60431 [010] 210953.579227473:   call                                            pthread_self@plt                                                              2e1ef7b virtual thunk to folly::EventBase::keepAliveAcquire()+0x2b (/usr/local/libexec/eden/edenfs)"""
        )
        self.assertEqual(d["comm"], "TierUpdEvb")
        self.assertEqual(d["tstamp"], 210953.579227473)

        d = Tracer.parse_line(
            r"""      tmux: server 129792/129792 [010] 226615.395902804:   tr strt             __GI___libc_poll                                0 [unknown] ([unknown])"""
        )
        self.assertEqual(d["comm"], "tmux: server")
        self.assertEqual(d["tstamp"], 226615.395902804)

        d = Tracer.parse_line(
            r"""           CfgrIO0 60004/61157 [010] 227377.192445036:   return                                          virtual thunk to folly::AsyncSocket::good() const                             251e811 virtual thunk to folly::AsyncSocket::good() const+0x41 (/usr/local/bin/scribe_cat)"""
        )
        self.assertEqual(d["comm"], "CfgrIO0")
        self.assertEqual(d["tstamp"], 227377.192445036)

        d = Tracer.parse_line(
            r"""       cfgator-sub 543111/550033 [010] 228100.096590179:   call                                                                    non-virtual thunk to folly::IOThreadPoolExecutor::getEventBase()                 7f13ddb3db31 apache::thrift::PooledRequestChannel::sendRequestResponse+0x331 (/tmp/par_unpack.hg_monitor.173922.fa3c55ceb84699d17db971c442533eba/libomnibus.so)"""
        )
        self.assertEqual(d["comm"], "cfgator-sub")
        self.assertEqual(d["tstamp"], 228100.096590179)

        d = Tracer.parse_line(
            r"""       cfgator-sub 60000/60391 [010] 229844.141397436:   call                                                    folly::IOBuf::operator delete                                          73e0c9 apache::thrift::ClientReceiveState::~ClientReceiveState+0xf9 (/usr/local/libexec/eden/edenfs)"""
        )
        self.assertEqual(d["comm"], "cfgator-sub")
        self.assertEqual(d["tstamp"], 229844.141397436)

        d = Tracer.parse_line(
            r"""       cfgator-sub 550036/550045 [010] 244787.010494922:   call                                                malloc                                    3d2d94c operator new+0xc (/tmp/par_unpack.hg_monitor.173922.fa3c55ceb84699d17db971c442533eba/servicerouter/client/python/srproxy/srclient)"""
        )
        self.assertEqual(d["comm"], "cfgator-sub")
        self.assertEqual(d["tstamp"], 244787.010494922)

        d = Tracer.parse_line(
            r"""   SR_TLSConnectio 2040982/2045006 [010] 245559.083044067:   call                                                    boost::move_detail::addr_impl_ref<boost::intrusive::slist_node<void*> const>::operator boost::intrusive::slist_node<void*> const&                                7fefba8223be boost::move_detail::addressof<boost::intrusive::slist_node<void*> const>+0xee (/data/users/davidca/fbsource-fbcode/fbcode/buck-out/dev/gen/folly/io/async/async_base#platform007-clang,shared/libfolly_io_async_async_base.so)"""
        )
        self.assertEqual(d["comm"], "SR_TLSConnectio")
        self.assertEqual(d["tstamp"], 245559.083044067)

        d = Tracer.parse_line(
            r"""        ThriftIO12 60000/60665 [010] 248062.212508164:   call                                                                                                                            TLS init function for apache::thrift::ServerInterface::requestParams_                         2556623 facebook::fb303::cpp2::BaseServiceAsyncProcessor::process_getRegexCounters<apache::thrift::CompactProtocolReader, apache::thrift::CompactProtocolWriter>+0x33 (/usr/local/libexec/eden/edenfs)"""
        )
        self.assertEqual(d["comm"], "ThriftIO12")
        self.assertEqual(d["tstamp"], 248062.212508164)
        self.assertEqual(d["offset"], 0x33)

        d = Tracer.parse_line(
            r""":3706494 3702301/3706494 [010] 132777.004045987:   call                    std::__shared_ptr<folly::EventBaseObserver, (__gnu_cxx::_Lock_policy)2>::operator bool           7f62d2342ec0 folly::EventBase::loopBody+0x1b40 (/data/users/davidca/fbsource-fbcode/fbcode/buck-out/dev/gen/folly/io/async/async_base#platform007-clang,shared/libfolly_io_async_async_base.so)"""
        )

        self.assertEqual(d["comm"], ":3706494")
        self.assertEqual(d["tstamp"], 132777.004045987)
        self.assertEqual(d["offset"], 0x1B40)

        d = Tracer.parse_line(
            r"""            process reaper 50008/4050263 [010] 138481.418471919:   tr strt             J_I2C/C2I adapters                              0 [unknown] ([unknown])"""
        )
        self.assertEqual(d["comm"], "process reaper")
        self.assertEqual(d["tstamp"], 138481.418471919)
        self.assertEqual(d["offset"], None)

        d = Tracer.parse_line(
            r"""SR_TLSConnectio 4085954/4090431 [010] 139242.109544395:   call                                                    void folly::Executor::KeepAlive<folly::Executor>::add<folly::futures::detail::Core<folly::Unit>::doCallback(folly::Executor::KeepAlive<folly::Executor>&&, folly::futures::detail::State)::{lambda(folly::Executor::KeepAlive<folly::Executor>&&)#1}>(folly::futures::detail::Core<folly::Unit>::doCallback(folly::Executor::KeepAlive<folly::Executor>&&, folly::futures::detail::State)::{lambda(folly::Executor::KeepAlive<folly::Executor>&&)#1}&&) &&::{lambda()#1}::operator()             7f3c8bde9ab8 folly::detail::function::FunctionTraits<void ()>::callSmall<void folly::Executor::KeepAlive<folly::Executor>::add<folly::futures::detail::Core<folly::Unit>::doCallback(folly::Executor::KeepAlive<folly::Executor>&&, folly::futures::detail::State)::{lambda(folly::Executor::KeepAlive<folly::Executor>&&)#1}>(folly::futures::detail::Core<folly::Unit>::doCallback(folly::Executor::KeepAlive<folly::Executor>&&, folly::futures::detail::State)::{lambda(folly::Executor::KeepAlive<folly::Executor>&&)#1}&&) &&::{lambda()#1}>+0x18 (/data/users/davidca/fbsource-fbcode/fbcode/buck-out/dev/gen/servicerouter/security/security#platform007-clang,shared/libservicerouter_security_security.so)"""
        )

        self.assertEqual(d["comm"], "SR_TLSConnectio")
        self.assertEqual(d["tstamp"], 139242.109544395)
        self.assertEqual(d["offset"], 0x18)

        d = Tracer.parse_line(
            r"""                  :1870951 1869014/1870951 [010] 169047.815132283:   return                                  std::__atomic_base<int>::operator++                                              7f12faad7d27 std::__atomic_base<int>::operator+++0x77 (/data/users/davidca/fbsource-fbcode/fbcode/buck-out/dev/gen/folly/io/async/async_base#platform007-clang,shared/libfolly_io_async_async_base.so)"""
        )

        self.assertEqual(d["comm"], ":1870951")
        self.assertEqual(d["tstamp"], 169047.815132283)
        self.assertEqual(d["offset"], 0x77)

        d = Tracer.parse_line(
            r""":2255891 2252702/2255891 [010] 174899.917887506:   call                                    7efd86f3ef90                                     7efd86f10e88 boost::iterators::operator+<folly::BitIterator<unsigned long*>, bool, std::random_access_iterator_tag, folly::bititerator_detail::BitReference<unsigned long&, unsigned long>, long>+0x38 (/data/users/davidca/fbsource-fbcode/fbcode/buck-out/dev/gen/folly/io/async/async_base#platform007-clang,shared/libfolly_io_async_async_base.so)"""
        )
        self.assertEqual(d["comm"], ":2255891")
        self.assertEqual(d["tstamp"], 174899.917887506)
        self.assertEqual(d["offset"], 0x38)

        d = Tracer.parse_line(
            r"""   instruction trace error type 1 time 214359.087082579 cpu 10 pid 3177 tid 12769 ip 0x7f56e76a626f code 5: Failed to get instruction"""
        )
        self.assertEqual(d["err_type"], 1)
        self.assertEqual(d["err_code"], 5)
        self.assertEqual(d["err_msg"], "Failed to get instruction")
        self.assertEqual(d["pid"], 3177)

        d = Tracer.parse_line(
            r"""           :958360    -1/958360 [010] 79174.714088246:   return                  __switch_to                                                  ffffffff8101848a __switch_to+0x23a ([kernel.kallsyms])"""
        )
        self.assertEqual(d["comm"], ":958360")
        self.assertEqual(d["pid"], -1)
        self.assertEqual(d["tstamp"], 79174.714088246)
        self.assertEqual(d["offset"], 0x23A)
        self.assertEqual(d["sym"], "__switch_to")
