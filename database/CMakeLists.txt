add_library (database database.cpp database.h)
target_include_directories (database PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries (database PUBLIC logging)
