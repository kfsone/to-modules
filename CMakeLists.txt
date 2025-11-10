cmake_minimum_required (VERSION 4.0)  # earlier versions require additional config


# Toolchain factors
set (CMAKE_CXX_STANDARD          20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS        OFF)  # consistency


project (ToModules LANGUAGES CXX)

add_subdirectory (database)
add_subdirectory (logging)
add_subdirectory (user)


add_executable (main main.cpp)
target_link_libraries (main database logging user)
