#include <iostream>
#include <string>
#include <soltysmath/math.hpp>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "ERROR: wrong amount of arguments!" << std::endl;
        std::cout << "EXAMPLE: soltys_math_cli.exe OPERATION VALUE1 VALUE2" << std::endl;
        std::cout << "EXAMPLE: soltys_math_cli.exe addition 21 37" << std::endl;
        return 1;
    }
    auto value1 = std::stoi(argv[2]);
    auto value2 = std::stoi(argv[3]);
    if (std::string(argv[1]) == "addition")
    {
        std::cout << sm_addition(value1, value2) << std::endl;
    }
    else if (std::string(argv[1]) == "subtraction")
    {
        std::cout << sm_subtraction(value1, value2) << std::endl;
    }
    else if (std::string(argv[1]) == "multiplication")
    {
        std::cout << sm_multiplication(value1, value2) << std::endl;
    }
    else if (std::string(argv[1]) == "division")
    {
        std::cout << sm_division(value1, value2) << std::endl;
    }
    else
    {
        std::cout << "ERROR: unknown operation, possible operaitons: [addition/subtraction/multiplication/division]" << std::endl;
        return 1;
    }

    return 0;
}
