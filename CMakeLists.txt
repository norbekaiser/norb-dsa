cmake_minimum_required(VERSION 3.16)
project(datastructures CXX)
add_library(LibDataStructures INTERFACE)
target_sources(LibDataStructures INTERFACE
        inc/Graph/DepthFirstSearch.hh
        inc/Graph/DepthFirstSearchStorage.hh
        inc/Graph/DepthFirstSearchVisit.hh
        inc/Graph/Graph.hh
        inc/Graph/GraphAttribute.hh
        inc/Graph/GraphNode.hh
        inc/Graph/GraphVedge.hh
        inc/Graph/ToplogicalSort.hh
        )

target_include_directories(LibDataStructures INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_compile_features(LibDataStructures INTERFACE cxx_std_20)