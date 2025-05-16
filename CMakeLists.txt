cmake_minimum_required(VERSION 3.30)
project(Projeto_SUS C)

set(CMAKE_C_STANDARD 11)

add_executable(Projeto_SUS main.c
        cadastrar.c
        cadastrar.h
        structs.h)
