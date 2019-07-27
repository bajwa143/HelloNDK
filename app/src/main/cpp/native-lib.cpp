#include <jni.h>
#include <string>
#include "PrimeNumber.h"

using namespace std;
extern "C" JNIEXPORT jstring JNICALL
Java_com_hellondk_MainActivity_getPrimeNumber(
        JNIEnv *env,
        jobject /* this */) {
/*    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());*/
    PrimeNumber primeNumber = PrimeNumber(43);

    int pNum = primeNumber.getNumber();
    string message = "Got prime number = " + to_string(pNum);

    return env->NewStringUTF(message.c_str());

}
