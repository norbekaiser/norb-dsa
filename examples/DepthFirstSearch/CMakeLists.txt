cmake_minimum_required(VERSION 3.16)
project(example-DepthFirstSearch CXX)
add_executable(example-DepthFirstSearch main.cc)
target_link_libraries(example-DepthFirstSearch libnorb-dsa)
