cmake_minimum_required(VERSION 3.14)
project(Assignment3 C)

set(CMAKE_C_STANDARD 99)


add_executable(Assignmen3 shell.c interpreter.c shellmemory.c ram.c pcb.c kernel.c cpu.c memorymanager.c)