// Copyright (c) Meta Platforms, Inc. and affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include "hbt/src/mon/MonData.h"

#include "tools/cxx/Resources.h"

#include <gtest/gtest.h>

using namespace facebook::hbt::mon;

TEST(MonData, ContDataCreation) {
  CountData cd{{"event1", "event2"}};
};

class ModuleCollectionTest : public ::testing::Test {
 protected:
  void SetUp() override {
    // Pass _ec to suppress exceptions since we don't care if this fails.
    std::error_code _ec;
    std::filesystem::remove_all(TEST_MODULES_DIR, _ec);

    try {
      std::filesystem::create_directory(TEST_MODULES_DIR);
    } catch (const std::filesystem::filesystem_error& ex) {
      FAIL() << "Unable to create test file directory: " << TEST_MODULES_DIR;
    }

    for (const auto& [module_path, _] : EXPECTED_MODULES) {
      std::ofstream ofs(module_path);
      ofs.close();
      if (!ofs) {
        FAIL() << "Unable to create test file: " << module_path;
      }
    }
  }

  void TearDown() override {
    // Pass _ec to suppress exceptions since we don't care if this fails.
    std::error_code _ec;
    std::filesystem::remove_all(TEST_MODULES_DIR, _ec);
  }

  static constexpr auto TEST_PROCFS_ROOT_DIR = "hbt/src/mon/tests/parse_procfs";
  static constexpr auto TEST_MODULES_DIR = "/tmp/module_collection_test";
  static constexpr size_t EXPECTED_NUM_MODULES = 3;
  static inline const ModuleInfo EXPECTED_MODULES[EXPECTED_NUM_MODULES] = {
      {fmt::format("{}/lib0", TEST_MODULES_DIR), 0x200000},
      {fmt::format("{}/lib1", TEST_MODULES_DIR), 0x7fe828f6c000},
      {fmt::format("{}/lib2", TEST_MODULES_DIR), 0x7fe829bfd000},
  };
};

TEST_F(ModuleCollectionTest, Collect) {
  auto path = build::getResourcePath(TEST_PROCFS_ROOT_DIR);
  pfs::procfs pfs(path.string());

  auto maps = pfs.get_task(1234).get_maps();
  auto modules = detail::getFileBackedExecutableModules("/", maps);
  ASSERT_EQ(modules.size(), EXPECTED_NUM_MODULES);

  for (size_t i = 0; i < EXPECTED_NUM_MODULES; i++) {
    EXPECT_EQ(modules[i], EXPECTED_MODULES[i]);
  }
}
