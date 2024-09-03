#pragma once
#include <stdint.h>

#ifdef SOLTYS_EXPORT
#define SOLTYS_DLL extern "C" __declspec(dllexport)
#else
#define SOLTYS_DLL extern "C" __declspec(dllimport)
#endif
extern "C"
{
    SOLTYS_DLL int sm_addition(int a, int b);
    SOLTYS_DLL int sm_subtraction(int a, int b);
    SOLTYS_DLL int sm_multiplication(int a, int b);
    SOLTYS_DLL int sm_division(int a, int b);
    SOLTYS_DLL int sm_is_prime(int64_t n);
}