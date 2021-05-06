//
// Created by julie on 05/05/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "fonctions.h"
void logo(void) {
    printf(" ____                                                  _______\n");
    printf("|    |                                                |       |            \n");
    printf("|____|                                                |       |                          \n");
    printf("|         .   ___    ___   ___    ___    ___   ___    |       |                 \n");
    printf("|  |   |  |  |___   |___  |___|  |   |  |     |___    |       |              \n");
    printf("|  |___|  |   ___|   ___| |   |  |   |  |___  |___    |       |                                             \n");
};

void vider_buffer(void)
{
    int c;

    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}


