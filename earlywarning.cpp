#include "earlywarning.hpp"

bool EarlyWarning::isInWarningRange(const vitalInfoandRange& vital, std::string& warningMsg) {
    float tolerance = 0.015f * vital.max;

    if (vital.vitalType == "Oxygen Saturation") {
        if (vital.value >= vital.min && vital.value < vital.min + tolerance) {
            warningMsg = "Warning: Approaching hypoxia";
            return true;
        }
    } else {
        if (vital.value >= vital.min && vital.value < vital.min + tolerance) {
            warningMsg = "Warning: Approaching hypothermia";
            return true;
        }
        if (vital.value <= vital.max && vital.value > vital.max - tolerance) {
            warningMsg = "Warning: Approaching hyperthermia";
            return true;
        }
    }
    return false;
}
