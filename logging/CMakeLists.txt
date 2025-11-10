# Header-only library so we can demonstrate modulizing one

add_library (logging INTERFACE)  # no compiled sources in this version
target_include_directories (logging INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_sources (logging PRIVATE logging.h)

