# Build stage
FROM ubuntu:latest as builder

# Set the working directory
WORKDIR /app

# Install build dependencies
RUN apt-get update && apt-get install -y \
    pkg-config \
    g++ \
    cmake \
    make \
    libgrpc++-dev \
    libprotobuf-dev \
    protobuf-compiler-grpc

# Copy the source code into the container
COPY . .

RUN mkdir build

# Run CMake to build the project
RUN cmake -B build && cd build && make

ENTRYPOINT [ "/app/build/model_serving" ]
