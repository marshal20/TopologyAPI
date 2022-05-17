cmake_minimum_required (VERSION 3.1)

set(SRC 
		include/top/component.h
		src/component.cpp
		)

add_library(TopologyAPI STATIC ${SRC})

target_include_directories(TopologyAPI
  PRIVATE src
  PUBLIC include
)

