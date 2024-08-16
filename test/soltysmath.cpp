#include <catch2/catch_test_macros.hpp>
#include <soltysmath/math.hpp>

TEST_CASE("Addition is performed", "[addition]")
{
    REQUIRE(sm_addition(1, 2) == 3);
    REQUIRE(sm_addition(192, 8) == 200);
}
TEST_CASE("Subtraction is performed", "[subtraction]")
{
    REQUIRE(sm_subtraction(1, 2) == -1);
    REQUIRE(sm_subtraction(200, 8) == 192);
}
TEST_CASE("Multiplication is performed", "[multiplication]")
{
    REQUIRE(sm_multiplication(1, 2) == 2);
    REQUIRE(sm_multiplication(200, 4) == 800);
}
TEST_CASE("Division is performed", "[division]")
{
    REQUIRE(sm_division(1, 2) == 0);
    REQUIRE(sm_division(200, 4) == 50);
}