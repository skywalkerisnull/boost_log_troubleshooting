# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.16)
include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

file( GLOB SOURCES *.h *.cpp )

# Add source to this project's executable.
add_executable (logging "Logging.h" "Logging.cpp")
