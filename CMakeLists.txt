cmake_minimum_required(VERSION 3.1)
project(TopologyAPI)

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )

# dependencies
set(gtest_force_shared_crt ON CACHE BOOL "gtest_force_shared_crt" FORCE)
add_subdirectory(deps/googletest)

# projects
add_subdirectory(TopologyAPI)
add_subdirectory(TopologyAPITests)
