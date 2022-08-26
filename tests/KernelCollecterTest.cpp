#include <sys/stat.h>

#include <glog/logging.h>
#include <gtest/gtest.h>

// @lint-ignore-every CLANGTIDY facebook-hte-RelativeInclude
#include "KernelCollector.h" // @manual=//dynolog/src:libkernelcollector

namespace dynolog {

namespace {

constexpr char kTestRoot[] = "TESTROOT";

std::string get_test_root() {
  if (const char* env_p = std::getenv(kTestRoot)) {
    return env_p;
  }
  LOG(ERROR) << "Missing test root env: " << kTestRoot;
  return "";
}

int is_directory(const char* path) {
  struct stat statbuf;
  if (::stat(path, &statbuf) != 0) {
    return 0;
  }
  return S_ISDIR(statbuf.st_mode);
}

} // namespace

TEST(KernelCollecterTest, UptimeTest) {
  KernelCollectorBase kb;
  EXPECT_GT(kb.readUptime(), 0);
}

TEST(KernelCollecterTest, CpuStatsTest) {
  auto test_root = get_test_root();
  // ensure path
  ASSERT_NE(test_root, "");
  ASSERT_EQ(is_directory(test_root.c_str()), 1)
      << "Path for test root is invalid" << test_root;

  KernelCollectorBase kb{get_test_root() + "/proc/"};
  kb.readCpuStats();

  EXPECT_EQ(kb.perCoreCpuTime_.size(), 32);
  EXPECT_EQ(kb.cpuCoresTotal_, 32);

  // cpu0 85923288 7559744 25071792 1175164067 39404260 4319 4746442 0 0 0
  EXPECT_EQ(kb.perCoreCpuTime_[0].u, 85923288);
  EXPECT_EQ(kb.perCoreCpuTime_[0].n, 7559744);
  EXPECT_EQ(kb.perCoreCpuTime_[0].s, 25071792);
  EXPECT_EQ(kb.perCoreCpuTime_[0].i, 1175164067);
  EXPECT_EQ(kb.perCoreCpuTime_[0].w, 39404260);
  EXPECT_EQ(kb.perCoreCpuTime_[0].x, 4319);
  EXPECT_EQ(kb.perCoreCpuTime_[0].y, 4746442);
  EXPECT_EQ(kb.perCoreCpuTime_[0].z, 0);
  // cpu31 6316214 2669639 4209634 1332212631 698635 0 25283 0 0 0
  EXPECT_EQ(kb.perCoreCpuTime_[31].u, 6316214);
  EXPECT_EQ(kb.perCoreCpuTime_[31].n, 2669639);
  EXPECT_EQ(kb.perCoreCpuTime_[31].s, 4209634);
  EXPECT_EQ(kb.perCoreCpuTime_[31].i, 1332212631);
  EXPECT_EQ(kb.perCoreCpuTime_[31].w, 698635);
  EXPECT_EQ(kb.perCoreCpuTime_[31].x, 0);
  EXPECT_EQ(kb.perCoreCpuTime_[31].y, 25283);
  EXPECT_EQ(kb.perCoreCpuTime_[31].z, 0);
}
} // namespace dynolog
