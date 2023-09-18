cmake_minimum_required(VERSION 3.12)
project(gca)

set(CMAKE_BUILD_TYPE Debug)

# Source files
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
# set(TEST_DIR "${CMAKE_SOURCE_DIR}/tests")
set(SRC_FILES
    ${SRC_DIR}/cell/cell.cpp
    ${SRC_DIR}/cell_space/cell_space.cpp
    ${SRC_DIR}/cell_space/timestep_functions.cpp
    ${SRC_DIR}/cell_space/transition_functions.cpp
    ${SRC_DIR}/file_io/file_io.cpp
)

# Include directories
include_directories(
    ${SRC_DIR}
)

# Add executable
add_executable(gca ${SRC_FILES} ${SRC_DIR}/gca/gca.cpp)
target_compile_options(gca PRIVATE -g -Wall -Wextra)
