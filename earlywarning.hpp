#ifndef EARLYWARNING_HPP
#define EARLYWARNING_HPP

#include <string>

// Enum representing the condition of a vital sign
enum class VitalCondition {
    NORMAL,
    NEAR_LOWER,
    NEAR_UPPER
};

// Struct representing vital sign information and its range
struct vitalInfoandRange {
    std::string vitalType;
    float value;
    float min;
    float max;
};

// EarlyWarning class declaration
class EarlyWarning {
public:
    // Checks if the vital is in a warning range and returns the warning message
    bool isInWarningRange(const vitalInfoandRange& vital, std::string& warningMsg);
};

#endif // EARLYWARNING_HPP
