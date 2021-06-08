cmake_minimum_required(VERSION 3.17)
project(projet_ifb_bergelin_herbillon_giner C)

set(CMAKE_C_STANDARD 99)

add_executable(projet_ifb_bergelin_herbillon_giner main.c fct_save.c fct_save.h fct_check.c fct_check.h grid.c grid.h affichage.c affichage.h mecanisme_jeu.c mecanisme_jeu.h)