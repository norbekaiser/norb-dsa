cmake_minimum_required(VERSION 3.16)
project(example-TopologicalSort CXX)
add_executable(example-TopologicalSort main.cc)
target_link_libraries(example-TopologicalSort libnorb-dsa)
