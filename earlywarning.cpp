#include "earlywarning.hpp"

namespace {
    float calculateTolerance(const vitalInfoandRange& vital) {
        return 0.015f * vital.max;
    }

    bool isApproachingLowerBound(const vitalInfoandRange& vital, float tolerance) {
        return vital.value >= vital.min && vital.value < vital.min + tolerance;
    }

    bool isApproachingUpperBound(const vitalInfoandRange& vital, float tolerance) {
        return vital.value <= vital.max && vital.value > vital.max - tolerance;
    }
}

bool EarlyWarning::isInWarningRange(const vitalInfoandRange& vital, std::string& warningMsg) {
    float tolerance = calculateTolerance(vital);

    if (vital.vitalType == "Oxygen Saturation") {
        if (isApproachingLowerBound(vital, tolerance)) {
            warningMsg = "Warning: Approaching hypoxia";
            return true;
        }
        return false;
    }

    if (isApproachingLowerBound(vital, tolerance)) {
        warningMsg = "Warning: Approaching hypothermia";
        return true;
    }

    if (isApproachingUpperBound(vital, tolerance)) {
        warningMsg = "Warning: Approaching hyperthermia";
        return true;
    }

    return false;
}

