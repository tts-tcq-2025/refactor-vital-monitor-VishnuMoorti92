#pragma once
#include <string>
#include <functional>

struct vitalInfoandRange {
    std::string vitalType;
    float value;
    float min;
    float max;
};

bool vitalRangechek(vitalInfoandRange& vitaldetails);
bool vitalRangeAlertmsg(vitalInfoandRange& vitaldetails, std::function<void(std::string&)> prntWrng);

int vitalsOk(float temperature, float pulseRate, float spo2, std::function<void(std::string&)> prntWrng);
