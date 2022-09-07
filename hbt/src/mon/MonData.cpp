#include "hbt/src/mon/MonData.h"

using namespace facebook::hbt::mon;

std::vector<ModuleInfo> detail::getFileBackedExecutableModules(
    std::vector<pfs::mem_region>& mem_regions) {
  // Sort mem_regions by start_address (ascending) so we can easily set each
  // module's load address to the lowest start address of its sections.
  std::sort(mem_regions.begin(), mem_regions.end());

  // A module is an executable file mapped into the process' address space.
  // Since there can be multiple mem_regions (sections) per file we set the
  // module's load address to the lowest start address of its sections.
  // The sections are sorted by start_address, so for each module we simply set
  // its load address to the start address of its first section.
  //
  // In the future this will need to be updated to account for "special" modules
  // that aren't backed by a file (vdso).

  // The inodes that are backed by a file and have an executable section.
  std::unordered_set<ino_t> executable_inodes;

  // First pass to populate exectuable_inodes
  for (const auto& region : mem_regions) {
    ino_t inode = region.inode;
    if (region.perm.can_execute && std::filesystem::exists(region.pathname)) {
      executable_inodes.insert(inode);
    }
  }

  std::vector<ModuleInfo> modules;

  // Second pass to only populate the modules based on the set of executable
  // inodes.
  for (const auto& region : mem_regions) {
    ino_t inode = region.inode;
    if (executable_inodes.find(inode) != executable_inodes.end()) {
      modules.emplace_back(region.pathname, region.start_address);
      // remove from set so we don't store duplicate modules.
      executable_inodes.erase(inode);
    }
  }
  return modules;
}
