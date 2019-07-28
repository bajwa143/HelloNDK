
#include "PrimeNumber.h"

PrimeNumber::PrimeNumber(int number) {
    this->number = number;
}

int PrimeNumber::getNumber() {
    return number;
}

bool PrimeNumber::isPrime() {
    if (number <= 1) {
        return false;
    }

    if (number <= 3) {
        return true;
    }

    bool ans;
    for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            return false;
        } else {
            ans = true;
        }
    }
    return ans;
}


