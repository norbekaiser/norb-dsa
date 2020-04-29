cmake_minimum_required(VERSION 3.16)
project(example-Dijkstra CXX)
add_executable(example-Dijkstra main.cc)
target_link_libraries(example-Dijkstra libnorb-dsa)
