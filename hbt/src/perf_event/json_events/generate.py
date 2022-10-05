#!/usr/bin/env python3
# (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

import collections.abc
import csv
import json
import os
import re
from functools import reduce

from sortedcontainers import SortedSet


kGeneratedBase = "hbt/src/perf_event/json_events/generated"
kGeneratedBaseIntel = "hbt/src/perf_event/json_events/generated/intel"
kJsonEventsHeader = os.path.join(kGeneratedBaseIntel, "JsonEvents.h")
kDownloadedBase = "hbt/downloaded/json_events/intel/download.01.org/perfmon"
kCpuArchFile = "CpuArch"


def jeventUnitToPmuType(unit_str):
    if unit_str == "CBO":
        return "uncore_cbox"
    if unit_str == "CHA":
        return "uncore_cha"
    if unit_str == "HA":
        return "uncore_ha"
    if unit_str == "iMC":
        return "uncore_imc"
    if unit_str == "IIO":
        return "uncore_iio"
    if unit_str == "IRP":
        return "uncore_irp"
    if unit_str == "M2M":
        return "uncore_m2m"
    if unit_str == "M3UPI":
        return "uncore_m3upi"
    if unit_str == "PCU":
        return "uncore_pcu"
    if unit_str == "QPI" or unit_str == "QPI LL":
        return "uncore_qpi"
    if unit_str == "R2PCIe":
        return "uncore_r2pcie"
    if unit_str == "R3QPI":
        return "uncore_r3qpi"
    if unit_str == "SBO":
        return "uncore_sbox"
    if unit_str == "UBOX":
        return "uncore_ubox"
    if unit_str == "UPI LL":
        return "uncore_upi"
    if unit_str == "NCU":
        return "uncore_ncu"
    if unit_str == "ARB":
        return "uncore_arb"
    if unit_str == "EDC_UCLK":
        return "uncore_edc_uclk"
    if unit_str == "EDC_ECLK":
        return "uncore_edc_eclk"
    if unit_str == "iMC_UCLK":
        return "uncore_imc_uclk"
    if unit_str == "iMC_DCLK":
        return "uncore_imc_dclk"
    if unit_str == "M2PCIe":
        return "uncore_m2pcie"
    raise ValueError("Unsupported unit_str " + unit_str)


def sanitize(s):
    """Sanitize text blops"""
    return s.replace('"', '\\"').replace("\r\n", "\n")


def sanitize_name(s):
    """Sanitize CPU names"""
    return re.sub("[^0-9a-zA-Z_]", "_", s)


def parseScaleUnit(scale_unit_str):
    """Returns (scale_factor, scale_unit)"""
    # XXX: Support for byte conversion
    if scale_unit_str.endswith("Bytes"):
        return (int(scale_unit_str.strip()[:-5]), "Bytes")
    elif scale_unit_str.endswith("MiB"):
        return (float(scale_unit_str.strip()[:-4]), "MiB")
    else:
        raise ValueError(f'Unexpected ScaleUnit "{scale_unit_str}"')


def output_jevent_scale(h, jevent):
    if "ScaleUnit" in jevent:
        scale_factor, scale_unit = parseScaleUnit(jevent.get("ScaleUnit"))
        h.write(f"      ScaleData{{\n")
        h.write(f"        .scale_factor={scale_factor},\n")
        h.write(f'        .scale_unit=scaleUnitFromStr("{scale_unit}")')
        h.write(f"      }},\n")
    else:
        h.write("      std::nullopt, // ScaleUnit\n")


def output_jevent_encoding(event_type, h, jevent):
    h.write("      EventDef::Encoding{")
    # If multiple codes, only use the first one.
    # This only happens in Offcore events and the kernel
    # is wise enough to select the right response counter.
    code = jevent["EventCode"].split(",")[0]
    h.write(f".code={code}")

    if "UMask" in jevent:
        # Phi CPUs (and others) do not use EventCode anymore
        # to select the offcore response counter, but the UMask.
        # Kernel should select the right offcore MSR regardless
        # of the UMask, so ignore all but first.
        umask = jevent["UMask"].split(",")[0]
        h.write(f", .umask={umask}")
    if jevent.get("EdgeDetect", "0").strip() == "1":
        h.write(", .edge=true")
    if jevent.get("AnyThread", "0").strip() == "1":
        h.write(", .any=true")
    if jevent.get("Invert", "0").strip() == "1":
        h.write(", .inv=true")

    if "CounterMask" in jevent:
        h.write(f', .cmask={jevent.get("CounterMask")}')

    if "MSRValue" in jevent:
        # JSON file comes with some comma terminated entries.
        msr_values_str = jevent["MSRValue"].strip(",")
        h.write(f", .msr_values={{ {msr_values_str} }}")

    h.write("},\n")


