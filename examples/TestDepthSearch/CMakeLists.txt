cmake_minimum_required(VERSION 3.16)
project(example-DFS CXX)
add_executable(example-DFS main.cc)
target_link_libraries(example-DFS libnorb-dsa)
