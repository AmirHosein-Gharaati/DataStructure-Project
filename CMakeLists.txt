cmake_minimum_required(VERSION 3.17)
project(DS_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(DS_Project main.cpp Library/AVL.cpp Library/AVL.h Library/Node.cpp Library/Node.h Library/Queue.cpp Library/Queue.h Library/MainDataStructure.cpp Library/MainDataStructure.h)