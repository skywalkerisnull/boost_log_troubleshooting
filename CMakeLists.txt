cmake_minimum_required (VERSION 3.16)

project (boost_log_trouble VERSION 0.1.0 LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 20)

set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    ON)

set(BOOST_LOG_PROJECT_DEPENDENCIES 
        boost-thread        
        boost-uuid
        boost-proto
        boost-log
        boost-filesystem
        boost-chrono
        boost-program-options
        protobuf
        grpc
        cryptopp
        azure-storage-cpp)

# add_definitions(-DBOOST_LOG_DYN_LINK)

if(NOT DEFINED ${CMAKE_TOOLCHAIN_FILE})
  if(NOT DEFINED ENV{VCPKG_ROOT})
    if(WIN32)
      set (VCPKG_ROOT $ENV{HOMEDRIVE}$ENV{HOMEPATH}/vcpkg_cpptruths)
      set (Boost_INCLUDE_DIR ${VCPKG_ROOT}/installed/x64-windows-static/include)
    else()
      set (VCPKG_ROOT $ENV{HOME}/.vcpkg_cpptruths)
      set (Boost_INCLUDE_DIR ${VCPKG_ROOT}/installed/x64-linux/include)
      set (BOOST_ROOT {VCPKG_ROOT}/installed/x64-linux/include CACHE PATH "Boost library path" )
    endif()
    set (Boost_NO_SYSTEM_PATHS on CACHE BOOL "Do not search system for Boost" )
  else()
    set (VCPKG_ROOT $ENV{VCPKG_ROOT})
  endif()

  if(NOT EXISTS ${VCPKG_ROOT})
    message("Cloning vcpkg in ${VCPKG_ROOT}")
    execute_process (COMMAND git clone https://github.com/Microsoft/vcpkg.git ${VCPKG_ROOT})
  else()
    execute_process (COMMAND git -C ${VCPKG_ROOT} pull)
  endif()

  if(NOT EXISTS ${VCPKG_ROOT}/README.md)
    message (FATAL_ERROR "***** FATAL ERROR: Could not clone vcpkg *****")
  endif()

  if(WIN32)
    set (VCPKG_EXEC ${VCPKG_ROOT}/vcpkg.exe)
    set (VCPKG_BOOTSTRAP ${VCPKG_ROOT}/bootstrap-vcpkg.bat)
  else()
    set (VCPKG_EXEC ${VCPKG_ROOT}/vcpkg)
    set (VCPKG_BOOTSTRAP ${VCPKG_ROOT}/bootstrap-vcpkg.sh)
  endif()

  if(NOT EXISTS ${VCPKG_EXEC})
    message ("Bootstrapping vcpkg in ${VCPKG_ROOT}")
    execute_process (COMMAND ${VCPKG_BOOTSTRAP} WORKING_DIRECTORY ${VCPKG_ROOT})
  endif()

  if(NOT EXISTS ${VCPKG_EXEC})
    message (FATAL_ERROR "***** FATAL ERROR: Could not bootstrap vcpkg *****")
  endif()

  set (CMAKE_TOOLCHAIN_FILE ${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake CACHE STRING "")

  message (STATUS "***** Checking project third party dependencies in ${VCPKG_ROOT} *****")
  execute_process (COMMAND ${VCPKG_EXEC} install ${BOOST_LOG_PROJECT_DEPENDENCIES} WORKING_DIRECTORY ${VCPKG_ROOT})
endif()

find_package (Boost REQUIRED)
include_directories (${Boost_INCLUDE_DIRS})
include_directories (${CMAKE_CURRENT_SOURCE_DIR} )
message ("boost lib: ${Boost_LIBRARIES}, inc:${Boost_INCLUDE_DIRS}")

## Install the executable to <install_directory>/bin
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
## Install libraries (if any) to <install_directory>/bin
set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

## Source file containing the "main" function
set (MAIN_SOURCES main.cpp)
## Specify a name for the generated executable file
set (MAIN_EXE_NAME boost_log_trouble)

add_subdirectory ("Logging")

## 1. Compile...
add_executable (boost_log_trouble main.cpp)

## 2. Link...
target_link_libraries (boost_log_trouble ${Boost_LIBRARIES})

## 3. Install...
# install( TARGETS ${MAIN_EXE_NAME} RUNTIME DESTINATION bin )