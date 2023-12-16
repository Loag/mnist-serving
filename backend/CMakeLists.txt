cmake_minimum_required(VERSION 3.0)
project(MnistServing)

# Set the C++ standard, e.g., C++11, C++14, C++17
set(CMAKE_CXX_STANDARD 11)

# Include directories for third-party libraries
include_directories(${CMAKE_SOURCE_DIR}/include/)

# Add library directories
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Specify the executable target and its source files
add_executable(model_serving src/main.cpp)
# Add more source files as needed

# Link the libraries to your executable
target_link_libraries(model_serving libonnxruntime.so)
