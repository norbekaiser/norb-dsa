# Copyright (c) 2020 Norbert Rühl
#
# This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
#
# Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
#
#     1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
#
#     2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
#
#     3. This notice may not be removed or altered from any source distribution.

cmake_minimum_required(VERSION 3.16)
project(libnorb-dsa CXX)
add_library(libnorb-dsa INTERFACE)
target_sources(libnorb-dsa INTERFACE
        inc/Graph/BreadthFirstSearch.hh
        inc/Graph/BreadthFirstSearchStorage.hh
        inc/Graph/DepthFirstSearch.hh
        inc/Graph/DepthFirstSearchStorage.hh
        inc/Graph/DepthFirstSearchVisit.hh
        inc/Graph/Graph.hh
        inc/Graph/GraphEdge.hh
        inc/Graph/GraphNode.hh
        inc/Graph/TraversalColoring.hh
        inc/Graph/TopologicalSort.hh
        )

target_include_directories(libnorb-dsa INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_compile_features(libnorb-dsa INTERFACE cxx_std_20)

add_subdirectory(examples)