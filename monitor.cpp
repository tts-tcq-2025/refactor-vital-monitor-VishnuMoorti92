#include "earlywarning.hpp"

bool isVitalOutOfRange(const vitalInfoandRange& vital) {
    return vital.value < vital.min || vital.value > vital.max;
}

void handleVitalStatus(const vitalInfoandRange& vital, std::function<void(std::string&)> prntWrng, bool& allOk) {
    std::string warningMsg;
    if (EarlyWarning::isInWarningRange(vital, warningMsg)) {
        prntWrng(warningMsg);
    }

    if (isVitalOutOfRange(vital)) {
        std::string alert = vital.vitalType + " is out of range!";
        prntWrng(alert);
        allOk = false;
    }
}

int vitalsOk(float temperature, float pulseRate, float spo2, std::function<void(std::string&)> prntWrng) {
    vitalInfoandRange vitals[] = {
        {"Temperature", temperature, 95.0, 102.0},
        {"Pulse Rate", pulseRate, 60.0, 100.0},
        {"Oxygen Saturation", spo2, 90.0, 100.0}
    };

    bool allVitalsOk = true;
    for (const auto& vital : vitals) {
        handleVitalStatus(vital, prntWrng, allVitalsOk);
    }
    return allVitalsOk;
}

