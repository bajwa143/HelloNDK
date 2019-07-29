
#include "PrimeNumber.h"
#include <android/log.h>

PrimeNumber::PrimeNumber(int number) {
    this->number = number;
}

int PrimeNumber::getNumber() {
    return number;
}

bool PrimeNumber::isPrime() {
    if (number <= 1) {
        __android_log_write(ANDROID_LOG_INFO,"Number Value","Value is less than 1");
        return false;
    }

    if (number <= 3) {
        return true;
    }

    bool ans;
    for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            __android_log_print(ANDROID_LOG_INFO,"Number Value","False return at i value %d",i);
            return false;
        } else {
            ans = true;
        }
    }
    __android_log_write(ANDROID_LOG_INFO,"Number Value","Reached to end of loop, returning true");
    return ans;
}


