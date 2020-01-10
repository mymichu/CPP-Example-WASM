# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.16)

cmake_minimum_required(VERSION 3.5.1)
option(JS_ONLY "Compiles to native JS (No WASM)" OFF)

add_definitions(-std=c++11 -O3)


add_library(obj_utils
			utils/calculator.cpp)


message(STATUS "Setting compilation target to WASM")
set(CMAKE_EXECUTABLE_SUFFIX ".wasm.js")

# Add an executable
add_executable(image-engine image-engine.cpp $<TARGET_OBJECTS:obj_utils>)

set_target_properties(image-engine PROPERTIES LINK_FLAGS "--bind -Oz -s WASM=1 -s NO_EXIT_RUNTIME=1 -s \"EXTRA_EXPORTED_RUNTIME_METHODS=['addOnPostRun']\"")

