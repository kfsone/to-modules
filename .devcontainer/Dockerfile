FROM mcr.microsoft.com/devcontainers/base:ubuntu

# clang: 18 and 19 can be bludgeoned into working, but for simplicity's sake...
ENV CLANG_VER=20
# cmake: 3.28+ works with extra config/hacks
ENV CMAKE_VER=4.1.2

RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
        build-essential \
        wget \
        ca-certificates \
        git \
        ninja-build \
        clang-${CLANG_VER} \
        lldb-${CLANG_VER} \
        lld-${CLANG_VER} \
        clangd-${CLANG_VER} \
        clang-tools-${CLANG_VER} \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/* \
    && update-alternatives --install /usr/bin/clang clang /usr/bin/clang-${CLANG_VER} 100 \
    && update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-${CLANG_VER} 100 \
    && update-alternatives --install /usr/bin/lld lld /usr/bin/lld-${CLANG_VER} 100

RUN wget https://github.com/Kitware/CMake/releases/download/v${CMAKE_VER}/cmake-${CMAKE_VER}-linux-x86_64.tar.gz \
    && tar -xzf cmake-${CMAKE_VER}-linux-x86_64.tar.gz \
    && mv cmake-${CMAKE_VER}-linux-x86_64 /opt/cmake \
    && ln -s /opt/cmake/bin/cmake /usr/local/bin/cmake \
    && ln -s /opt/cmake/bin/ctest /usr/local/bin/ctest \
    && ln -s /opt/cmake/bin/cpack /usr/local/bin/cpack \
    && rm cmake-${CMAKE_VER}-linux-x86_64.tar.gz

# Set environment variables
ENV CC=clang
ENV CXX=clang++
