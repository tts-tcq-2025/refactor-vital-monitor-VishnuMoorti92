#pragma once
#include <string>
#include <functional>

struct vitalInfoandRange {
    std::string vitalType;
    float value;
    float min;
    float max;
};

bool vitalRangechekandAlertmsg(vitalInfoandRange& vitaldetails, std::function<void(std::string&)> prntWrng);

int vitalsOk(float temperature, float pulseRate, float spo2);
