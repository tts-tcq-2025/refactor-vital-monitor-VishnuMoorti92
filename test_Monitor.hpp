#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <functional>

namespace EarlyWarning {
    bool isInWarningRange(const vitalInfoandRange& vital, std::string& warningMsg) {
        // Simulate warning if value is within 1 unit of min or max
        if (vital.value >= vital.min && vital.value <= vital.min + 1) {
            warningMsg = vital.vitalType + " is approaching lower threshold!";
            return true;
        }
        if (vital.value <= vital.max && vital.value >= vital.max - 1) {
            warningMsg = vital.vitalType + " is approaching upper threshold!";
            return true;
        }
        return false;
    }
}
