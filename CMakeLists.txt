cmake_minimum_required(VERSION 3.1)
project(TopologyAPI)

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )

# dependencies
# Google Test Library
set(gtest_force_shared_crt ON CACHE BOOL "gtest_force_shared_crt" FORCE)
add_subdirectory("deps/googletest")
# JSON for Modern C++ Library
set(JSON_BuildTests OFF CACHE INTERNAL "JSON_BuildTests" FORCE)
add_subdirectory("deps/json")

# projects
add_subdirectory(TopologyAPI)
add_subdirectory(TopologyAPITests)
