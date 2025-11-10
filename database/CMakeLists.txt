add_library (database database.impl.cpp)
target_sources (database PUBLIC FILE_SET cxx_modules TYPE CXX_MODULES FILES database.ixx)
target_link_libraries (database PUBLIC logging)
