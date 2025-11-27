cmake_minimum_required(VERSION 3.25)


project(main)


add_executable(main main.cpp)

add_library(bplustree src/tree.cpp src/node.cpp)

include_directories(include)

target_link_libraries(main bplustree)