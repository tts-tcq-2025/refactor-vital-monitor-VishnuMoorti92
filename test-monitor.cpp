#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "monitor.h"

std::vector<std::string> messages;
auto alertfunc = & {
    messages.push_back(msg);
};

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
    messages.clear();
    ASSERT_FALSE(vitalsOk(94, 80, 95, alertfunc));  // Temperature too low
    messages.clear();
    ASSERT_TRUE(vitalsOk(100, 70, 98, alertfunc));  // All vitals OK
    messages.clear();
    ASSERT_FALSE(vitalsOk(105, 80, 95, alertfunc)); // Temperature too high
    messages.clear();
    ASSERT_FALSE(vitalsOk(100, 58, 95, alertfunc)); // Pulse Rate too low
    messages.clear();
    ASSERT_FALSE(vitalsOk(100, 101, 95, alertfunc));// Pulse Rate too high
    messages.clear();
    ASSERT_FALSE(vitalsOk(100, 75, 89.9, alertfunc));// SPO2 too low
}

