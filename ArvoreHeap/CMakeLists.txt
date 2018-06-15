cmake_minimum_required(VERSION 3.10)
project(ArvoreHeap C)

set(CMAKE_C_STANDARD 99)

add_executable(ArvoreHeap main.c Arvheap.h Arvheap.c)