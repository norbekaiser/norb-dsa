cmake_minimum_required(VERSION 3.16)
project(libnorb-dsa CXX)
add_library(libnorb-dsa INTERFACE)
target_sources(libnorb-dsa INTERFACE
        inc/Graph/DepthFirstSearch.hh
        inc/Graph/DepthFirstSearchStorage.hh
        inc/Graph/DepthFirstSearchVisit.hh
        inc/Graph/Dijkstra.hh
        inc/Graph/Graph.hh
        inc/Graph/GraphNode.hh
        inc/Graph/GraphVedge.hh
        inc/Graph/TopologicalSort.hh
        )

target_include_directories(libnorb-dsa INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_compile_features(libnorb-dsa INTERFACE cxx_std_20)

add_subdirectory(examples)