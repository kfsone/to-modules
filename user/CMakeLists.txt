add_library(
	user
	user.cpp	# or user.impl.cpp
)
target_sources (
	user
	PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES FILES
		user.ixx
)
target_link_libraries (user PRIVATE database logging)
