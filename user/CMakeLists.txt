add_library (user user.cpp user.h)
target_include_directories (user PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries (user PUBLIC database logging)
