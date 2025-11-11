add_library (components database.impl.cpp user.impl.cpp)
target_sources (
	components
	PUBLIC FILE_SET cxx TYPE CXX_MODULES FILES
		components.ixx
		database.ixx
		logging.ixx
		user.ixx
)
