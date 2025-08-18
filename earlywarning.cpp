#include "earlywarning.hpp"

namespace {
    float calculateTolerance(const vitalInfoandRange& vital) {
        return 0.015f * vital.max;
    }

    std::string getWarningMessage(const std::string& type, bool lowerBound) {
        if (type == "Oxygen Saturation") return "Warning: Approaching hypoxia";
        return lowerBound ? "Warning: Approaching hypothermia" : "Warning: Approaching hyperthermia";
    }
}

bool EarlyWarning::isInWarningRange(const vitalInfoandRange& vital, std::string& warningMsg) {
    const float tolerance = calculateTolerance(vital);
    const bool lowerBound = vital.value >= vital.min && vital.value < vital.min + tolerance;
    const bool upperBound = vital.value <= vital.max && vital.value > vital.max - tolerance;

    if (lowerBound || (vital.vitalType != "Oxygen Saturation" && upperBound)) {
        warningMsg = getWarningMessage(vital.vitalType, lowerBound);
        return true;
    }

    return false;
}


