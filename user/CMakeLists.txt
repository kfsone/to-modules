add_library(
	user
	user.cpp user.h
)
target_link_libraries (user PRIVATE database logging)
