#ifndef EARLYWARNING_HPP
#define EARLYWARNING_HPP

#include "monitor.h"
#include <string>

enum class VitalCondition {
    NORMAL,
    NEAR_LOWER,
    NEAR_UPPER
};

class EarlyWarning {
public:
    static bool isInWarningRange(const vitalInfoandRange& vital, std::string& warningMsg);
};

#endif // EARLYWARNING_HPP
