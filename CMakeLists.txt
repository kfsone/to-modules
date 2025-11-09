cmake_minimum_required (VERSION 3.21)  # Works best with 4.0+


# Toolchain factors
set (CMAKE_CXX_STANDARD          20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS        OFF)  # consistency


project (ToModules LANGUAGES CXX)


add_executable (main main.cpp)