def output_jevent_intel_features(event_type, h, jevent):
    first = True
    h.write("      EventDef::IntelFeatures{")
    if jevent.get("Data_LA", "0").strip() == "1":
        h.write(f'{"" if first else ", "}.data_la=true')
        first = False
    if jevent.get("L1_Hit_Indication", "0").strip() == "1":
        h.write(f'{"" if first else ", "}.l1_hit_indication=true')
        first = False
    if jevent.get("ELLC", "0").strip() == "1":
        h.write(f'{"" if first else ", "}.ellc=true')
        first = False
    if jevent.get("PEBS", "0").strip() != "0":
        h.write(f'{"" if first else ", "}.pebs={jevent.get("PEBS")}')
        first = False
    h.write("},\n")


def output_jevent(event_type, h, jevent):
    event_name = jevent["EventName"]
    assert event_name is not None and event_name, f"Missing EventName"

    brief_desc = sanitize(jevent["BriefDescription"])

    if not brief_desc or brief_desc == "tbd":
        brief_desc = f"{event_name} (Description is auto-generated)"
    pub_desc = sanitize(jevent["PublicDescription"])

    # No need to warn if missing PublicDescription since many events
    # do not provide it.
    if not pub_desc or pub_desc == "tbd":
        pub_desc = brief_desc

    h.write(f"  pmu_manager.addEvent(std::make_shared<EventDef>(\n")
    # Output PMU Type
    if event_type == "core":
        h.write("      PmuType::cpu,\n")
    elif event_type == "uncore":
        assert "Unit" in jevent
        pmu_type = jeventUnitToPmuType(jevent["Unit"])
        h.write(f"      PmuType::{pmu_type},\n")
    else:
        raise ValueError(f'Unknown event_type: "{event_type}"')

    # Output event ID
    h.write(f'      "{event_name}",\n')

    # Output encoding
    output_jevent_encoding(event_type, h, jevent)

    # Output brief_desc
    h.write(f'      R"({brief_desc})",\n')
    # Output full_desc
    h.write(f'      R"({pub_desc})",\n')
    # Output default_sampling_period
    if "SampleAfterValue" in jevent:
        sampling_period = int(jevent["SampleAfterValue"])
        assert sampling_period > 0
        h.write(f"      {sampling_period},\n")
    else:
        h.write("      std::nullopt,\n")
    # Output scale_data
    output_jevent_scale(h, jevent)

    # Output Intel features
    output_jevent_intel_features(event_type, h, jevent)

    # Output errata
    if "Errata" in jevent and jevent["Errata"] != "null":
        h.write(f'      R"({sanitize(jevent["Errata"])})"\n')
    else:
        h.write("      std::nullopt // Errata\n")
    h.write("  ));\n")


class CpuSku:
    def __init__(self, arch_str, model_id, model_str, steps):
        """Note: In Intel JSON Files, <model_str> uniquely determines the group
        of JSON files used."""
        self.arch_str = arch_str
        self.model_id = model_id
        self.model_str = model_str
        self.steps = steps
        if self.steps is not None:
            self.steps = self.steps.strip()
            assert self.steps[0] == "["
            assert self.steps[-1] == "]"
            self.steps = list(self.steps[1:-1])

        self.event_groups = []

    def __repr__(self):
        s = f"Arch: {self.arch_str}, Model: {self.model_str} id: {self.model_id}"
        if self.steps is not None:
            s += f" Steps: {self.steps}"
        return s


class EventGroup:
    def __init__(self, filename, event_type, is_exp, jevents):
        assert filename[-5:] == ".json"
        self.filename = filename
        self.event_type = event_type
        self.is_exp = is_exp
        self.jevents = jevents
        self.namespace = sanitize_name(filename[:-5]).lower()

    def __repr__(self):
        return (
            f"<EventGroup filename: {self.filename} event_type: {self.event_type} "
            f"experimental: {self.is_exp} "
            f"{self.namespace} n_events: {len(self.jevents)}>"
        )

    @staticmethod
    def make_from_json_file(model_str, event_type, is_exp, filename):
        """Load filename info and load JSON if it exists and it is supported"""
        path = os.path.join(kDownloadedBase, model_str, filename)

        if "_inst_" in path:
            print("Instruction definition not yet supported. Skipping: ", path)
            return None

        if "matrix" in path:
            print("Matrix definitions not yet supported. Skipping: ", path)
            return None

        if not os.path.isfile(path):
            print(
                f"Igoring csv entry with file {path} because json file not present. "
                f"If you want to generate events for this file make sure to download it"
            )
            return None

        # Only know how to handle these tyes of event groups.
        if event_type not in ["core", "uncore"]:
            print(f'event_type: "{event_type}" is not supported. Found in {filename}')
            return None

        with open(path) as h:
            print("Opening ", path)
            jevents = json.load(h)
            print("Done with ", path)

        return EventGroup(filename, event_type, is_exp, jevents)


