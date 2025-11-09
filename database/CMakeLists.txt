add_library (
	database
	database.cpp database.h
)
target_link_libraries (database PRIVATE logging)
