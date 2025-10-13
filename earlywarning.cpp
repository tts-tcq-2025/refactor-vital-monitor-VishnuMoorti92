
#include "earlywarning.hpp"
#include <vector>
#include <string>
#include <unordered_map>

namespace {

// Map condition to warning message
std::string conditionToMessage(const std::string& type, VitalCondition condition) {
    static const std::unordered_map<std::string, std::unordered_map<VitalCondition, std::string>> messages = {
        {"Oxygen Saturation", {
            {VitalCondition::NEAR_LOWER, "Warning: Approaching hypoxia"}
        }},
        {"Temperature", {
            {VitalCondition::NEAR_LOWER, "Warning: Approaching hypothermia"},
            {VitalCondition::NEAR_UPPER, "Warning: Approaching hyperthermia"}
        }}
    };

    auto typeIt = messages.find(type == "Oxygen Saturation" ? "Oxygen Saturation" : "Temperature");
    if (typeIt != messages.end()) {
        auto condIt = typeIt->second.find(condition);
        if (condIt != typeIt->second.end()) {
            return condIt->second;
        }
    }
    return "";
}

// Calculate tolerance based on max value
float calculateTolerance(const vitalInfoandRange& vital) {
    return 0.015f * vital.max;
}

// Map value to condition
VitalCondition mapToCondition(const vitalInfoandRange& vital) {
    float tolerance = calculateTolerance(vital);
    if (vital.value >= vital.min && vital.value < vital.min + tolerance)
        return VitalCondition::NEAR_LOWER;

    if (vital.vitalType != "Oxygen Saturation" &&
        vital.value <= vital.max && vital.value > vital.max - tolerance)
        return VitalCondition::NEAR_UPPER;

    return VitalCondition::NORMAL;
}

} // anonymous namespace

// Compose transformations
bool EarlyWarning::isInWarningRange(const vitalInfoandRange& vital, std::string& warningMsg) {
    VitalCondition condition = mapToCondition(vital);
    warningMsg = conditionToMessage(vital.vitalType, condition);
    return condition != VitalCondition::NORMAL;
}
