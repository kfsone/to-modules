add_library (
	database
	database.cpp		# or database.impl.cpp
)
target_sources (
	database
	PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES
		database.ixx
)
target_link_libraries (database PRIVATE logging)