def create_cpp_jevents_file(base_path, event_group, ev_g_skus):
    """
    Create a CPP file with an addEvents function that
    adds all events to their PMU.
    """
    assert event_group.jevents
    with open(
        os.path.join(base_path, f"{event_group.namespace}.cpp"),
        "w",
        encoding="ascii",
        errors="backslashreplace",
    ) as h:
        h.write(
            f"// Copyright (c) Meta Platforms, Inc. and affiliates.\n"
            f"//\n"
            f"// This source code is licensed under the MIT license found in the\n"
            f"// LICENSE file in the root directory of this source tree.\n\n"
            f"// Generated file. Do not modify.\n\n"
            f"#include <stdexcept>\n"
            f'#include "{kJsonEventsHeader}"\n\n'
            f"namespace facebook::hbt::perf_event::generated {{\n"
            f"namespace {event_group.namespace} {{\n\n"
        )

        added_events = set()

        h.write(f"void addEvents(PmuDeviceManager& pmu_manager) {{\n")
        h.write(
            f"\n/*\n  Events from {event_group.filename} "
            f'({len(event_group.jevents)}{" experimental" if event_group.is_exp else ""} events).\n\n'
        )
        h.write("  Supported SKUs: \n")
        for sku in ev_g_skus:
            h.write(f"      - {sku}\n")
        h.write("*/\n")

        for ev in event_group.jevents:
            if "Deprecated" in ev and ev["Deprecated"] == "1":
                continue
            if ev["EventName"] in added_events:
                print(
                    f"Event \"{ev['EventName']}\" in \"{event_group.event_type}\" already added, skipping."
                )
                continue
            output_jevent(event_group.event_type, h, ev)
            added_events.add(ev["EventName"])
            h.write("\n")

        h.write(
            f"}}\n\n"
            f"}} // namespace {event_group.namespace}\n"
            f"}} // namespace facebook::hbt::perf_event::generated\n"
        )


