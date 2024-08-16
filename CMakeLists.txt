cmake_minimum_required(VERSION 3.28)

project(
    SoltysMath
    VERSION 0.0.1
    DESCRIPTION "Soltys Math"
    HOMEPAGE_URL "https://github.com/soltys/SoltysMath"
    LANGUAGES CXX
)


add_library(soltys_math_lib lib/math.cpp lib/include/soltysmath/math.hpp)
target_include_directories(soltys_math_lib PRIVATE lib/include)

add_executable(soltys_math_cli cli/main.cpp)

target_link_libraries(soltys_math_cli PRIVATE soltys_math_lib)
target_include_directories(soltys_math_cli PRIVATE lib/include)


enable_testing()

add_test(NAME addition_not_crash COMMAND soltys_math_cli addition 21 37)
add_test(NAME subtraction_not_crash COMMAND soltys_math_cli subtraction 21 37)
add_test(NAME multiplication_not_crash COMMAND soltys_math_cli multiplication 21 37)
add_test(NAME division_not_crash COMMAND soltys_math_cli division 21 37)


Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.7.0 
)

FetchContent_MakeAvailable(Catch2)
add_executable(soltys_math_test test/soltysmath.cpp)
target_link_libraries(soltys_math_test Catch2::Catch2WithMain soltys_math_lib)
target_include_directories(soltys_math_test PRIVATE lib/include)
include(Catch)
catch_discover_tests(soltys_math_test)