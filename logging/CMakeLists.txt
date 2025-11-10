# Header-only library so we can demonstrate modulizing one

add_library (logging)
target_sources (
	logging
	PUBLIC FILE_SET cxx_modules TYPE CXX_MODULES
	FILES
		logging.ixx
)