def create_cpu_arch_file(base_path, basename, skus, event_groups):
    """Create a header file with list of all the architectures"""
    with open(
        os.path.join(base_path, basename + ".h"),
        "w",
        encoding="ascii",
        errors="backslashreplace",
    ) as h:
        h.write(
            "// Copyright (c) Meta Platforms, Inc. and affiliates.\n"
            "//\n"
            "// This source code is licensed under the MIT license found in the\n"
            "// LICENSE file in the root directory of this source tree.\n\n"
            "// Generated file. Do not modify.\n\n"
            "#pragma once\n\n"
            "namespace facebook::hbt::perf_event {\n\n"
        )

        # Create enumeration of CPU Families.
        h.write(
            "enum class CpuFamily {\n"
            "  AMD,\n"
            "  INTEL,\n"
            "  UNKNOWN\n"
            "};\n\n"
            "inline std::ostream& operator<<(std::ostream& os, CpuFamily f) {\n"
            "  switch(f) {\n"
            '    case CpuFamily::AMD: return os << "AMD";\n'
            '    case CpuFamily::INTEL: return os << "INTEL";\n'
            '    case CpuFamily::UNKNOWN: return os << "UNKNOWN";\n'
            "  }\n"
            "}\n"
        )

        # Create function to create CpuArch from integer.
        h.write(
            "// Create CpuFamily enumeration from integer.\n"
            "inline CpuFamily makeCpuFamily(uint32_t cpu_family) {\n"
            "  switch (cpu_family) {\n"
            "    case  6: return CpuFamily::INTEL;\n"
            "    case  25: return CpuFamily::AMD;\n"
            "    // Not recognized CPU model.\n"
            "    default: return CpuFamily::UNKNOWN;\n"
            "  }\n"
            "}\n\n"
        )

        # Create enumeration of CPU Architectures. Treat AMD as a special case.
        h.write(
            "enum class CpuArch {\n"
            "  // AMD Architectures\n"
            "  MILAN,\n"
            "  // Intel Architectures Sorted by model id.\n"
        )

        added_architectures = SortedSet()
        for sku in sorted(skus.values(), key=lambda sku: sku.model_id):
            if sku.model_str not in added_architectures:
                added_architectures.add(sku.model_str)

        for cpu_arch in added_architectures:
            h.write(f"  {sanitize_name(cpu_arch)},\n")

        h.write("  // Not recognized CPU model.\n" "  UNKNOWN\n" "};\n\n")

        # Create function to print CpuArch.
        h.write(
            "inline std::ostream & operator<<(std::ostream & os, CpuArch ev) {\n"
            "  switch (ev) {\n"
            '   case CpuArch::MILAN: return os << "MILAN";\n'
        )

        for cpu_arch in added_architectures:
            h.write(
                f'   case CpuArch::{sanitize_name(cpu_arch)}: return os << "{cpu_arch}";\n'
            )

        h.write('   default: return os << "<UnknownCPU>";\n' "  }\n" "}\n\n")

        # Create function to create CpuArch.
        h.write(
            "// Create CpuArch from CPU information in integers.\n"
            "inline CpuArch makeCpuArch(uint32_t cpu_family_num, uint32_t cpu_model_num, uint32_t cpu_step_num)\n"
            "{\n"
            # AMD CPUs.
            "  auto cpu_family = makeCpuFamily(cpu_family_num);\n"
            "  if (cpu_family == CpuFamily::AMD) {\n"
            "    switch (cpu_model_num) {\n"
            "      case 1:\n"
            "        return CpuArch::MILAN;\n"
            "    }\n"
            "  }\n"
        )

        h.write(
            "  else if (cpu_family == CpuFamily::INTEL) {\n"
            "    switch (cpu_model_num) {\n"
        )
        # Intel CPUS. Sort by model so we can deduplicate the model case statements.
        last_model = None
        must_close_step_switch = False
        for sku in sorted(skus.values(), key=lambda sku: sku.model_id):
            model_str = sanitize_name(sku.model_str)
            if last_model != sku.model_id:
                if must_close_step_switch:
                    h.write(
                        "          // Step count is extensive. No need for default\n"
                    )
                    h.write("        }  // End of step switch\n\n")
                    must_close_step_switch = False

                # Only output model's case statement when we encounter a new model.
                h.write(f"      case {sku.model_id}:")
            if sku.steps:
                if last_model != sku.model_id:
                    # Only output step's switch when we encounter a new model.
                    h.write("\n        switch (cpu_step_num) {\n")
                # All but last step.
                for step in sku.steps[:-1]:
                    h.write(f"          case 0x{step}: [[fallthrough]];\n")

                h.write(f"          case 0x{sku.steps[-1]}:\n")
                h.write(f"            return CpuArch::{model_str};\n")
                # Leave switch open in case next sku is from the same model.
                must_close_step_switch = True
            else:
                h.write(f"   return CpuArch::{model_str};\n")
            last_model = sku.model_id

        h.write(
            "      default: return CpuArch::UNKNOWN;\n"
            "    } // End of model switch case\n"
            "  } // End of Intel Family if case\n"
            "\n  // Unknown CPU Family.\n"
            "  return CpuArch::UNKNOWN;\n"
            "}\n\n"
            "} // namespace facebook::hbt::perf_event\n"
        )


def create_headers(skus, event_groups):
    """Create .h file with functions to add JSON events to metrics."""
    with open(kJsonEventsHeader, "w", encoding="ascii", errors="backslashreplace") as h:
        h.write(f'#include "hbt/src/perf_event/PmuEvent.h"\n')
        h.write(f'#include "hbt/src/perf_event/PmuDevices.h"\n\n\n')

        # Declare all available addEvents functions, one per events group.
        h.write(f"namespace facebook::hbt::perf_event::generated {{\n\n")
        for event_group in event_groups.values():
            h.write(f"namespace {event_group.namespace} {{\n")
            h.write(f"  void addEvents(PmuDeviceManager& pmu_manager);\n")
            h.write(f"}} // namespace {event_group.namespace}\n\n")

        # Utility function.
        h.write("// Make a key by combining cpu_model ond cpu_step\n")
        h.write(
            "constexpr uint64_t toCpuKey(uint32_t cpu_model, uint32_t cpu_step) {\n"
        )
        h.write("  uint64_t r = cpu_model;\n")
        h.write("  return (r << 31) | cpu_step;\n")
        h.write("}\n")

        # Function to chose appropriate addEvents functions to call, depending on cpu_model
        h.write(
            f"\ninline void addEvents(uint32_t cpu_model, uint32_t step, PmuDeviceManager& pmu_manager) {{\n"
        )
        h.write(f"  uint64_t cpu_key = toCpuKey(cpu_model, step);\n\n")
        h.write(f"  switch(cpu_key) {{\n\n")

        for sku in sorted(skus.values(), key=lambda sku: sku.model_id):
            for step in sku.steps if sku.steps is not None else range(16):
                h.write(f"  case toCpuKey({sku.model_id}, 0x{step}): // fall-through\n")
            for cpp_file in sku.event_groups:
                assert (
                    cpp_file in event_groups.keys()
                ), f"{cpp_file} not in {event_groups.keys()}"
                event_group = event_groups[cpp_file]
                h.write(f"    // from {event_group.filename}\n")
                h.write(f"    {event_group.namespace}::addEvents(pmu_manager);\n")
            h.write(f"    break;\n\n")

        h.write(
            f'  default:\n    HBT_THROW_EINVAL() << "Unknown CPU model ID " + std::to_string(cpu_model);\n  }}\n'
        )
        h.write(f"}}\n\n")
        h.write(f"}} // facebook::hbt::perf_event::generated\n")


