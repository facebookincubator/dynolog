// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

// Generated file. Do not modify.

#include <stdexcept>
#include "hbt/src/perf_event/json_events/generated/intel/JsonEvents.h"

namespace facebook::hbt::perf_event::generated {
namespace skylakex_uncore {

void addEvents(PmuDeviceManager& pmu_manager) {
  /*
    Events from skylakex_uncore.json (268 events).

    Supported SKUs:
        - Arch: x86, Model: SKX id: 85 Steps: ['0', '1', '2', '3', '4']
  */
  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_HIT",
      EventDef::Encoding{.code = 0x35, .umask = 0x14, .msr_values = {0x00}},
      R"(TOR Inserts; Hits from Local IO)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IO_MISS",
      EventDef::Encoding{.code = 0x35, .umask = 0x24, .msr_values = {0x00}},
      R"(TOR Inserts; Misses from Local IO)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA",
      EventDef::Encoding{.code = 0x35, .umask = 0x31, .msr_values = {0x00}},
      R"(TOR Inserts; All from Local iA)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.; All locally initiated requests from iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT",
      EventDef::Encoding{.code = 0x35, .umask = 0x11, .msr_values = {0x00}},
      R"(TOR Inserts; Hits from Local iA)",
      R"(Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS",
      EventDef::Encoding{.code = 0x35, .umask = 0x21, .msr_values = {0x00}},
      R"(TOR Inserts : All requests from iA Cores that Missed the LLC)",
      R"(TOR Inserts : All requests from iA Cores that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA",
      EventDef::Encoding{.code = 0x36, .umask = 0x31, .msr_values = {0x00}},
      R"(TOR Occupancy; All from Local iA)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T; All locally initiated requests from iA Cores)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT",
      EventDef::Encoding{.code = 0x36, .umask = 0x11, .msr_values = {0x00}},
      R"(TOR Occupancy; Hits from Local iA)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS",
      EventDef::Encoding{.code = 0x36, .umask = 0x21, .msr_values = {0x00}},
      R"(TOR Occupancy; Misses from Local iA)",
      R"(For each cycle, this event accumulates the number of valid entries in the TOR that match qualifications specified by the subevent.   T)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_UPI_CREDIT_OCCUPANCY.VN0_BL_NCS",
      EventDef::Encoding{.code = 0x3B, .umask = 0x80, .msr_values = {0x00}},
      R"(UPI Ingress Credits In Use Cycles; BL NCS VN0 Credits)",
      R"(Accumulates the number of UPI credits available in each cycle for either the AD or BL ring.  In order to send snoops, snoop responses, requests, data, etc to the UPI agent on the ring, it is necessary to first acquire a credit for the UPI ingress buffer.  This stat increments by the number of credits that are available each cycle.  This can be used in conjunction with the Credit Acquired event in order to calculate average credit lifetime.  This event supports filtering for the different types of credits that are available.  Note that you must select the link that you would like to monitor using the link select register, and you can only monitor 1 link at a time.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_HITME_HIT.EX_RDS",
      EventDef::Encoding{.code = 0x5F, .umask = 0x01, .msr_values = {0x00}},
      R"(Read request from a remote socket which hit in the HitMe Cache to a line In the E state)",
      R"(Counts read requests from a remote socket which hit in the HitME cache (used to cache the multi-socket Directory state) to a line in the E(Exclusive) state.  This includes the following read opcodes (RdCode, RdData, RdDataMigratory, RdCur, RdInv*, Inv*))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_FAST_ASSERTED.HORZ",
      EventDef::Encoding{.code = 0xA5, .umask = 0x02, .msr_values = {0x00}},
      R"(FaST wire asserted; Horizontal)",
      R"(Counts the number of cycles either the local or incoming distress signals are asserted.  Incoming distress includes up, dn and across.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_CLOCKTICKS",
      EventDef::Encoding{.code = 0x00, .umask = 0x00, .msr_values = {0x00}},
      R"(Clockticks of the uncore caching & home agent (CHA))",
      R"(Counts clockticks of the clock controlling the uncore caching and home agent (CHA).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_CORE_SNP.CORE_GTONE",
      EventDef::Encoding{.code = 0x33, .umask = 0x42, .msr_values = {0x00}},
      R"(Core Cross Snoops Issued; Multiple Core Requests)",
      R"(Counts the number of transactions that trigger a configurable number of cross snoops.  Cores are snooped if the transaction looks up the cache and determines that it is necessary based on the operation type and what CoreValid bits are set.  For example, if 2 CV bits are set on a data read, the cores must have the data in S state so it is not necessary to snoop them.  However, if only 1 CV bit is set the core my have modified the data.  If the transaction was an RFO, it would need to invalidate the lines.  This event can be filtered based on who triggered the initial snoop(s).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_CORE_SNP.EVICT_GTONE",
      EventDef::Encoding{.code = 0x33, .umask = 0x82, .msr_values = {0x00}},
      R"(Core Cross Snoops Issued; Multiple Eviction)",
      R"(Counts the number of transactions that trigger a configurable number of cross snoops.  Cores are snooped if the transaction looks up the cache and determines that it is necessary based on the operation type and what CoreValid bits are set.  For example, if 2 CV bits are set on a data read, the cores must have the data in S state so it is not necessary to snoop them.  However, if only 1 CV bit is set the core my have modified the data.  If the transaction was an RFO, it would need to invalidate the lines.  This event can be filtered based on who triggered the initial snoop(s).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_DIR_LOOKUP.SNP",
      EventDef::Encoding{.code = 0x53, .umask = 0x01, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory state lookups; Snoop Needed)",
      R"(Counts  transactions that looked into the multi-socket cacheline Directory state, and sent one or more snoops, because the Directory indicated it was needed)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_DIR_LOOKUP.NO_SNP",
      EventDef::Encoding{.code = 0x53, .umask = 0x02, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory state lookups; Snoop Not Needed)",
      R"(Counts transactions that looked into the multi-socket cacheline Directory state, and therefore did not send a snoop because the Directory indicated it was not needed)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_DIR_UPDATE.HA",
      EventDef::Encoding{.code = 0x54, .umask = 0x01, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory state updates; Directory Updated memory write from the HA pipe)",
      R"(Counts only multi-socket cacheline Directory state updates memory writes issued from the HA pipe. This does not include memory write requests which are for I (Invalid) or E (Exclusive) cachelines.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_DIR_UPDATE.TOR",
      EventDef::Encoding{.code = 0x54, .umask = 0x02, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory state updates; Directory Updated memory write from TOR pipe)",
      R"(Counts only multi-socket cacheline Directory state updates due to memory writes issued from the TOR pipe which are the result of remote transaction hitting the SF/LLC and returning data Core2Core. This does not include memory write requests which are for I (Invalid) or E (Exclusive) cachelines.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_IMC_READS_COUNT.NORMAL",
      EventDef::Encoding{.code = 0x59, .umask = 0x01, .msr_values = {0x00}},
      R"(Normal priority reads issued to the memory controller from the CHA)",
      R"(Counts when a normal (Non-Isochronous) read is issued to any of the memory controller channels from the CHA.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_IMC_WRITES_COUNT.FULL",
      EventDef::Encoding{.code = 0x5B, .umask = 0x01, .msr_values = {0x00}},
      R"(CHA to iMC Full Line Writes Issued; Full Line Non-ISOCH)",
      R"(Counts when a normal (Non-Isochronous) full line write is issued from the CHA to the any of the memory controller channels.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_MISC.RFO_HIT_S",
      EventDef::Encoding{.code = 0x39, .umask = 0x08, .msr_values = {0x00}},
      R"(Number of times that an RFO hit in S state.)",
      R"(Counts when a RFO (the Read for Ownership issued before a  write) request hit a cacheline in the S (Shared) state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.READS",
      EventDef::Encoding{.code = 0x50, .umask = 0x03, .msr_values = {0x00}},
      R"(Read requests)",
      R"(Counts read requests made into this CHA. Reads include all read opcodes (including RFO: the Read for Ownership issued before a  write) .)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.WRITES",
      EventDef::Encoding{.code = 0x50, .umask = 0x0C, .msr_values = {0x00}},
      R"(Write requests)",
      R"(Counts write requests made into the CHA, including streaming, evictions, HitM (Reads from another core to a Modified cacheline), etc.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.READS_LOCAL",
      EventDef::Encoding{.code = 0x50, .umask = 0x01, .msr_values = {0x00}},
      R"(Read requests from a unit on this socket)",
      R"(Counts read requests coming from a unit on this socket made into this CHA. Reads include all read opcodes (including RFO: the Read for Ownership issued before a  write).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.READS_REMOTE",
      EventDef::Encoding{.code = 0x50, .umask = 0x02, .msr_values = {0x00}},
      R"(Read requests from a remote socket)",
      R"(Counts read requests coming from a remote socket made into the CHA. Reads include all read opcodes (including RFO: the Read for Ownership issued before a  write).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.WRITES_LOCAL",
      EventDef::Encoding{.code = 0x50, .umask = 0x04, .msr_values = {0x00}},
      R"(Write Requests from a unit on this socket)",
      R"(Counts  write requests coming from a unit on this socket made into this CHA, including streaming, evictions, HitM (Reads from another core to a Modified cacheline), etc.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.INVITOE_LOCAL",
      EventDef::Encoding{.code = 0x50, .umask = 0x10, .msr_values = {0x00}},
      R"(Local requests for exclusive ownership of a cache line  without receiving data)",
      R"(Counts the total number of requests coming from a unit on this socket for exclusive ownership of a cache line without receiving data (INVITOE) to the CHA.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_REQUESTS.INVITOE_REMOTE",
      EventDef::Encoding{.code = 0x50, .umask = 0x20, .msr_values = {0x00}},
      R"(Local requests for exclusive ownership of a cache line without receiving data)",
      R"(Counts the total number of requests coming from a remote socket for exclusive ownership of a cache line without receiving data (INVITOE) to the CHA.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_SNOOP_RESP.RSPI",
      EventDef::Encoding{.code = 0x5C, .umask = 0x01, .msr_values = {0x00}},
      R"(RspI Snoop Responses Received)",
      R"(Counts when a transaction with the opcode type RspI Snoop Response was received which indicates the remote cache does not have the data, or when the remote cache silently evicts data (such as when an RFO: the Read for Ownership issued before a write hits non-modified data).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_SNOOP_RESP.RSPIFWD",
      EventDef::Encoding{.code = 0x5C, .umask = 0x04, .msr_values = {0x00}},
      R"(RspIFwd Snoop Responses Received)",
      R"(Counts when a a transaction with the opcode type RspIFwd Snoop Response was received which indicates a remote caching agent forwarded the data and the requesting agent is able to acquire the data in E (Exclusive) or M (modified) states.  This is commonly returned with RFO (the Read for Ownership issued before a write) transactions.  The snoop could have either been to a cacheline in the M,E,F (Modified, Exclusive or Forward)  states.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_SNOOP_RESP.RSPSFWD",
      EventDef::Encoding{.code = 0x5C, .umask = 0x08, .msr_values = {0x00}},
      R"(RspSFwd Snoop Responses Received)",
      R"(Counts when a a transaction with the opcode type RspSFwd Snoop Response was received which indicates a remote caching agent forwarded the data but held on to its current copy.  This is common for data and code reads that hit in a remote socket in E (Exclusive) or F (Forward) state.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_SNOOP_RESP.RSP_WBWB",
      EventDef::Encoding{.code = 0x5C, .umask = 0x10, .msr_values = {0x00}},
      R"(Rsp*WB Snoop Responses Received)",
      R"(Counts when a transaction with the opcode type Rsp*WB Snoop Response was received which indicates which indicates the data was written back to its home.  This is returned when a non-RFO request hits a cacheline in the Modified state. The Cache can either downgrade the cacheline to a S (Shared) or I (Invalid) state depending on how the system has been configured.  This response will also be sent when a cache requests E (Exclusive) ownership of a cache line without receiving data, because the cache must acquire ownership.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_SNOOP_RESP.RSP_FWD_WB",
      EventDef::Encoding{.code = 0x5C, .umask = 0x20, .msr_values = {0x00}},
      R"(Rsp*Fwd*WB Snoop Responses Received)",
      R"(Counts when a transaction with the opcode type Rsp*Fwd*WB Snoop Response was received which indicates the data was written back to its home socket, and the cacheline was forwarded to the requestor socket.  This snoop response is only used in &gt;= 4 socket systems.  It is used when a snoop HITM's in a remote caching agent and it directly forwards data to a requestor, and simultaneously returns data to its home socket to be written back to memory.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_SNOOP_RESP.RSPCNFLCTS",
      EventDef::Encoding{.code = 0x5C, .umask = 0x40, .msr_values = {0x00}},
      R"(RspCnflct* Snoop Responses Received)",
      R"(Counts when a a transaction with the opcode type RspCnflct* Snoop Response was received. This is returned when a snoop finds an existing outstanding transaction in a remote caching agent. This triggers conflict resolution hardware. This covers both the opcode RspCnflct and RspCnflctWbI.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_SF_EVICTION.M_STATE",
      EventDef::Encoding{.code = 0x3D, .umask = 0x01, .msr_values = {0x00}},
      R"(Snoop filter capacity evictions for M-state entries.)",
      R"(Counts snoop filter capacity evictions for entries tracking modified lines in the cores cache. Snoop filter capacity evictions occur when the snoop filter is full and evicts an existing entry to track a new entry. Does not count clean evictions such as when a cores cache replaces a tracked cacheline with a new cacheline.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_SF_EVICTION.E_STATE",
      EventDef::Encoding{.code = 0x3D, .umask = 0x02, .msr_values = {0x00}},
      R"(Snoop filter capacity evictions for E-state entries.)",
      R"(Counts snoop filter capacity evictions for entries tracking exclusive lines in the cores cache. Snoop filter capacity evictions occur when the snoop filter is full and evicts an existing entry to track a new entry. Does not count clean evictions such as when a cores cache replaces a tracked cacheline with a new cacheline.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_SF_EVICTION.S_STATE",
      EventDef::Encoding{.code = 0x3D, .umask = 0x04, .msr_values = {0x00}},
      R"(Snoop filter capacity evictions for S-state entries.)",
      R"(Counts snoop filter capacity evictions for entries tracking shared lines in the cores cache. Snoop filter capacity evictions occur when the snoop filter is full and evicts an existing entry to track a new entry. Does not count clean evictions such as when a cores cache replaces a tracked cacheline with a new cacheline.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_RxC_INSERTS.IRQ",
      EventDef::Encoding{.code = 0x13, .umask = 0x01, .msr_values = {0x00}},
      R"(Ingress (from CMS) Allocations; IRQ)",
      R"(Counts number of allocations per cycle into the specified Ingress queue.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_RxC_IRQ1_REJECT.PA_MATCH",
      EventDef::Encoding{.code = 0x19, .umask = 0x80, .msr_values = {0x00}},
      R"(Ingress (from CMS) Request Queue Rejects; PhyAddr Match)",
      R"(Ingress (from CMS) Request Queue Rejects; PhyAddr Match)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_RxC_OCCUPANCY.IRQ",
      EventDef::Encoding{.code = 0x11, .umask = 0x01, .msr_values = {0x00}},
      R"(Ingress (from CMS) Occupancy; IRQ)",
      R"(Counts number of entries in the specified Ingress queue in each cycle.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_VICTIMS.TOTAL_M",
      EventDef::Encoding{.code = 0x37, .umask = 0x01, .msr_values = {0x00}},
      R"(Lines Victimized; Lines in M state)",
      R"(Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_VICTIMS.TOTAL_E",
      EventDef::Encoding{.code = 0x37, .umask = 0x02, .msr_values = {0x00}},
      R"(Lines Victimized; Lines in E state)",
      R"(Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_VICTIMS.TOTAL_S",
      EventDef::Encoding{.code = 0x37, .umask = 0x04, .msr_values = {0x00}},
      R"(Lines Victimized; Lines in S State)",
      R"(Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_LLC_VICTIMS.TOTAL_F",
      EventDef::Encoding{.code = 0x37, .umask = 0x08, .msr_values = {0x00}},
      R"(Lines Victimized; Lines in F State)",
      R"(Counts the number of lines that were victimized on a fill.  This can be filtered by the state that the line was in.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_DRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x11, .msr_values = {0x00}},
      R"(TOR Inserts : DRds issued by iA Cores that Hit the LLC)",
      R"(TOR Inserts : DRds issued by iA Cores that Hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_CRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x11, .msr_values = {0x00}},
      R"(TOR Inserts : CRds issued by iA Cores that Hit the LLC)",
      R"(TOR Inserts : CRds issued by iA Cores that Hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_RFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x11, .msr_values = {0x00}},
      R"(TOR Inserts : RFOs issued by iA Cores that Hit the LLC)",
      R"(TOR Inserts : RFOs issued by iA Cores that Hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_LlcPrefDRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x11, .msr_values = {0x00}},
      R"(UNC_CHA_TOR_INSERTS.IA_HIT_LlcPrefDRD)",
      R"(UNC_CHA_TOR_INSERTS.IA_HIT_LlcPrefDRD)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_LlcPrefCRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x11, .msr_values = {0x00}},
      R"(UNC_CHA_TOR_INSERTS.IA_HIT_LlcPrefCRD)",
      R"(UNC_CHA_TOR_INSERTS.IA_HIT_LlcPrefCRD)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_HIT_LlcPrefRFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x11, .msr_values = {0x00}},
      R"(TOR Inserts : LLCPrefRFO issued by iA Cores that hit the LLC)",
      R"(TOR Inserts : LLCPrefRFO issued by iA Cores that hit the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_DRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x21, .msr_values = {0x00}},
      R"(TOR Inserts : DRds issued by iA Cores that Missed the LLC)",
      R"(TOR Inserts : DRds issued by iA Cores that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_CRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x21, .msr_values = {0x00}},
      R"(TOR Inserts : CRds issued by iA Cores that Missed the LLC)",
      R"(TOR Inserts : CRds issued by iA Cores that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_RFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x21, .msr_values = {0x00}},
      R"(TOR Inserts : RFOs issued by iA Cores that Missed the LLC)",
      R"(TOR Inserts : RFOs issued by iA Cores that Missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_LlcPrefDRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x21, .msr_values = {0x00}},
      R"(UNC_CHA_TOR_INSERTS.IA_MISS_LlcPrefDRD)",
      R"(UNC_CHA_TOR_INSERTS.IA_MISS_LlcPrefDRD)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_LlcPrefCRD",
      EventDef::Encoding{.code = 0x35, .umask = 0x21, .msr_values = {0x00}},
      R"(UNC_CHA_TOR_INSERTS.IA_MISS_LlcPrefCRD)",
      R"(UNC_CHA_TOR_INSERTS.IA_MISS_LlcPrefCRD)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_INSERTS.IA_MISS_LlcPrefRFO",
      EventDef::Encoding{.code = 0x35, .umask = 0x21, .msr_values = {0x00}},
      R"(TOR Inserts : LLCPrefRFO issued by iA Cores that missed the LLC)",
      R"(TOR Inserts : LLCPrefRFO issued by iA Cores that missed the LLC : Counts the number of entries successfully inserted into the TOR that match qualifications specified by the subevent.   Does not include addressless requests such as locks and interrupts.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_DRD",
      EventDef::Encoding{.code = 0x36, .umask = 0x11, .msr_values = {0x00}},
      R"(UNC_CHA_TOR_OCCUPANCY.IA_HIT_DRD)",
      R"(UNC_CHA_TOR_OCCUPANCY.IA_HIT_DRD)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_CRD",
      EventDef::Encoding{.code = 0x36, .umask = 0x11, .msr_values = {0x00}},
      R"(UNC_CHA_TOR_OCCUPANCY.IA_HIT_CRD)",
      R"(UNC_CHA_TOR_OCCUPANCY.IA_HIT_CRD)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_RFO",
      EventDef::Encoding{.code = 0x36, .umask = 0x11, .msr_values = {0x00}},
      R"(UNC_CHA_TOR_OCCUPANCY.IA_HIT_RFO)",
      R"(UNC_CHA_TOR_OCCUPANCY.IA_HIT_RFO)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_LlcPrefDRD",
      EventDef::Encoding{.code = 0x36, .umask = 0x11, .msr_values = {0x00}},
      R"(UNC_CHA_TOR_OCCUPANCY.IA_HIT_LlcPrefDRD)",
      R"(UNC_CHA_TOR_OCCUPANCY.IA_HIT_LlcPrefDRD)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_LlcPrefCRD",
      EventDef::Encoding{.code = 0x36, .umask = 0x11, .msr_values = {0x00}},
      R"(UNC_CHA_TOR_OCCUPANCY.IA_HIT_LlcPrefCRD)",
      R"(UNC_CHA_TOR_OCCUPANCY.IA_HIT_LlcPrefCRD)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_HIT_LlcPrefRFO",
      EventDef::Encoding{.code = 0x36, .umask = 0x11, .msr_values = {0x00}},
      R"(UNC_CHA_TOR_OCCUPANCY.IA_HIT_LlcPrefRFO)",
      R"(UNC_CHA_TOR_OCCUPANCY.IA_HIT_LlcPrefRFO)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD",
      EventDef::Encoding{.code = 0x36, .umask = 0x21, .msr_values = {0x00}},
      R"(UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD)",
      R"(UNC_CHA_TOR_OCCUPANCY.IA_MISS_DRD)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_CRD",
      EventDef::Encoding{.code = 0x36, .umask = 0x21, .msr_values = {0x00}},
      R"(UNC_CHA_TOR_OCCUPANCY.IA_MISS_CRD)",
      R"(UNC_CHA_TOR_OCCUPANCY.IA_MISS_CRD)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO",
      EventDef::Encoding{.code = 0x36, .umask = 0x21, .msr_values = {0x00}},
      R"(UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO)",
      R"(UNC_CHA_TOR_OCCUPANCY.IA_MISS_RFO)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LlcPrefDRD",
      EventDef::Encoding{.code = 0x36, .umask = 0x21, .msr_values = {0x00}},
      R"(UNC_CHA_TOR_OCCUPANCY.IA_MISS_LlcPrefDRD)",
      R"(UNC_CHA_TOR_OCCUPANCY.IA_MISS_LlcPrefDRD)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LlcPrefCRD",
      EventDef::Encoding{.code = 0x36, .umask = 0x21, .msr_values = {0x00}},
      R"(UNC_CHA_TOR_OCCUPANCY.IA_MISS_LlcPrefCRD)",
      R"(UNC_CHA_TOR_OCCUPANCY.IA_MISS_LlcPrefCRD)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_cha,
      "UNC_CHA_TOR_OCCUPANCY.IA_MISS_LlcPrefRFO",
      EventDef::Encoding{.code = 0x36, .umask = 0x21, .msr_values = {0x00}},
      R"(UNC_CHA_TOR_OCCUPANCY.IA_MISS_LlcPrefRFO)",
      R"(UNC_CHA_TOR_OCCUPANCY.IA_MISS_LlcPrefRFO)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_CLOCKTICKS",
      EventDef::Encoding{.code = 0x1, .umask = 0x0, .msr_values = {0x00}},
      R"(Clockticks of the IIO Traffic Controller)",
      R"(Counts clockticks of the 1GHz trafiic controller clock in the IIO unit.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART0",
      EventDef::Encoding{.code = 0xC0, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of 4 bytes made to IIO Part0 by the CPU)",
      R"(Counts every write request of 4 bytes of data made to the MMIO space of a card on IIO Part0 by a unit on the main die (generally a core) or by another IIO unit. In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART1",
      EventDef::Encoding{.code = 0xC0, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of 4 bytes made to IIO Part1 by the CPU)",
      R"(Counts every write request of 4 bytes of data made to the MMIO space of a card on IIO Part1 by a unit on the main die (generally a core) or by another IIO unit. In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART2",
      EventDef::Encoding{.code = 0xC0, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of 4 bytes made to IIO Part2 by the CPU)",
      R"(Counts every write request of 4 bytes of data made to the MMIO space of a card on IIO Part2 by  a unit on the main die (generally a core) or by another IIO unit. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_WRITE.PART3",
      EventDef::Encoding{.code = 0xC0, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of 4 bytes made to IIO Part3 by the CPU)",
      R"(Counts every write request of 4 bytes of data made to the MMIO space of a card on IIO Part3 by  a unit on the main die (generally a core) or by another IIO unit. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.PEER_WRITE.PART0",
      EventDef::Encoding{.code = 0xC0, .umask = 0x02, .msr_values = {0x00}},
      R"(Peer to peer write request of 4 bytes made to IIO Part0 by a different IIO unit)",
      R"(Counts every peer to peer write request of 4 bytes of data made to the MMIO space of a card on IIO Part0 by a different IIO unit. Does not include requests made by the same IIO unit.  In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.PEER_WRITE.PART1",
      EventDef::Encoding{.code = 0xC0, .umask = 0x02, .msr_values = {0x00}},
      R"(Peer to peer write request of 4 bytes made to IIO Part1 by a different IIO unit)",
      R"(Counts every peer to peer write request of 4 bytes of data made to the MMIO space of a card on IIO Part1 by a different IIO unit. Does not include requests made by the same IIO unit. In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.PEER_WRITE.PART2",
      EventDef::Encoding{.code = 0xC0, .umask = 0x02, .msr_values = {0x00}},
      R"(Peer to peer write request of 4 bytes made to IIO Part2 by a different IIO unit)",
      R"(Counts every peer to peer write request of 4 bytes of data made to the MMIO space of a card on IIO Part2 by a different IIO unit. Does not include requests made by the same IIO unit. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.PEER_WRITE.PART3",
      EventDef::Encoding{.code = 0xC0, .umask = 0x02, .msr_values = {0x00}},
      R"(Peer to peer write request of 4 bytes made to IIO Part3 by a different IIO unit)",
      R"(Counts every peer to peer write request of 4 bytes of data made to the MMIO space of a card on IIO Part3 by a different IIO unit. Does not include requests made by the same IIO unit. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART0",
      EventDef::Encoding{.code = 0xC0, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for 4 bytes made by the CPU to IIO Part0)",
      R"(Counts every read request for 4 bytes of data made by a unit on the main die (generally a core) or by another IIO unit to the MMIO space of a card on IIO Part0. In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART1",
      EventDef::Encoding{.code = 0xC0, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for 4 bytes made by the CPU to IIO Part1)",
      R"(Counts every read request for 4 bytes of data made by a unit on the main die (generally a core) or by another IIO unit to the MMIO space of a card on IIO Part1. In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART2",
      EventDef::Encoding{.code = 0xC0, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for 4 bytes made by the CPU to IIO Part2)",
      R"(Counts every read request for 4 bytes of data made by a unit on the main die (generally a core) or by another IIO unit to the MMIO space of a card on IIO Part2. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.MEM_READ.PART3",
      EventDef::Encoding{.code = 0xC0, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for 4 bytes made by the CPU to IIO Part3)",
      R"(Counts every read request for 4 bytes of data made by a unit on the main die (generally a core) or by another IIO unit to the MMIO space of a card on IIO Part3. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.PEER_READ.PART0",
      EventDef::Encoding{.code = 0xC0, .umask = 0x08, .msr_values = {0x00}},
      R"(Peer to peer read request for 4 bytes made by a different IIO unit to IIO Part0)",
      R"(Counts ever peer to peer read request for 4 bytes of data made by a different IIO unit to the MMIO space of a card on IIO Part0. Does not include requests made by the same IIO unit. In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.PEER_READ.PART1",
      EventDef::Encoding{.code = 0xC0, .umask = 0x08, .msr_values = {0x00}},
      R"(Peer to peer read request for 4 bytes made by a different IIO unit to IIO Part1)",
      R"(Counts ever peer to peer read request for 4 bytes of data made by a different IIO unit to the MMIO space of a card on IIO Part1. Does not include requests made by the same IIO unit. In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.PEER_READ.PART2",
      EventDef::Encoding{.code = 0xC0, .umask = 0x08, .msr_values = {0x00}},
      R"(Peer to peer read request for 4 bytes made by a different IIO unit to IIO Part2)",
      R"(Counts ever peer to peer read request for 4 bytes of data made by a different IIO unit to the MMIO space of a card on IIO Part2. Does not include requests made by the same IIO unit. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_BY_CPU.PEER_READ.PART3",
      EventDef::Encoding{.code = 0xC0, .umask = 0x08, .msr_values = {0x00}},
      R"(Peer to peer read request for 4 bytes made by a different IIO unit to IIO Part3)",
      R"(Counts ever peer to peer read request for 4 bytes of data made by a different IIO unit to the MMIO space of a card on IIO Part3. Does not include requests made by the same IIO unit. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART0",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of 4 bytes made by IIO Part0 to Memory)",
      R"(Counts every write request of 4 bytes of data made by IIO Part0 to a unit on the main die (generally memory). In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART1",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of 4 bytes made by IIO Part1 to Memory)",
      R"(Counts every write request of 4 bytes of data made by IIO Part1 to a unit on the main die (generally memory). In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART2",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of 4 bytes made by IIO Part2 to Memory)",
      R"(Counts every write request of 4 bytes of data made by IIO Part2 to a unit on the main die (generally memory). In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_WRITE.PART3",
      EventDef::Encoding{.code = 0x83, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of 4 bytes made by IIO Part3 to Memory)",
      R"(Counts every write request of 4 bytes of data made by IIO Part3 to a unit on the main die (generally memory). In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART0",
      EventDef::Encoding{.code = 0x83, .umask = 0x02, .msr_values = {0x00}},
      R"(Peer to peer write request of 4 bytes made by IIO Part0 to an IIO target)",
      R"(Counts every peer to peer write request of 4 bytes of data made by IIO Part0 to the MMIO space of an IIO target. In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART1",
      EventDef::Encoding{.code = 0x83, .umask = 0x02, .msr_values = {0x00}},
      R"(Peer to peer write request of 4 bytes made by IIO Part0 to an IIO target)",
      R"(Counts every peer to peer write request of 4 bytes of data made by IIO Part1 to the MMIO space of an IIO target. In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART2",
      EventDef::Encoding{.code = 0x83, .umask = 0x02, .msr_values = {0x00}},
      R"(Peer to peer write request of 4 bytes made by IIO Part0 to an IIO target)",
      R"(Counts every peer to peer write request of 4 bytes of data made by IIO Part2 to the MMIO space of an IIO target. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_WRITE.PART3",
      EventDef::Encoding{.code = 0x83, .umask = 0x02, .msr_values = {0x00}},
      R"(Peer to peer write request of 4 bytes made by IIO Part0 to an IIO target)",
      R"(Counts every peer to peer write request of 4 bytes of data made by IIO Part3 to the MMIO space of an IIO target. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART0",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for 4 bytes made by IIO Part0 to Memory)",
      R"(Counts every read request for 4 bytes of data made by IIO Part0 to a unit on the main die (generally memory). In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART1",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for 4 bytes made by IIO Part1 to Memory)",
      R"(Counts every read request for 4 bytes of data made by IIO Part1 to a unit on the main die (generally memory). In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART2",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for 4 bytes made by IIO Part2 to Memory)",
      R"(Counts every read request for 4 bytes of data made by IIO Part2 to a unit on the main die (generally memory). In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.MEM_READ.PART3",
      EventDef::Encoding{.code = 0x83, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for 4 bytes made by IIO Part3 to Memory)",
      R"(Counts every read request for 4 bytes of data made by IIO Part3 to a unit on the main die (generally memory). In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART0",
      EventDef::Encoding{.code = 0x83, .umask = 0x08, .msr_values = {0x00}},
      R"(Peer to peer read request for 4 bytes made by IIO Part0 to an IIO target)",
      R"(Counts every peer to peer read request for 4 bytes of data made by IIO Part0 to the MMIO space of an IIO target. In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART1",
      EventDef::Encoding{.code = 0x83, .umask = 0x08, .msr_values = {0x00}},
      R"(Peer to peer read request for 4 bytes made by IIO Part1 to an IIO target)",
      R"(Counts every peer to peer read request for 4 bytes of data made by IIO Part1 to the MMIO space of an IIO target. In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART2",
      EventDef::Encoding{.code = 0x83, .umask = 0x08, .msr_values = {0x00}},
      R"(Peer to peer read request for 4 bytes made by IIO Part2 to an IIO target)",
      R"(Counts every peer to peer read request for 4 bytes of data made by IIO Part2 to the MMIO space of an IIO target. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_DATA_REQ_OF_CPU.PEER_READ.PART3",
      EventDef::Encoding{.code = 0x83, .umask = 0x08, .msr_values = {0x00}},
      R"(Peer to peer read request for 4 bytes made by IIO Part3 to an IIO target)",
      R"(Counts every peer to peer read request for 4 bytes of data made by IIO Part3 to the MMIO space of an IIO target. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART0",
      EventDef::Encoding{.code = 0xC1, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of up to a 64 byte transaction is made to IIO Part0 by the CPU)",
      R"(Counts every write request of up to a 64 byte transaction of data made to the MMIO space of a card on IIO Part0 by a unit on the main die (generally a core) or by another IIO unit. In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART1",
      EventDef::Encoding{.code = 0xC1, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of up to a 64 byte transaction is made to IIO Part1 by the CPU)",
      R"(Counts every write request of up to a 64 byte transaction of data made to the MMIO space of a card on IIO Part1 by a unit on the main die (generally a core) or by another IIO unit. In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART2",
      EventDef::Encoding{.code = 0xC1, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of up to a 64 byte transaction is made to IIO Part2 by the CPU)",
      R"(Counts every write request of up to a 64 byte transaction of data made to the MMIO space of a card on IIO Part2 by a unit on the main die (generally a core) or by another IIO unit. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_WRITE.PART3",
      EventDef::Encoding{.code = 0xC1, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of up to a 64 byte transaction is made to IIO Part3 by the CPU)",
      R"(Counts every write request of up to a 64 byte transaction of data made to the MMIO space of a card on IIO Part3 by a unit on the main die (generally a core) or by another IIO unit. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.PEER_WRITE.PART0",
      EventDef::Encoding{.code = 0xC1, .umask = 0x02, .msr_values = {0x00}},
      R"(Peer to peer write request of up to a 64 byte transaction is made to IIO Part0 by a different IIO unit)",
      R"(Counts every peer to peer write request of up to a 64 byte transaction of data made to the MMIO space of a card on IIO Part0 by a different IIO unit. Does not include requests made by the same IIO unit. In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.PEER_WRITE.PART1",
      EventDef::Encoding{.code = 0xC1, .umask = 0x02, .msr_values = {0x00}},
      R"(Peer to peer write request of up to a 64 byte transaction is made to IIO Part1 by a different IIO unit)",
      R"(Counts every peer to peer write request of up to a 64 byte transaction of data made to the MMIO space of a card on IIO Part1 by a different IIO unit. Does not include requests made by the same IIO unit. In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.PEER_WRITE.PART2",
      EventDef::Encoding{.code = 0xC1, .umask = 0x02, .msr_values = {0x00}},
      R"(Peer to peer write request of up to a 64 byte transaction is made to IIO Part2 by a different IIO unit)",
      R"(Counts every peer to peer write request of up to a 64 byte transaction of data made to the MMIO space of a card on IIO Part2 by a different IIO unit. Does not include requests made by the same IIO unit. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.PEER_WRITE.PART3",
      EventDef::Encoding{.code = 0xC1, .umask = 0x02, .msr_values = {0x00}},
      R"(Peer to peer write request of up to a 64 byte transaction is made to IIO Part3 by a different IIO unit)",
      R"(Counts every peer to peer write request of up to a 64 byte transaction of data made to the MMIO space of a card on IIO Part3 by a different IIO unit. Does not include requests made by the same IIO unit. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART0",
      EventDef::Encoding{.code = 0xC1, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for up to a 64 byte transaction is made by the CPU to IIO Part0)",
      R"(Counts every read request for up to a 64 byte transaction of data made by a unit on the main die (generally a core) or by another IIO unit to the MMIO space of a card on IIO Part0. In the general case, part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART1",
      EventDef::Encoding{.code = 0xC1, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for up to a 64 byte transaction is made by the CPU to IIO Part1)",
      R"(Counts every read request for up to a 64 byte transaction of data made by a unit on the main die (generally a core) or by another IIO unit to the MMIO space of a card on IIO Part1. In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART2",
      EventDef::Encoding{.code = 0xC1, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for up to a 64 byte transaction is made by the CPU to IIO Part2)",
      R"(Counts every read request for up to a 64 byte transaction of data made by a unit on the main die (generally a core) or by another IIO unit to the MMIO space of a card on IIO Part2. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.MEM_READ.PART3",
      EventDef::Encoding{.code = 0xC1, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for up to a 64 byte transaction is made by the CPU to IIO Part3)",
      R"(Counts every read request for up to a 64 byte transaction of data made by a unit on the main die (generally a core) or by another IIO unit to the MMIO space of a card on IIO Part3. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.PEER_READ.PART0",
      EventDef::Encoding{.code = 0xC1, .umask = 0x08, .msr_values = {0x00}},
      R"(Peer to peer read request for up to a 64 byte transaction is made by a different IIO unit to IIO Part0)",
      R"(Counts every peer to peer read request for up to a 64 byte transaction of data made by a different IIO unit to the MMIO space of a card on IIO Part0. Does not include requests made by the same IIO unit. In the general case, part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.PEER_READ.PART1",
      EventDef::Encoding{.code = 0xC1, .umask = 0x08, .msr_values = {0x00}},
      R"(Peer to peer read request for up to a 64 byte transaction is made by a different IIO unit to IIO Part1)",
      R"(Counts every peer to peer read request for up to a 64 byte transaction of data made by a different IIO unit to the MMIO space of a card on IIO Part1. Does not include requests made by the same IIO unit. In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.PEER_READ.PART2",
      EventDef::Encoding{.code = 0xC1, .umask = 0x08, .msr_values = {0x00}},
      R"(Peer to peer read request for up to a 64 byte transaction is made by a different IIO unit to IIO Part2)",
      R"(Counts every peer to peer read request for up to a 64 byte transaction of data made by a different IIO unit to the MMIO space of a card on IIO Part2. Does not include requests made by the same IIO unit. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_BY_CPU.PEER_READ.PART3",
      EventDef::Encoding{.code = 0xC1, .umask = 0x08, .msr_values = {0x00}},
      R"(Peer to peer read request for up to a 64 byte transaction is made by a different IIO unit to IIO Part3)",
      R"(Counts every peer to peer read request for up to a 64 byte transaction of data made by a different IIO unit to the MMIO space of a card on IIO Part3. Does not include requests made by the same IIO unit. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART0",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of up to a 64 byte transaction is made by IIO Part0 to Memory)",
      R"(Counts every write request of up to a 64 byte transaction of data made by IIO Part0 to a unit on the main die (generally memory). In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART1",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of up to a 64 byte transaction is made by IIO Part1 to Memory)",
      R"(Counts every write request of up to a 64 byte transaction of data made by IIO Part1 to a unit on the main die (generally memory). In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART2",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of up to a 64 byte transaction is made by IIO Part2 to Memory)",
      R"(Counts every write request of up to a 64 byte transaction of data made by IIO Part2 to a unit on the main die (generally memory). In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_WRITE.PART3",
      EventDef::Encoding{.code = 0x84, .umask = 0x01, .msr_values = {0x00}},
      R"(Write request of up to a 64 byte transaction is made by IIO Part3 to Memory)",
      R"(Counts every write request of up to a 64 byte transaction of data made by IIO Part3 to a unit on the main die (generally memory). In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART0",
      EventDef::Encoding{.code = 0x84, .umask = 0x02, .msr_values = {0x00}},
      R"(Peer to peer write request of up to a 64 byte transaction is made by IIO Part0 to an IIO target)",
      R"(Counts every peer to peer write request of up to a 64 byte transaction of data made by IIO Part0 to the MMIO space of an IIO target. In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART1",
      EventDef::Encoding{.code = 0x84, .umask = 0x02, .msr_values = {0x00}},
      R"(Peer to peer write request of up to a 64 byte transaction is made by IIO Part1 to an IIO target)",
      R"(Counts every peer to peer write request of up to a 64 byte transaction of data made by IIO Part1 to the MMIO space of an IIO target.In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART2",
      EventDef::Encoding{.code = 0x84, .umask = 0x02, .msr_values = {0x00}},
      R"(Peer to peer write request of up to a 64 byte transaction is made by IIO Part2 to an IIO target)",
      R"(Counts every peer to peer write request of up to a 64 byte transaction of data made by IIO Part2 to the MMIO space of an IIO target. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_WRITE.PART3",
      EventDef::Encoding{.code = 0x84, .umask = 0x02, .msr_values = {0x00}},
      R"(Peer to peer write request of up to a 64 byte transaction is made by IIO Part3 to an IIO target)",
      R"(Counts every peer to peer write request of up to a 64 byte transaction of data made by IIO Part3 to the MMIO space of an IIO target. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART0",
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for up to a 64 byte transaction is made by IIO Part0 to Memory)",
      R"(Counts every read request for up to a 64 byte transaction of data made by IIO Part0 to a unit on the main die (generally memory). In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART1",
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for up to a 64 byte transaction is  made by IIO Part1 to Memory)",
      R"(Counts every read request for up to a 64 byte transaction of data made by IIO Part1 to a unit on the main die (generally memory). In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART2",
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for up to a 64 byte transaction is made by IIO Part2 to Memory)",
      R"(Counts every read request for up to a 64 byte transaction of data made by IIO Part2 to a unit on the main die (generally memory). In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.MEM_READ.PART3",
      EventDef::Encoding{.code = 0x84, .umask = 0x04, .msr_values = {0x00}},
      R"(Read request for up to a 64 byte transaction is made by IIO Part3 to Memory)",
      R"(Counts every read request for up to a 64 byte transaction of data made by IIO Part3 to a unit on the main die (generally memory). In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to  any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART0",
      EventDef::Encoding{.code = 0x84, .umask = 0x08, .msr_values = {0x00}},
      R"(Peer to peer read request of up to a 64 byte transaction is made by IIO Part0 to an IIO target)",
      R"(Counts every peer to peer read request of up to a 64 byte transaction made by IIO Part0 to the MMIO space of an IIO target. In the general case, Part0 refers to a standard PCIe card of any size (x16,x8,x4) that is plugged directly into one of the PCIe slots. Part0 could also refer to any device plugged into the first slot of a PCIe riser card or to a device attached to the IIO unit which starts its use of the bus using lane 0 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART1",
      EventDef::Encoding{.code = 0x84, .umask = 0x08, .msr_values = {0x00}},
      R"(Peer to peer read request of up to a 64 byte transaction is made by IIO Part1 to an IIO target)",
      R"(Counts every peer to peer read request of up to a 64 byte transaction made by IIO Part1 to the MMIO space of an IIO target. In the general case, Part1 refers to a x4 PCIe card plugged into the second slot of a PCIe riser card, but it could refer to any x4 device attached to the IIO unit using lanes starting at lane 4 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART2",
      EventDef::Encoding{.code = 0x84, .umask = 0x08, .msr_values = {0x00}},
      R"(Peer to peer read request of up to a 64 byte transaction is made by IIO Part2 to an IIO target)",
      R"(Counts every peer to peer read request of up to a 64 byte transaction made by IIO Part2 to the MMIO space of an IIO target. In the general case, Part2 refers to a x4 or x8 PCIe card plugged into the third slot of a PCIe riser card, but it could refer to any x4 or x8 device attached to the IIO unit and using lanes starting at lane 8 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_TXN_REQ_OF_CPU.PEER_READ.PART3",
      EventDef::Encoding{.code = 0x84, .umask = 0x08, .msr_values = {0x00}},
      R"(Peer to peer read request of up to a 64 byte transaction is made by IIO Part3 to an IIO target)",
      R"(Counts every peer to peer read request of up to a 64 byte transaction made by IIO Part3 to the MMIO space of an IIO target. In the general case, Part3 refers to a x4 PCIe card plugged into the fourth slot of a PCIe riser card, but it could brefer to any device attached to the IIO unit using the lanes starting at lane 12 of the 16 lanes supported by the bus.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART0",
      EventDef::Encoding{.code = 0xC2, .umask = 0x03, .msr_values = {0x00}},
      R"(PCIe Completion Buffer Inserts of completions with data: Part 0)",
      R"(PCIe Completion Buffer Inserts of completions with data: Part 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART1",
      EventDef::Encoding{.code = 0xC2, .umask = 0x03, .msr_values = {0x00}},
      R"(PCIe Completion Buffer Inserts of completions with data: Part 1)",
      R"(PCIe Completion Buffer Inserts of completions with data: Part 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART2",
      EventDef::Encoding{.code = 0xC2, .umask = 0x03, .msr_values = {0x00}},
      R"(PCIe Completion Buffer Inserts of completions with data: Part 2)",
      R"(PCIe Completion Buffer Inserts of completions with data: Part 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_INSERTS.CMPD.PART3",
      EventDef::Encoding{.code = 0xC2, .umask = 0x03, .msr_values = {0x00}},
      R"(PCIe Completion Buffer Inserts of completions with data: Part 3)",
      R"(PCIe Completion Buffer Inserts of completions with data: Part 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART0",
      EventDef::Encoding{.code = 0xD5, .umask = 0x01, .msr_values = {0x00}},
      R"(PCIe Completion Buffer occupancy of completions with data: Part 0)",
      R"(PCIe Completion Buffer occupancy of completions with data: Part 0)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART1",
      EventDef::Encoding{.code = 0xD5, .umask = 0x02, .msr_values = {0x00}},
      R"(PCIe Completion Buffer occupancy of completions with data: Part 1)",
      R"(PCIe Completion Buffer occupancy of completions with data: Part 1)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART2",
      EventDef::Encoding{.code = 0xD5, .umask = 0x04, .msr_values = {0x00}},
      R"(PCIe Completion Buffer occupancy of completions with data: Part 2)",
      R"(PCIe Completion Buffer occupancy of completions with data: Part 2)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.PART3",
      EventDef::Encoding{.code = 0xD5, .umask = 0x08, .msr_values = {0x00}},
      R"(PCIe Completion Buffer occupancy of completions with data: Part 3)",
      R"(PCIe Completion Buffer occupancy of completions with data: Part 3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_INSERTS.CMPD.ALL_PARTS",
      EventDef::Encoding{.code = 0xC2, .umask = 0x03, .msr_values = {0x00}},
      R"(PCIe Completion Buffer Inserts of completions with data: Part 0-3)",
      R"(PCIe Completion Buffer Inserts of completions with data: Part 0-3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_iio,
      "UNC_IIO_COMP_BUF_OCCUPANCY.CMPD.ALL_PARTS",
      EventDef::Encoding{.code = 0xD5, .umask = 0x0f, .msr_values = {0x00}},
      R"(PCIe Completion Buffer occupancy of completions with data: Part 0-3)",
      R"(PCIe Completion Buffer occupancy of completions with data: Part 0-3)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_CACHE_TOTAL_OCCUPANCY.MEM",
      EventDef::Encoding{.code = 0xF, .umask = 0x4, .msr_values = {0x00}},
      R"(Total IRP occupancy of inbound read and write requests.)",
      R"(Total IRP occupancy of inbound read and write requests.  This is effectively the sum of read occupancy and write occupancy.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_COHERENT_OPS.RFO",
      EventDef::Encoding{.code = 0x10, .umask = 0x8, .msr_values = {0x00}},
      R"(RFO request issued by the IRP unit to the mesh with the intention of writing a partial cacheline.)",
      R"(RFO request issued by the IRP unit to the mesh with the intention of writing a partial cacheline to coherent memory.  RFO is a Read For Ownership command that requests ownership of the cacheline and moves data from the mesh to IRP cache.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_COHERENT_OPS.PCITOM",
      EventDef::Encoding{.code = 0x10, .umask = 0x10, .msr_values = {0x00}},
      R"(PCIITOM request issued by the IRP unit to the mesh with the intention of writing a full cacheline.)",
      R"(PCIITOM request issued by the IRP unit to the mesh with the intention of writing a full cacheline to coherent memory, without a RFO.  PCIITOM is a speculative Invalidate to Modified command that requests ownership of the cacheline and does not move data from the mesh to IRP cache.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_FAF_INSERTS",
      EventDef::Encoding{.code = 0x18, .umask = 0x0, .msr_values = {0x00}},
      R"(Inbound read requests received by the IRP and inserted into the FAF queue.)",
      R"(Inbound read requests to coherent memory, received by the IRP and inserted into the Fire and Forget queue (FAF), a queue used for processing inbound reads in the IRP.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_FAF_OCCUPANCY",
      EventDef::Encoding{.code = 0x19, .umask = 0x0, .msr_values = {0x00}},
      R"(Occupancy of the IRP FAF queue.)",
      R"(Occupancy of the IRP Fire and Forget (FAF) queue, a queue used for processing inbound reads in the IRP.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_irp,
      "UNC_I_TRANSACTIONS.WR_PREF",
      EventDef::Encoding{.code = 0x11, .umask = 0x8, .msr_values = {0x00}},
      R"(Inbound write (fast path) requests received by the IRP.)",
      R"(Inbound write (fast path) requests to coherent memory, received by the IRP resulting in write ownership requests issued by IRP to the mesh.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_CLOCKTICKS",
      EventDef::Encoding{.code = 0x1, .umask = 0x0, .msr_values = {0x00}},
      R"(Clocks of the Intel Ultra Path Interconnect (UPI))",
      R"(Counts clockticks of the fixed frequency clock controlling the Intel Ultra Path Interconnect (UPI).  This clock runs at1/8th the 'GT/s' speed of the UPI link.  For example, a  9.6GT/s  link will have a fixed Frequency of 1.2 Ghz.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_DIRECT_ATTEMPTS.D2C",
      EventDef::Encoding{.code = 0x12, .umask = 0x1, .msr_values = {0x00}},
      R"(Data Response packets that go direct to core)",
      R"(Counts Data Response (DRS) packets that attempted to go direct to core bypassing the CHA.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_L1_POWER_CYCLES",
      EventDef::Encoding{.code = 0x21, .umask = 0x0, .msr_values = {0x00}},
      R"(Cycles Intel UPI is in L1 power mode (shutdown))",
      R"(Counts cycles when the Intel Ultra Path Interconnect (UPI) is in L1 power mode.  L1 is a mode that totally shuts down the UPI link.  Link power states are per link and per direction, so for example the Tx direction could be in one state while Rx was in another, this event only coutns when both links are shutdown.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL0P_POWER_CYCLES",
      EventDef::Encoding{.code = 0x25, .umask = 0x0, .msr_values = {0x00}},
      R"(Cycles the Rx of the Intel UPI is in L0p power mode)",
      R"(Counts cycles when the the receive side (Rx) of the Intel Ultra Path Interconnect(UPI) is in L0p power mode. L0p is a mode where we disable 60% of the UPI lanes, decreasing our bandwidth in order to save power.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BYPASSED.SLOT0",
      EventDef::Encoding{.code = 0x31, .umask = 0x1, .msr_values = {0x00}},
      R"(FLITs received which bypassed the Slot0 Receive Buffer)",
      R"(Counts incoming FLITs (FLow control unITs) which bypassed the slot0 RxQ buffer (Receive Queue) and passed directly to the Egress.  This is a latency optimization, and should generally be the common case.  If this value is less than the number of FLITs transferred, it implies that there was queueing getting onto the ring, and thus the transactions saw higher latency.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BYPASSED.SLOT1",
      EventDef::Encoding{.code = 0x31, .umask = 0x2, .msr_values = {0x00}},
      R"(FLITs received which bypassed the Slot0 Receive Buffer)",
      R"(Counts incoming FLITs (FLow control unITs) which bypassed the slot1 RxQ buffer  (Receive Queue) and passed directly across the BGF and into the Egress.  This is a latency optimization, and should generally be the common case.  If this value is less than the number of FLITs transferred, it implies that there was queueing getting onto the ring, and thus the transactions saw higher latency.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_BYPASSED.SLOT2",
      EventDef::Encoding{.code = 0x31, .umask = 0x4, .msr_values = {0x00}},
      R"(FLITs received which bypassed the Slot0 Receive Buffer)",
      R"(Counts incoming FLITs (FLow control unITs) which bypassed the slot2 RxQ buffer (Receive Queue)  and passed directly to the Egress.  This is a latency optimization, and should generally be the common case.  If this value is less than the number of FLITs transferred, it implies that there was queueing getting onto the ring, and thus the transactions saw higher latency.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL0P_POWER_CYCLES",
      EventDef::Encoding{.code = 0x27, .umask = 0x0, .msr_values = {0x00}},
      R"(Cycles in which the Tx of the Intel Ultra Path Interconnect (UPI) is in L0p power mode)",
      R"(Counts cycles when the transmit side (Tx) of the Intel Ultra Path Interconnect(UPI) is in L0p power mode. L0p is a mode where we disable 60% of the UPI lanes, decreasing our bandwidth in order to save power.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_BYPASSED",
      EventDef::Encoding{.code = 0x41, .umask = 0x0, .msr_values = {0x00}},
      R"(FLITs that bypassed the TxL Buffer)",
      R"(Counts incoming FLITs (FLow control unITs) which bypassed the TxL(transmit) FLIT buffer and pass directly out the UPI Link. Generally, when data is transmitted across the Intel Ultra Path Interconnect (UPI), it will bypass the TxQ and pass directly to the link.  However, the TxQ will be used in L0p (Low Power) mode and (Link Layer Retry) LLR  mode, increasing latency to transfer out to the link.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.DATA",
      EventDef::Encoding{.code = 0x2, .umask = 0x8, .msr_values = {0x00}},
      R"(Valid Flits Sent; Data)",
      R"(Shows legal flit time (hides impact of L0p and L0c).; Count Data Flits (which consume all slots), but how much to count is based on Slot0-2 mask, so count can be 0-3 depending on which slots are enabled for counting..)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.NON_DATA",
      EventDef::Encoding{.code = 0x3, .umask = 0x97, .msr_values = {0x00}},
      R"(Protocol header and credit FLITs received from any slot)",
      R"(Counts protocol header and credit FLITs  (80 bit FLow control unITs) received from any of the 3 UPI slots on this UPI unit.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.NON_DATA",
      EventDef::Encoding{.code = 0x2, .umask = 0x97, .msr_values = {0x00}},
      R"(Protocol header and credit FLITs transmitted across any slot)",
      R"(Counts protocol header and credit FLITs (80 bit FLow control unITs) transmitted across any of the 3 UPI (Ultra Path Interconnect) slots on this UPI unit.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.IDLE",
      EventDef::Encoding{.code = 0x2, .umask = 0x47, .msr_values = {0x00}},
      R"(Idle FLITs transmitted)",
      R"(Counts when the Intel Ultra Path Interconnect(UPI) transmits an idle FLIT(80 bit FLow control unITs).  Every UPI cycle must be sending either data FLITs, protocol/credit FLITs or idle FLITs.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.ALL_NULL",
      EventDef::Encoding{.code = 0x2, .umask = 0x27, .msr_values = {0x00}},
      R"(Null FLITs transmitted from any slot)",
      R"(Counts null FLITs (80 bit FLow control unITs) transmitted via any of the 3 Intel Ulra Path Interconnect (UPI) slots on this UPI unit.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.ALL_NULL",
      EventDef::Encoding{.code = 0x3, .umask = 0x27, .msr_values = {0x00}},
      R"(Null FLITs received from any slot)",
      R"(Counts null FLITs (80 bit FLow control unITs) received from any of the 3 Intel Ultra Path Interconnect (UPI) Receive Queue slots on this UPI unit.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_RxL_FLITS.ALL_DATA",
      EventDef::Encoding{.code = 0x3, .umask = 0x0F, .msr_values = {0x00}},
      R"(Valid data FLITs received from any slot)",
      R"(Counts valid data FLITs  (80 bit FLow control unITs: 64bits of data) received from any of the 3 Intel Ultra Path Interconnect (UPI) Receive Queue slots on this UPI unit.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_TxL_FLITS.ALL_DATA",
      EventDef::Encoding{.code = 0x2, .umask = 0x0F, .msr_values = {0x00}},
      R"(Valid data FLITs transmitted via any slot)",
      R"(Counts valid data FLITs (80 bit FLow control unITs: 64bits of data) transmitted (TxL) via any of the 3 Intel Ultra Path Interconnect (UPI) slots on this UPI unit.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_upi,
      "UNC_UPI_DIRECT_ATTEMPTS.D2U",
      EventDef::Encoding{.code = 0x12, .umask = 0x2, .msr_values = {0x00}},
      R"(Data Response packets that go direct to Intel UPI)",
      R"(Counts Data Response (DRS) packets that attempted to go direct to Intel Ultra Path Interconnect (UPI) bypassing the CHA .)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_BYPASS_M2M_Egress.NOT_TAKEN",
      EventDef::Encoding{.code = 0x22, .umask = 0x2, .msr_values = {0x00}},
      R"(Traffic in which the M2M to iMC Bypass was not taken)",
      R"(Counts traffic in which the M2M (Mesh to Memory) to iMC (Memory Controller) bypass was not taken)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECT2CORE_NOT_TAKEN_DIRSTATE",
      EventDef::Encoding{.code = 0x24, .umask = 0x0, .msr_values = {0x00}},
      R"(Cycles when direct to core mode (which bypasses the CHA) was disabled)",
      R"(Counts cycles when direct to core mode (which bypasses the CHA) was disabled)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECT2CORE_TAKEN",
      EventDef::Encoding{.code = 0x23, .umask = 0x0, .msr_values = {0x00}},
      R"(Messages sent direct to core (bypassing the CHA))",
      R"(Counts when messages were sent direct to core (bypassing the CHA))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECT2CORE_TXN_OVERRIDE",
      EventDef::Encoding{.code = 0x25, .umask = 0x0, .msr_values = {0x00}},
      R"(Number of reads in which direct to core transaction were overridden)",
      R"(Counts reads in which direct to core transactions (which would have bypassed the CHA) were overridden)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_LOOKUP.ANY",
      EventDef::Encoding{.code = 0x2D, .umask = 0x1, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory lookups (any state found))",
      R"(Counts when the M2M (Mesh to Memory) looks into the multi-socket cacheline Directory state, and found the cacheline marked in Any State (A, I, S or unused))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_LOOKUP.STATE_I",
      EventDef::Encoding{.code = 0x2D, .umask = 0x2, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory lookup (cacheline found in I state))",
      R"(Counts when the M2M (Mesh to Memory) looks into the multi-socket cacheline Directory state , and found the cacheline marked in the I (Invalid) state indicating the cacheline is not stored in another socket, and so there is no need to snoop the other sockets for the latest data.  The data may be stored in any state in the local socket.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_LOOKUP.STATE_S",
      EventDef::Encoding{.code = 0x2D, .umask = 0x4, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory lookup (cacheline found in S state))",
      R"(Counts when the M2M (Mesh to Memory) looks into the multi-socket cacheline Directory state , and found the cacheline marked in the S (Shared) state indicating the cacheline is either stored in another socket in the S(hared) state , and so there is no need to snoop the other sockets for the latest data.  The data may be stored in any state in the local socket.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_LOOKUP.STATE_A",
      EventDef::Encoding{.code = 0x2D, .umask = 0x8, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory lookups (cacheline found in A state))",
      R"(Counts when the M2M (Mesh to Memory) looks into the multi-socket cacheline Directory state, and found the cacheline marked in the A (SnoopAll) state, indicating the cacheline is stored in another socket in any state, and we must snoop the other sockets to make sure we get the latest data.  The data may be stored in any state in the local socket.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_UPDATE.ANY",
      EventDef::Encoding{.code = 0x2E, .umask = 0x1, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory update from/to Any state)",
      R"(Counts when the M2M (Mesh to Memory) updates the multi-socket cacheline Directory to a new state)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_UPDATE.I2S",
      EventDef::Encoding{.code = 0x2E, .umask = 0x2, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory update from I to S)",
      R"(Counts when the M2M (Mesh to Memory) updates the multi-socket cacheline Directory state from from I (Invalid) to S (Shared))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_UPDATE.I2A",
      EventDef::Encoding{.code = 0x2E, .umask = 0x4, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory update from I to A)",
      R"(Counts when the M2M (Mesh to Memory) updates the multi-socket cacheline Directory state from from I (Invalid) to A (SnoopAll))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_UPDATE.S2I",
      EventDef::Encoding{.code = 0x2E, .umask = 0x8, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory update from S to I)",
      R"(Counts when the M2M (Mesh to Memory) updates the multi-socket cacheline Directory state from from S (Shared) to I (Invalid))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_UPDATE.S2A",
      EventDef::Encoding{.code = 0x2E, .umask = 0x10, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory update from S to A)",
      R"(Counts when the M2M (Mesh to Memory) updates the multi-socket cacheline Directory state from from S (Shared) to A (SnoopAll))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_UPDATE.A2I",
      EventDef::Encoding{.code = 0x2E, .umask = 0x20, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory update from A to I)",
      R"(Counts when the M2M (Mesh to Memory) updates the multi-socket cacheline Directory state from from A (SnoopAll) to I (Invalid))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECTORY_UPDATE.A2S",
      EventDef::Encoding{.code = 0x2E, .umask = 0x40, .msr_values = {0x00}},
      R"(Multi-socket cacheline Directory update from A to S)",
      R"(Counts when the M2M (Mesh to Memory) updates the multi-socket cacheline Directory state from from A (SnoopAll) to S (Shared))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_IMC_READS.NORMAL",
      EventDef::Encoding{.code = 0x37, .umask = 0x1, .msr_values = {0x00}},
      R"(Reads to iMC issued at Normal Priority (Non-Isochronous))",
      R"(Counts when the M2M (Mesh to Memory) issues reads to the iMC (Memory Controller).  It only counts  normal priority non-isochronous reads.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_IMC_READS.ALL",
      EventDef::Encoding{.code = 0x37, .umask = 0x4, .msr_values = {0x00}},
      R"(Reads to iMC issued)",
      R"(Counts when the M2M (Mesh to Memory) issues reads to the iMC (Memory Controller).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_IMC_WRITES.PARTIAL",
      EventDef::Encoding{.code = 0x38, .umask = 0x2, .msr_values = {0x00}},
      R"(Partial Non-Isochronous writes to the iMC)",
      R"(Counts when the M2M (Mesh to Memory) issues partial writes to the iMC (Memory Controller).  It only counts normal priority non-isochronous writes.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_IMC_WRITES.ALL",
      EventDef::Encoding{.code = 0x38, .umask = 0x10, .msr_values = {0x00}},
      R"(Writes to iMC issued)",
      R"(Counts when the M2M (Mesh to Memory) issues writes to the iMC (Memory Controller).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_IMC_WRITES.NI",
      EventDef::Encoding{.code = 0x38, .umask = 0x80, .msr_values = {0x00}},
      R"(M2M Writes Issued to iMC; All, regardless of priority.)",
      R"(M2M Writes Issued to iMC; All, regardless of priority.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_PREFCAM_DEMAND_PROMOTIONS",
      EventDef::Encoding{.code = 0x56, .umask = 0x0, .msr_values = {0x00}},
      R"(Prefetch requests that got turn into a demand request)",
      R"(Counts when the M2M (Mesh to Memory) promotes a outstanding request in the prefetch queue due to a subsequent demand read request that entered the M2M with the same address.  Explanatory Side Note: The Prefetch queue is made of CAM (Content Addressable Memory))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_PREFCAM_INSERTS",
      EventDef::Encoding{.code = 0x57, .umask = 0x0, .msr_values = {0x00}},
      R"(Inserts into the Memory Controller Prefetch Queue)",
      R"(Counts when the M2M (Mesh to Memory) receives a prefetch request and inserts it into its outstanding prefetch queue.  Explanatory Side Note: the prefect queue is made from CAM: Content Addressable Memory)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_RxC_AD_INSERTS",
      EventDef::Encoding{.code = 0x1, .umask = 0x00, .msr_values = {0x00}},
      R"(AD Ingress (from CMS) Queue Inserts)",
      R"(Counts when the a new entry is Received(RxC) and then added to the AD (Address Ring) Ingress Queue from the CMS (Common Mesh Stop).  This is generally used for reads, and)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_RxC_AD_OCCUPANCY",
      EventDef::Encoding{.code = 0x2, .umask = 0x00, .msr_values = {0x00}},
      R"(AD Ingress (from CMS) Occupancy)",
      R"(AD Ingress (from CMS) Occupancy)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_RxC_BL_INSERTS",
      EventDef::Encoding{.code = 0x5, .umask = 0x00, .msr_values = {0x00}},
      R"(BL Ingress (from CMS) Allocations)",
      R"(BL Ingress (from CMS) Allocations)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_RxC_BL_OCCUPANCY",
      EventDef::Encoding{.code = 0x6, .umask = 0x00, .msr_values = {0x00}},
      R"(BL Ingress (from CMS) Occupancy)",
      R"(BL Ingress (from CMS) Occupancy)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_TxC_AD_INSERTS",
      EventDef::Encoding{.code = 0x9, .umask = 0x00, .msr_values = {0x00}},
      R"(AD Egress (to CMS) Allocations)",
      R"(AD Egress (to CMS) Allocations)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_TxC_AD_OCCUPANCY",
      EventDef::Encoding{.code = 0xA, .umask = 0x00, .msr_values = {0x00}},
      R"(AD Egress (to CMS) Occupancy)",
      R"(AD Egress (to CMS) Occupancy)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_TxC_BL_INSERTS.ALL",
      EventDef::Encoding{.code = 0x15, .umask = 0x03, .msr_values = {0x00}},
      R"(BL Egress (to CMS) Allocations; All)",
      R"(BL Egress (to CMS) Allocations; All)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_TxC_BL_OCCUPANCY.ALL",
      EventDef::Encoding{.code = 0x16, .umask = 0x03, .msr_values = {0x00}},
      R"(BL Egress (to CMS) Occupancy; All)",
      R"(BL Egress (to CMS) Occupancy; All)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECT2UPI_NOT_TAKEN_CREDITS",
      EventDef::Encoding{.code = 0x28, .umask = 0x00, .msr_values = {0x00}},
      R"(Number of reads in which direct to Intel UPI transactions were overridden)",
      R"(Counts reads in which direct to Intel Ultra Path Interconnect (UPI) transactions (which would have bypassed the CHA) were overridden)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECT2UPI_NOT_TAKEN_DIRSTATE",
      EventDef::Encoding{.code = 0x27, .umask = 0x00, .msr_values = {0x00}},
      R"(Cycles when direct to Intel UPI was disabled)",
      R"(Counts cycles when the ability to send messages direct to the Intel Ultra Path Interconnect (bypassing the CHA) was disabled)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECT2UPI_TAKEN",
      EventDef::Encoding{.code = 0x26, .umask = 0x00, .msr_values = {0x00}},
      R"(Messages sent direct to the Intel UPI)",
      R"(Counts when messages were sent direct to the Intel Ultra Path Interconnect (bypassing the CHA))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m2m,
      "UNC_M2M_DIRECT2UPI_TXN_OVERRIDE",
      EventDef::Encoding{.code = 0x29, .umask = 0x00, .msr_values = {0x00}},
      R"(Number of reads that a message sent direct2 Intel UPI was overridden)",
      R"(Counts when a read message that was sent direct to the Intel Ultra Path Interconnect (bypassing the CHA) was overridden)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_m3upi,
      "UNC_M3UPI_UPI_PREFETCH_SPAWN",
      EventDef::Encoding{.code = 0x29, .umask = 0x0, .msr_values = {0x00}},
      R"(Prefetches generated by the flow control queue of the M3UPI unit.)",
      R"(Count cases where flow control queue that sits between the Intel Ultra Path Interconnect (UPI) and the mesh spawns a prefetch to the iMC (Memory Controller))",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_ACT_COUNT.WR",
      EventDef::Encoding{.code = 0x1, .umask = 0x2, .msr_values = {0x00}},
      R"(DRAM Page Activate commands sent due to a write request)",
      R"(Counts DRAM Page Activate commands sent on this channel due to a write request to the iMC (Memory Controller).  Activate commands are issued to open up a page on the DRAM devices so that it can be read or written to with a CAS (Column Access Select) command.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.RD_REG",
      EventDef::Encoding{.code = 0x4, .umask = 0x1, .msr_values = {0x00}},
      R"(All DRAM Read CAS Commands issued (does not include underfills))",
      R"(Counts CAS (Column Access Select) regular read commands issued to DRAM on a per channel basis.  CAS commands are issued to specify the address to read or write on DRAM, and this event increments for every regular read.  This event only counts regular reads and does not includes underfill reads due to partial write requests.  This event counts whether AutoPrecharge (which closes the DRAM Page automatically after a read/write)  is enabled or not.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.RD_UNDERFILL",
      EventDef::Encoding{.code = 0x4, .umask = 0x2, .msr_values = {0x00}},
      R"(DRAM Underfill Read CAS Commands issued)",
      R"(Counts CAS (Column Access Select) underfill read commands issued to DRAM due to a partial write, on a per channel basis.  CAS commands are issued to specify the address to read or write on DRAM, and this command counts underfill reads.  Partial writes must be completed by first reading in the underfill from DRAM and then merging in the partial write data before writing the full line back to DRAM. This event will generally count about the same as the number of partial writes, but may be slightly less because of partials hitting in the WPQ (due to a previous write request).)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.RD",
      EventDef::Encoding{.code = 0x4, .umask = 0x3, .msr_values = {0x00}},
      R"(All DRAM Read CAS Commands issued (including underfills))",
      R"(Counts all CAS (Column Access Select) read commands issued to DRAM on a per channel basis.  CAS commands are issued to specify the address to read or write on DRAM, and this event increments for every read.  This event includes underfill reads due to partial write requests.  This event counts whether AutoPrecharge (which closes the DRAM Page automatically after a read/write)  is enabled or not.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.WR_WMM",
      EventDef::Encoding{.code = 0x4, .umask = 0x4, .msr_values = {0x00}},
      R"(DRAM CAS (Column Address Strobe) Commands.; DRAM WR_CAS (w/ and w/out auto-pre) in Write Major Mode)",
      R"(Counts the total number or DRAM Write CAS commands issued on this channel while in Write-Major-Mode.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.WR",
      EventDef::Encoding{.code = 0x4, .umask = 0xC, .msr_values = {0x00}},
      R"(All DRAM Write CAS commands issued)",
      R"(Counts all CAS (Column Address Select) commands issued to DRAM per memory channel.  CAS commands are issued to specify the address to read or write on DRAM, and this event increments for every write. This event counts whether AutoPrecharge (which closes the DRAM Page automatically after a read/write) is enabled or not.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CAS_COUNT.ALL",
      EventDef::Encoding{.code = 0x4, .umask = 0xF, .msr_values = {0x00}},
      R"(All DRAM CAS Commands issued)",
      R"(Counts all CAS (Column Address Select) commands issued to DRAM per memory channel.  CAS commands are issued to specify the address to read or write on DRAM, so this event increments for every read and write. This event counts whether AutoPrecharge (which closes the DRAM Page automatically after a read/write) is enabled or not.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_CLOCKTICKS",
      EventDef::Encoding{.code = 0x0, .umask = 0x0, .msr_values = {0x00}},
      R"(Clockticks of the memory controller which uses a programmable counter)",
      R"(Counts clockticks of the fixed frequency clock of the memory controller using one of the programmable counters.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_CHANNEL_PPD",
      EventDef::Encoding{.code = 0x85, .umask = 0x0, .msr_values = {0x00}},
      R"(Channel PPD Cycles)",
      R"(Counts cycles when all the ranks in the channel are in PPD (PreCharge Power Down) mode. If IBT (Input Buffer Terminators)=off is enabled, then this event counts the cycles in PPD mode. If IBT=off is not enabled, then this event counts the number of cycles when being in PPD mode could have been taken advantage of.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_POWER_SELF_REFRESH",
      EventDef::Encoding{.code = 0x43, .umask = 0x0, .msr_values = {0x00}},
      R"(Clock-Enabled Self-Refresh)",
      R"(Counts the number of cycles when the iMC (memory controller) is in self-refresh and has a clock. This happens in some ACPI CPU package C-states for the sleep levels. For example, the PCU (Power Control Unit) may ask the iMC to enter self-refresh even though some of the cores are still processing. One use of this is for Intel? Dynamic Power Technology.  Self-refresh is required during package C3 and C6, but there is no clock in the iMC at this time, so it is not possible to count these cases.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.PAGE_MISS",
      EventDef::Encoding{.code = 0x2, .umask = 0x1, .msr_values = {0x00}},
      R"(Precharges due to page miss)",
      R"(Counts the number of explicit DRAM Precharge commands sent on this channel as a result of a DRAM page miss. This does not include the implicit precharge commands sent with CAS commands in Auto-Precharge mode. This does not include Precharge commands sent as a result of a page close counter expiration.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_PRE_COUNT.RD",
      EventDef::Encoding{.code = 0x2, .umask = 0x4, .msr_values = {0x00}},
      R"(Precharge due to read)",
      R"(Counts the number of explicit DRAM Precharge commands issued on a per channel basis due to a read, so as to close the previous DRAM page, before opening the requested page.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RPQ_INSERTS",
      EventDef::Encoding{.code = 0x10, .umask = 0x0, .msr_values = {0x00}},
      R"(Read Pending Queue Allocations)",
      R"(Counts the number of read requests allocated into the Read Pending Queue (RPQ).  This queue is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the CHA to the iMC.  The requests deallocate after the read CAS command has been issued to DRAM.  This event counts both Isochronous and non-Isochronous requests which were issued to the RPQ.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_RPQ_OCCUPANCY",
      EventDef::Encoding{.code = 0x80, .umask = 0x0, .msr_values = {0x00}},
      R"(Read Pending Queue Occupancy)",
      R"(Counts the number of entries in the Read Pending Queue (RPQ) at each cycle.  This can then be used to calculate both the average occupancy of the queue (in conjunction with the number of cycles not empty) and the average latency in the queue (in conjunction with the number of allocations).  The RPQ is used to schedule reads out to the memory controller and to track the requests.  Requests allocate into the RPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the CHA to the iMC. They deallocate from the RPQ after the CAS command has been issued to memory.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WPQ_INSERTS",
      EventDef::Encoding{.code = 0x20, .umask = 0x0, .msr_values = {0x00}},
      R"(Write Pending Queue Allocations)",
      R"(Counts the number of writes requests allocated into the Write Pending Queue (WPQ).  The WPQ is used to schedule writes out to the memory controller and to track the requests.  Requests allocate into the WPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the CHA to the iMC (Memory Controller).  The write requests deallocate after being issued to DRAM.  Write requests themselves are able to complete (from the perspective of the rest of the system) as soon they have 'posted' to the iMC.)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));

  pmu_manager.addEvent(std::make_shared<EventDef>(
      PmuType::uncore_imc,
      "UNC_M_WPQ_OCCUPANCY",
      EventDef::Encoding{.code = 0x81, .umask = 0x0, .msr_values = {0x00}},
      R"(Write Pending Queue Occupancy)",
      R"(Counts the number of entries in the Write Pending Queue (WPQ) at each cycle.  This can then be used to calculate both the average queue occupancy (in conjunction with the number of cycles not empty) and the average latency (in conjunction with the number of allocations).  The WPQ is used to schedule writes out to the memory controller and to track the requests.  Requests allocate into the WPQ soon after they enter the memory controller, and need credits for an entry in this buffer before being sent from the CHA to the iMC (memory controller).  They deallocate after being issued to DRAM.  Write requests themselves are able to complete (from the perspective of the rest of the system) as soon they have 'posted' to the iMC.  This is not to be confused with actually performing the write to DRAM.  Therefore, the average latency for this queue is actually not useful for deconstruction intermediate write latencies.  So, we provide filtering based on if the request has posted or not.  By using the 'not posted' filter, we can track how long writes spent in the iMC before completions were sent to the HA.  The 'posted' filter, on the other hand, provides information about how much queueing is actually happenning in the iMC for writes before they are actually issued to memory.  High average occupancies will generally coincide with high write major mode counts. Is there a filter of sorts???)",
      std::nullopt,
      std::nullopt, // ScaleUnit
      EventDef::IntelFeatures{},
      std::nullopt // Errata
      ));
}

} // namespace skylakex_uncore
} // namespace facebook::hbt::perf_event::generated
