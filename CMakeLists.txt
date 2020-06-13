# from here: https://github.com/lefticus/cpp_starter_project/blob/master/

cmake_minimum_required(VERSION 3.16)

project(blaze CXX)
include(cmake/StandardProjectSettings.cmake)

# Link to this 'Library' to set the C++ standard / compile time options requested
add_library(blaze_project_options INTERFACE)
target_compile_features(blaze_project_options INTERFACE cxx_std_17)

add_library(Blaze::ProjectOption ALIAS blaze_project_options)

# Link to this 'Library' to use the warnings
add_library(blaze_project_warnings INTERFACE)
if(not APPLE)
	# TODO: The settings specified in compiler warning here are not compatible with macos, these need to be updated
	include(cmake/CompilerWarnings.cmake)
endif()
set_project_warnings(blaze_project_warnings)

add_library(Blaze::ProjectWarnings ALIAS blaze_project_warnings)

# Sanitizer options if supported by the compiler
include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

# Enable doxygen
include(cmake/Doxygen.cmake)
enable_doxygen()

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)

# External dependencies
add_subdirectory(external)

# Testing 
option(ENABLE_TESTING "Enable test builds" ON)
if(ENABLE_TESTING)
	include(CTest)
	message(STATUS "Building tests")
	enable_testing()
endif()

# Sources
add_subdirectory(Blaze)

# Install
install(
	TARGETS
		blaze_engine_base
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
	INCLUDES DESTINATION include
)