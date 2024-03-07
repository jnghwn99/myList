cmake_minimum_required(VERSION 3.27)
project(myList)

set(CMAKE_CXX_STANDARD 17)

add_executable(myList main.cpp
        mySinglyLinkedList.h
        myDoublyLinkedList.h)
