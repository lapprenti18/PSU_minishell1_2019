/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "my.h"

int display_env(char **env) {
    for (int temp = 0; env[temp]; temp += 1)
        my_putstr(env[temp], 0, 1);
    return (0);
}

int no_bin(char **env, char *cmd)
{
    if (str_cmp("exit\n", cmd) == 1)
        return (-1);
    if (str_cmp("env\n", cmd))
        return (display_env(env) == 1);
    return (2);
}