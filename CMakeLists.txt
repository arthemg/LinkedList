cmake_minimum_required(VERSION 3.6)
project(SinglyLinkedList)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp list.cpp list.h)
add_executable(SinglyLinkedList ${SOURCE_FILES})