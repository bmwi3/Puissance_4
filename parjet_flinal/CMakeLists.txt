cmake_minimum_required(VERSION 3.19)
project(parjet_flinal C)

set(CMAKE_C_STANDARD 99)

add_executable(parjet_flinal main.c fonction.c fonction.h fct_save.c fct_save.h grid.c grid.h fonction_check.c fonction_check.h)