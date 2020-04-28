cmake_minimum_required(VERSION 3.16)
project(datastructures CXX)
add_library(LibDataStructures
        inc/Graph/DepthFirstSearch.hh
        inc/Graph/DepthFirstSearchVisit.hh
        inc/Graph/Graph.hh
        inc/Graph/GraphAttribute.hh
        inc/Graph/GraphNode.hh
        inc/Graph/GraphVedge.hh
        src/List/List.cc
        src/List/ListNode.cc
        src/List/ListNodeElement.cc
        src/List/ListNodeEnd.cc

        inc/Graph/DepthFirstSearchStorage.hh)

set_target_properties(LibDataStructures PROPERTIES PREFIX "")
target_include_directories(LibDataStructures PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
set_property(TARGET LibDataStructures PROPERTY CXX_STANDARD 20)