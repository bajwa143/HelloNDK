#include <jni.h>
#include <string>
#include "PrimeNumber.h"

using namespace std;

// The naming convention for the C function is Java_{package_and_classname}_{function_name}(JNI_arguments).
// The dot in package name is replaced by underscore

// JNIEnv*: reference to JNI environment, which lets you access all the JNI functions.

// The extern "C" is recognized by C++ compiler only. It notifies the C++ compiler that these functions are to
// be compiled using C's function naming protocol instead of C++ naming protocol. C and C++ have different function
// naming protocols as C++ support function overloading and uses a name mangling scheme to differentiate the overloaded functions.

extern "C" JNIEXPORT jstring JNICALL
Java_com_hellondk_MainActivity_getPrimeNumber(JNIEnv *env, jobject) {
    PrimeNumber primeNumber = PrimeNumber(43);

    int pNum = primeNumber.getNumber();
    string message = "Prime Number = " + to_string(pNum);

    return env->NewStringUTF(message.c_str());

}

extern "C" JNIEXPORT jstring JNICALL
Java_com_hellondk_MainActivity_findPrime(JNIEnv *env, jobject, jint inputNumber) {

    // We don't need to convert jint to int, because
    // Java Primitives: jint, jbyte, jshort, jlong, jfloat, jdouble, jchar, jboolean for
    // Java Primitive of int,  byte, short,  long,  float,  double,  char and boolean, respectively
    // It is interesting to note that jint is mapped to C's long (which is at least 32 bits), instead of of C's int
    // (which could be 16 bits). Hence, it is important to use jint in the C program, instead of simply using int.
    PrimeNumber primeNumber = PrimeNumber(inputNumber);
    string message;
    bool result = primeNumber.isPrime();

    if (result == true) {
        message = "Prime Number";

    } else {
        message = "Not Prime Number";
    }

    return env->NewStringUTF(message.c_str());

}

// JNI is a C interface, which is not object-oriented. It does not really pass the objects
