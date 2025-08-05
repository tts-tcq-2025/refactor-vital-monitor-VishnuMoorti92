#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "./monitor.hpp"

std::vector<std::string> messages;
auto alertfunc = [&messages](const std::string& msg) {
        messages.push_back(msg);
    };

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsOk(94, 80, 95, alertfunc));
  ASSERT_TRUE(vitalsOk(100, 70, 98, alertfunc));
  ASSERT_FALSE(vitalsOk(105, 80, 95, alertfunc));
  ASSERT_TRUE(vitalsOk(100, 55, 95, alertfunc));
  ASSERT_FALSE(vitalsOk(100, 101, 95, alertfunc));
  ASSERT_FALSE(vitalsOk(100, 75, 88, alertfunc));
}





