cmake_minimum_required (VERSION 3.21)  # Works best with 4.0+


# Toolchain factors
set (CMAKE_CXX_STANDARD          20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS        OFF)  # consistency


project (ToModules LANGUAGES CXX)

include_directories (${CMAKE_CURRENT_LIST_DIR})  # so #include <x/x.h> works

add_subdirectory (database)
add_subdirectory (logging)
add_subdirectory (user)


add_executable (main main.cpp)
target_link_libraries (main PUBLIC database logging user)
