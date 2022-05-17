cmake_minimum_required (VERSION 3.1)

set(SRC 
 "include/top/component.h"
 "src/component.cpp"
 "include/top/nmos.h"
 "src/nmos.cpp"
 "include/top/resistor.h"
 "src/resistor.cpp"
 "include/top/component_value.h"
 "include/top/topology.h"
 "src/topology.cpp"
)

add_library(TopologyAPI STATIC ${SRC})

target_include_directories(TopologyAPI
  PRIVATE src
  PUBLIC include
)

