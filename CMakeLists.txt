cmake_minimum_required(VERSION 3.10)

project(MyCoreUtils C)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Set output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Build cat utility
add_executable(my-cat cat.c)

# Build cp utility
add_executable(my-cp cp.c)

# Build mkdir utility
add_executable(my-mkdir mkdir.c)
