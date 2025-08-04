#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

void dynamicUpdateandWarningandPrint(const std::string& message) {
    cout << message << "\n";
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}

bool vitalRangechekandAlertmsg(vitalInfoandRange& vitaldetails, std::function<void(std::string&)> prntWrng) {
    if(vitaldetails.vitalType is not "Oxygen Saturation")
    {
        if (vitaldetails.value < vitaldetails.min || vitaldetails.value > vitaldetails.max) {
            alert(vitaldetails.vitalType + " is out of range!");
            return false;
    }
    else{
        if (vitaldetails.value < vitaldetails.min) {
            alert(vitaldetails.vitalType + " is out of range!");
            return false;
        }
    }
    return true;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
vitalInfoandRange vitaldetails[] = {
        {"Temperature", temperature, 95.0, 102.0},
        {"Pulse Rate", pulseRate, 60.0, 100.0},
        {"Oxygen Saturation", spo2, 90.0, 89.0}
    };

    bool vitalsChkOk = true;
    for (int i = 0; i < 3; ++i) {
        vitalsChkOk = vitalRangechekandAlertmsg(vitals[i], alert);
    }

    return vitalsChkOk;
}
