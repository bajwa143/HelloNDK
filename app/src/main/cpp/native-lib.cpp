#include <jni.h>
#include <string>
#include "PrimeNumber.h"

using namespace std;
extern "C" JNIEXPORT jstring JNICALL
Java_com_hellondk_MainActivity_getPrimeNumber(
        JNIEnv *env,
        jobject) {
    PrimeNumber primeNumber = PrimeNumber(43);

    int pNum = primeNumber.getNumber();
    string message = "Prime Number = " + to_string(pNum);

    return env->NewStringUTF(message.c_str());

}

extern "C" JNIEXPORT jstring JNICALL
Java_com_hellondk_MainActivity_findPrime(
        JNIEnv *env,
        jobject,jint inputNumber) {

    PrimeNumber primeNumber = PrimeNumber(inputNumber);
    string message;
    bool result = primeNumber.isPrime();

    if(result == true) {
        message = "Prime Number";

    }else{
        message = "Not Prime Number";
    }

    return env->NewStringUTF(message.c_str());

}
