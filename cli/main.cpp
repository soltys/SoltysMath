#include <iostream>
#include <string>
#include <soltysmath/math.hpp>

int main(int argc, char **argv)
{
    if (argc != 4 && argc != 5)
    {
        std::cerr << "ERROR: wrong amount of arguments! (argc: " << argc << ")" << std::endl;
        std::cerr << "EXAMPLE: soltys_math_cli.exe OPERATION VALUE1 VALUE2" << std::endl;
        std::cerr << "EXAMPLE: soltys_math_cli.exe OPERATION VALUE1 VALUE2 EXPECTED_VALUE" << std::endl;
        std::cerr << "EXAMPLE: soltys_math_cli.exe addition 21 37" << std::endl;
        return 1;
    }
    auto value1 = std::stoi(argv[2]);
    auto value2 = std::stoi(argv[3]);
    int computed_value = 0;
    if (std::string(argv[1]) == "addition")
    {
        computed_value = sm_addition(value1, value2);
    }
    else if (std::string(argv[1]) == "subtraction")
    {
        computed_value = sm_subtraction(value1, value2);
    }
    else if (std::string(argv[1]) == "multiplication")
    {
        computed_value = sm_multiplication(value1, value2);
    }
    else if (std::string(argv[1]) == "division")
    {
        computed_value = sm_division(value1, value2);
    }
    else if (std::string(argv[1]) == "is_prime")
    {
        computed_value = sm_is_prime(value1);
    }
    else
    {
        std::cerr << "ERROR: unknown operation, possible operaitons: [addition/subtraction/multiplication/division/is_prime]" << std::endl;
        return 1;
    }

    std::cout << computed_value << std::endl;

    bool check_expected_value = argc == 5;
    if (check_expected_value)
    {
        auto expected_value = std::stoi(argv[4]);
        if (computed_value == expected_value)
        {
            return 0;
        }
        else
        {
            std::cerr << "ERROR: expected_value =" << expected_value << " computed_value=" << computed_value << std::endl;
            return 1;
        }
    }
    return 0;
}
