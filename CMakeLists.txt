cmake_minimum_required(VERSION 3.28)

project(
    SoltysMath
    VERSION 0.0.1
    DESCRIPTION "Soltys Math"
    HOMEPAGE_URL "https://github.com/soltys/SoltysMath"
    LANGUAGES CXX
)


add_library(soltys_math_lib SHARED lib/math.cpp lib/include/soltysmath/math.hpp)
target_include_directories(soltys_math_lib PRIVATE lib/include)
target_compile_definitions(soltys_math_lib PRIVATE SOLTYS_EXPORT)

add_executable(soltys_math_cli cli/main.cpp)
target_link_libraries(soltys_math_cli PRIVATE soltys_math_lib)
target_include_directories(soltys_math_cli PRIVATE lib/include)

#Testing
enable_testing()

add_test(NAME addition_cli COMMAND soltys_math_cli addition 21 37 58)
add_test(NAME subtraction_cli COMMAND soltys_math_cli subtraction 21 37 -16)
add_test(NAME multiplication_cli COMMAND soltys_math_cli multiplication 21 37 777)
add_test(NAME division_cli COMMAND soltys_math_cli division 21 37 0)
add_test(NAME is_prime_21_no_cli COMMAND soltys_math_cli is_prime 21 0 0)
add_test(NAME is_prime_37_yes_cli COMMAND soltys_math_cli is_prime 37 0 1)

#Get unit testing dependecy
include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.7.0 
)

FetchContent_MakeAvailable(Catch2)

#Create unit testing executable
add_executable(soltys_math_test test/soltysmath.cpp)
target_link_libraries(soltys_math_test Catch2::Catch2WithMain soltys_math_lib)
target_include_directories(soltys_math_test PRIVATE lib/include)
include(Catch)
catch_discover_tests(soltys_math_test)


# add_custom_target(dotnet_build
# DEPENDS soltys_math_lib
# COMMAND dotnet build -c Release
# WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/dotnet/csharp_vs_cpp)

# add_custom_command(TARGET dotnet_build PRE_BUILD        
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different  
#         "${CMAKE_BINARY_DIR}/$<CONFIG>/soltys_math_lib.dll"      
#         ${CMAKE_SOURCE_DIR}/dotnet/csharp_vs_cpp/bin/Release/net8.0) 