def create_target(event_groups):
    """Create TARGETS file for generated files."""
    with open(kGeneratedBase + "/TARGETS", "w") as h:
        h.write(
            "# @noautodeps\n\n"
            'load("@fbcode_macros//build_defs:cpp_library.bzl", "cpp_library")\n\n'
            'oncall("heartbeat")\n\n'
        )

        names = ",\n".join(
            [f'        "intel/{c.namespace}.cpp"' for c in event_groups.values()]
        )
        h.write(
            f"cpp_library(\n"
            f'    name = "JsonEvents",\n'
            f'    headers = ["intel/JsonEvents.h"],\n'
            f"    srcs = [\n{names}\n"
            f"    ],\n"
            f"    exported_deps = [\n"
            f'        "//hbt/src/perf_event:PmuDevices",\n'
            f'        "//hbt/src/perf_event:PmuEvent",\n'
            f"    ]\n"
            f")"
        )

        h.write(
            "\n\ncpp_library(\n"
            '    name = "CpuArch",\n'
            '    headers = ["CpuArch.h"],\n'
            "    deps = [\n"
            "    ],\n"
            ")"
        )


def parse_mapfile_csv(h):
    """Returns a list of CppFiles to create."""

    cpu_map = csv.reader(h)
    header = None
    # Currently only arch x86.
    arch_str = "x86"

    event_groups = {}
    skus = {}

    for family_model, version, filepath, event_type in cpu_map:
        if header is None:
            header = [family_model, version, filepath, event_type]
            assert header == ["Family-model", "Version", "Filename", "EventType"]
            continue

        # Breakdown filepath.
        # Expect filepath to be equal to generated by event_file_to_path
        filepath = filepath.strip("/")
        model_str, filename = filepath.split("/")
        model_str = model_str.strip()
        filename = filename.strip()

        terms = family_model.split("-")
        if len(terms) == 3:
            manuf, family, model = terms
            steps = None
        elif len(terms) == 4:
            manuf, family, model, steps = terms
        else:
            raise ValueError("Unrecognized mapfiles.csv line " + terms)

        # Currently only support Intel.
        assert manuf == "GenuineIntel"
        assert family == "6"

        # Breakdown of EventType
        terms = event_type.split()
        event_type = terms[0]
        model = int(model, 16)
        if len(terms) == 1:
            is_experimental = False
        elif len(terms) == 2:
            assert terms[1] == "experimental"
            is_experimental = True
        else:
            raise ValueError("Unrecognized EventType string " + event_type)

        if filename not in event_groups:
            new_event_group = EventGroup.make_from_json_file(
                model_str, event_type, is_experimental, filename
            )
            if new_event_group:
                event_groups[filename] = new_event_group
            else:
                continue

        sku_key = (arch_str, model, steps)

        if sku_key not in skus:
            skus[sku_key] = CpuSku(arch_str, model, model_str, steps)

        skus[sku_key].event_groups.append(filename)

    return event_groups, skus


def generate():
    event_groups = None
    skus = None

    with open(os.path.join(kDownloadedBase, "mapfile.csv")) as h:
        event_groups, skus = parse_mapfile_csv(h)

    print("Generate cpp files: ", event_groups.keys())
    for filename, event_group in event_groups.items():
        # CpuSkus with this event group.
        ev_g_skus = [s for s in skus.values() if filename in s.event_groups]
        create_cpp_jevents_file(kGeneratedBaseIntel, event_group, ev_g_skus)

    create_cpu_arch_file(kGeneratedBase, kCpuArchFile, skus, event_groups)
    create_headers(skus, event_groups)
    create_target(event_groups)


if __name__ == "__main__":
    generate()
