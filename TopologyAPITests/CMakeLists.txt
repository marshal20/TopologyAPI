cmake_minimum_required (VERSION 3.1)

set(SRC 
 "src/components_test.cpp"
 "src/topology_test.cpp"
 "src/topology_manager_test.cpp"
)

add_executable(TopologyAPITests ${SRC})
target_link_libraries(TopologyAPITests PRIVATE TopologyAPI GTest::gtest GTest::gtest_main)

