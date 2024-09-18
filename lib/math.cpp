#define SOLTYS_EXPORT
#include <soltysmath/math.hpp>

int sm_addition(int a, int b)
{
    return a + b;
}
int sm_subtraction(int a, int b)
{
    return a - b;
}
int sm_multiplication(int a, int b)
{
    return a * b;
}
int sm_division(int a, int b)
{
    return a / b;
}
int sm_is_prime(int64_t n)
{
    if (n < 2)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return 0;
    }
    for (int64_t i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}