cmake_minimum_required(VERSION 3.0)
project(MnistServing)

find_package(PkgConfig REQUIRED)

pkg_check_modules(PROTOBUF REQUIRED protobuf)
pkg_check_modules(GRPC REQUIRED grpc++)

include_directories(${GRPC_INCLUDE_DIRS})
link_directories(${GRPC_LIBRARY_DIRS})

# Set the C++ standard, e.g., C++11, C++14, C++17
set(CMAKE_CXX_STANDARD 17)

# Include directories for third-party libraries
include_directories(${CMAKE_SOURCE_DIR}/include/)

# Add library directories
link_directories(${CMAKE_SOURCE_DIR}/lib)

file(GLOB SOURCES "src/*.cc")

# Specify the executable target and its source files
add_executable(model_serving ${SOURCES})
# Add more source files as needed

# Include directories for gRPC and Protobuf
include_directories(${GRPC_INCLUDE_DIRS} ${PROTOBUF_INCLUDE_DIRS})

# Link directories for gRPC and Protobuf
link_directories(${GRPC_LIBRARY_DIRS} ${PROTOBUF_LIBRARY_DIRS})

# Link the libraries to your executable
target_link_libraries(model_serving libonnxruntime.so grpc++ grpc++_reflection protobuf)
