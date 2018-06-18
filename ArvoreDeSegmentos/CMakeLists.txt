cmake_minimum_required(VERSION 3.10)
project(ArvoreDeSegmentos C)

set(CMAKE_C_STANDARD 99)

add_executable(ArvoreDeSegmentos main.c SegLazy.h SegLazy.c)