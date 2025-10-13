#include "earlywarning.hpp"
#include <vector>
#include <string>
#include <unordered_map>

namespace {

// Lookup table for warning messages
const std::unordered_map<std::string, std::unordered_map<VitalCondition, std::string>> warningMessages = {
    {"Oxygen Saturation", {
        {VitalCondition::NEAR_LOWER, "Warning: Approaching hypoxia"}
    }},
    {"Temperature", {
        {VitalCondition::NEAR_LOWER, "Warning: Approaching hypothermia"},
        {VitalCondition::NEAR_UPPER, "Warning: Approaching hyperthermia"}
    }}
};

// Lookup message based on type and condition
std::string conditionToMessage(const std::string& type, VitalCondition condition) {
    auto typeKey = (type == "Oxygen Saturation") ? "Oxygen Saturation" : "Temperature";
    auto typeIt = warningMessages.find(typeKey);
    auto condIt = (typeIt != warningMessages.end()) ? typeIt->second.find(condition) : warningMessages.at("Temperature").end();
    return (condIt != typeIt->second.end()) ? condIt->second : "";
}

// Calculate tolerance
float calculateTolerance(float max) {
    return 0.015f * max;
}

// Map value to condition
VitalCondition mapToCondition(const vitalInfoandRange& vital) {
    float tolerance = calculateTolerance(vital.max);
    bool nearLower = vital.value >= vital.min && vital.value < vital.min + tolerance;
    bool nearUpper = vital.vitalType != "Oxygen Saturation" &&
                     vital.value <= vital.max && vital.value > vital.max - tolerance;

    return nearLower ? VitalCondition::NEAR_LOWER :
           nearUpper ? VitalCondition::NEAR_UPPER :
           VitalCondition::NORMAL;
}

} // anonymous namespace

// Compose transformations
bool EarlyWarning::isInWarningRange(const vitalInfoandRange& vital, std::string& warningMsg) {
    VitalCondition condition = mapToCondition(vital);
    warningMsg = conditionToMessage(vital.vitalType, condition);
    return condition != VitalCondition::NORMAL;
}
