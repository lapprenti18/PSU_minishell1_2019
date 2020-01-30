/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "my.h"

int str_ncmp(char *str, char *str2)
{
    int temp = 0;

    for (; str[temp]; temp += 1) {
        if (str[temp] != str2[temp])
            return (0);
    }
    return (1);
}

int str_ncmp_spe(char *str, char *str2)
{
    int temp = 0;

    for (; str[temp]; temp += 1) {
        if (str[temp] != str2[temp])
            return (0);
    }
    if (str2[temp] != '\0' && str2[temp] != ' ') {
        if (str2[temp] != '\n')
            return (0);
    }
    return (1);
}