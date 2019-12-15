cmake_minimum_required(VERSION 2.15)
project(Coding)

set(CMAKE_CXX_STANDARD 11)

add_executable(Coding main.cpp src/Solution.cpp include/Solution.h src/ListNodeSolution.cpp include/ListNodeSolution.h src/VectorSolution.cpp include/VectorSolution.h src/TreeNode.cpp include/TreeNode.h src/StingSolution.cpp include/StingSolution.h src/Math.cpp include/Math.h src/Hash.cpp include/Hash.h include/RandomList.h src/RandomList.cpp src/language.cpp include/language.h include/Language/virtual_table.h include/Language/coroutine_jmp.h include/Language/consumer_productor_pthread.h include/Language/consumer_productor_jump.h include/Language/coroutine_ucontext.h)