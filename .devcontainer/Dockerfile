FROM mcr.microsoft.com/devcontainers/base:ubuntu

# Install basic tools
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
        build-essential \
        wget \
        ca-certificates \
        git \
        ninja-build \
        clang-18 \
        lldb-18 \
        lld-18 \
        clangd-18 \
        clang-tools-18 \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/* \
    && update-alternatives --install /usr/bin/clang clang /usr/bin/clang-18 100 \
    && update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-18 100 \
    && update-alternatives --install /usr/bin/lld lld /usr/bin/lld-18 100

# Install CMake 3.31
RUN wget https://github.com/Kitware/CMake/releases/download/v3.31.0/cmake-3.31.0-linux-x86_64.tar.gz \
    && tar -xzf cmake-3.31.0-linux-x86_64.tar.gz \
    && mv cmake-3.31.0-linux-x86_64 /opt/cmake \
    && ln -s /opt/cmake/bin/cmake /usr/local/bin/cmake \
    && ln -s /opt/cmake/bin/ctest /usr/local/bin/ctest \
    && ln -s /opt/cmake/bin/cpack /usr/local/bin/cpack \
    && rm cmake-3.31.0-linux-x86_64.tar.gz

# Set environment variables
ENV CC=clang
ENV CXX=clang++
