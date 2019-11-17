cmake_minimum_required(VERSION 2.15)
project(Coding)

set(CMAKE_CXX_STANDARD 11)

add_executable(Coding main.cpp src/Solution.cpp include/Solution.h src/ListNodeSolution.cpp include/ListNodeSolution.h src/VectorSolution.cpp include/VectorSolution.h src/TreeNode.cpp include/TreeNode.h src/StingSolution.cpp include/StingSolution.h)