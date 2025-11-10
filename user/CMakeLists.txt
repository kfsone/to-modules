add_library (user user.impl.cpp)
target_sources (user PUBLIC FILE_SET cxx_modules TYPE CXX_MODULES FILES user.ixx)
target_link_libraries (user PUBLIC database logging)
