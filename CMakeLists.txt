cmake_minimum_required(VERSION 3.13)
project(datastructures CXX)
add_library(LibDataStructures
        src/List/List.cc
        src/List/ListNode.cc
        src/List/ListNodeElement.cc
        src/List/ListNodeEnd.cc

        src/Graph/Graph.cc
        src/Graph/GraphNode.cc
        src/Graph/GraphVedge.cc
        src/Graph/GraphAttribute.cc
        )

set_target_properties(LibDataStructures PROPERTIES PREFIX "")
target_include_directories(LibDataStructures PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
