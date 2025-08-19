#include "earlywarning.hpp"
#include <vector>
#include <string>

namespace {

// Map condition to warning message
std::string conditionToMessage(const std::string& type, VitalCondition condition) {
    if (type == "Oxygen Saturation") {
        if (condition == VitalCondition::NEAR_LOWER)
            return "Warning: Approaching hypoxia";
    } else {
        if (condition == VitalCondition::NEAR_LOWER)
            return "Warning: Approaching hypothermia";
        if (condition == VitalCondition::NEAR_UPPER)
            return "Warning: Approaching hyperthermia";
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
