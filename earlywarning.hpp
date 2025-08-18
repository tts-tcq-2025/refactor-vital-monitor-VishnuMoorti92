#ifndef EARLYWARNING_HPP
#define EARLYWARNING_HPP

#include "monitor.h"
#include <string>

class EarlyWarning {
public:
    static bool isInWarningRange(const vitalInfoandRange& vital, std::string& warningMsg);
};

#endif // EARLYWARNING_HPP
