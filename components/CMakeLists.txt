add_library (
	components
		# Convention suggests <module>-<partition>.impl.cpp
		# but that would make a larger diff
		database.cpp
		user.cpp
)

target_sources (
	components
	PUBLIC FILE_SET cxx_modules TYPE CXX_MODULES FILES
		components.ixx
		database.ixx
		logging.ixx
		user.ixx
)

