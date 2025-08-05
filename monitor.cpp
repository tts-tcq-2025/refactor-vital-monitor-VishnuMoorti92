#include "monitor.hpp"
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

bool vitalRangechek(vitalInfoandRange& vitaldetails) {
    if(vitaldetails.vitalType != "Oxygen Saturation"){
        return(vitaldetails.value < vitaldetails.min || vitaldetails.value > vitaldetails.max);
    }
    return(vitaldetails.value < vitaldetails.min);
}

bool vitalRangeAlertmsg(vitalInfoandRange& vitaldetails, std::function<void(std::string&)> prntWrng){
    if(vitalRangechek(vitaldetails)){
        std::string msg = vitaldetails.vitalType + " is out of range!";
        prntWrng(msg);
        return false;
    }
    return true;
}

void printalertmassage(std::string& lineContent){
  std::cout<<lineContent;
}

int vitalsOk(float temperature, float pulseRate, float spo2, std::function<void(std::string&)> prntWrng) {
vitalInfoandRange vitaldetails[] = {{"Temperature", temperature, 95.0, 102.0},
                                    {"Pulse Rate", pulseRate, 60.0, 100.0},
                                    {"Oxygen Saturation", spo2, 90.0, 90.0}};

    bool vitalsChkOk = true;
    for (int i = 0; i < 3; ++i) {
        if(!vitalRangeAlertmsg(vitaldetails[i], prntWrng)){
            vitalsChkOk = false;
        }
    }
    return vitalsChkOk;
}
