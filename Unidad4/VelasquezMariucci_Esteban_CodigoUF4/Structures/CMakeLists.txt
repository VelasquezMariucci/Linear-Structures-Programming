cmake_minimum_required(VERSION 3.29)
project(Structures)

set(CMAKE_CXX_STANDARD 23)

add_executable(Structures main.cpp
        LinkedList.h
        Stack_LinkedList.h
        DoubleLinkedList.h
        BinaryTree_DoubleLinkedList.h
        Queue_LinkedList.h)
