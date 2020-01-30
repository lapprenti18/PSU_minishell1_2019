/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "my.h"

void er(char *str)
{
    for (int temp = 0; str[temp]; temp += 1) {
        if (str[temp] < '0' || \
        (str[temp] > '9' && str[temp] < 'A') || (str[temp] > 'Z' && \
        str[temp] < 'a' )|| str[temp] > 'z') {
            my_putstr("setenv: Variable name must ", 0, 0); 
            my_putstr("contain alphanumeric characters.", 0, 1);
        }
    }
}