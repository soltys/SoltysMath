cmake_minimum_required(VERSION 3.28)

project(
    SoltysMath
    VERSION 0.0.1
    DESCRIPTION "Soltys Math"
    HOMEPAGE_URL "https://github.com/soltys/SoltysMath"
    LANGUAGES CXX
)

add_library(soltys_math_lib
 SHARED 
 lib/math.cpp 
 lib/include/soltysmath/math.hpp)
target_include_directories(soltys_math_lib PRIVATE lib/include)

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

#Building dotnet solution
find_program(DOTNET_EXE dotnet REQUIRED)
add_custom_target(dotnet_build ALL
  DEPENDS soltys_math_lib
  COMMAND ${DOTNET_EXE} build -c $<CONFIG> --property:SoltysMathLibPath=$<TARGET_FILE:soltys_math_lib>
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/ffi/dotnet
  COMMENT "Building dotnet solution under $<CONFIG> configuration"
)
add_test(
  NAME ffi_dotnet_nativelibuse_projectworks 
  COMMAND ${DOTNET_EXE} run --no-build
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/ffi/dotnet/NativeLibUse
  )

find_program(CARGO_EXE cargo REQUIRED)
add_custom_target(rust_build ALL
  DEPENDS soltys_math_lib ${CMAKE_SOURCE_DIR}/ffi/rust/CreateBuildRs.cmake
  COMMAND ${CMAKE_COMMAND} -D Target_File=$<TARGET_FILE:soltys_math_lib> -D Rust_Dir=${CMAKE_SOURCE_DIR}/ffi/rust -P ${CMAKE_SOURCE_DIR}/ffi/rust/CreateBuildRs.cmake
  COMMAND ${CARGO_EXE} build 
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/ffi/rust
  COMMENT "Building rust solution under dev configuration"
)
add_test(
  NAME ffi_rust_prime
  COMMAND ${CMAKE_SOURCE_DIR}/ffi/rust/target/debug/my-project.exe
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>
)

find_package (Python COMPONENTS Interpreter REQUIRED)
set(Python_Dir ${CMAKE_SOURCE_DIR}/ffi/python)
add_custom_target(create_python_script ALL
  DEPENDS soltys_math_lib ${Python_Dir}/CreateIsPrimeScript.cmake
  COMMAND ${CMAKE_COMMAND} -D Python_Dir=${Python_Dir} -D Target_File=$<TARGET_FILE:soltys_math_lib> -P ${Python_Dir}/CreateIsPrimeScript.cmake
  COMMENT "Creating Python script for testing FFI"
)
add_test(
  NAME ffi_python_prime
  COMMAND ${Python_EXECUTABLE} ${Python_Dir}/is_prime.py
)