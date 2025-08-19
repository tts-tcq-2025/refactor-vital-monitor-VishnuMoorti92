#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <functional>
#include "monitor.h"
#include "test_Monitor.hpp"

std::vector<std::string> messages;
auto alertfunc = [&messages](const std::string& msg) {
        messages.push_back(msg);
};

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
    messages.clear();
    ASSERT_FALSE(vitalsOk(94, 80, 95, alertfunc));
    messages.clear();
    ASSERT_TRUE(vitalsOk(100, 70, 98, alertfunc));
    messages.clear();
    ASSERT_FALSE(vitalsOk(105, 80, 95, alertfunc));
    messages.clear();
    ASSERT_FALSE(vitalsOk(100, 58, 95, alertfunc));
    messages.clear();
    ASSERT_FALSE(vitalsOk(100, 101, 95, alertfunc));
    messages.clear();
    ASSERT_FALSE(vitalsOk(100, 75, 89.9, alertfunc));
}


TEST(Monitor, WarningGeneratedNearLowerThreshold) {
    messages.clear();
    ASSERT_TRUE(vitalsOk(95.1, 60.1, 90.1, alertfunc));
}

TEST(Monitor, WarningGeneratedNearUpperThreshold) {
    messages.clear();
    ASSERT_TRUE(vitalsOk(101.1, 99.1, 99.1, alertfunc));
    ASSERT_FALSE(messages.empty());
}

TEST(Monitor, NoWarningOrAlertWhenVitalsAreMidRange) {
    messages.clear();
    ASSERT_TRUE(vitalsOk(98.6, 75, 96, alertfunc));
    ASSERT_TRUE(messages.empty());
}















