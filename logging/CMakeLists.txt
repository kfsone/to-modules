# Header only implementation solely to provide an example.
add_library (logging)  # INTERFACE) <- not any more.
target_sources (
	logging
	PUBLIC FILE_SET cxx_modules TYPE CXX_MODULES FILES
		logging.ixx
)
