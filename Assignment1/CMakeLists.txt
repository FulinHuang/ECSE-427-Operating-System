cmake_minimum_required(VERSION 3.14)
project(Assignment1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Assignment1 shell.c interpreter.c shellmemory.c)