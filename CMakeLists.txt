# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.16)

# Set the project name
project (imageengineapp)

add_subdirectory(src)
#add_subdirectory(test)

#include(CTest)
#enable_testing()
#add_test(NAME testCalcAdd COMMAND testCalcAdd)