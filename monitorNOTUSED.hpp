#pragma once
#include <string>
#include <functional>

class VitalInfoAndRange {
private:
    std::string vitalType;
    float value;
    float min;
    float max;

public:
    VitalInfoAndRange(const std::string& type, float val, float minVal, float maxVal)
        : vitalType(type), value(val), min(minVal), max(maxVal) {}

    std::string getVitalType() const { return vitalType; }
    float getValue() const { return value; }
    float getMin() const { return min; }
    float getMax() const { return max; }

    void setValue(float val) { value = val; }
    void setMin(float minVal) { min = minVal; }
    void setMax(float maxVal) { max = maxVal; }
};

// Function declarations
bool vitalRangeCheck(VitalInfoAndRange& vitalDetails);
bool vitalRangeAlertMsg(VitalInfoAndRange& vitalDetails, std::function<void(std::string&)> prntWrng);
int vitalsOk(float temperature, float pulseRate, float spo2, std::function<void(std::string&)> prntWrng);

