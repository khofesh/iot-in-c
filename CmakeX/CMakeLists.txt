cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)

# Add the include directory
include_directories(include)

# Add the source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create the executable
add_executable(main ${SOURCES})
