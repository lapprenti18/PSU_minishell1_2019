/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "my.h"

void siginthandler(int sig_num)
{
    signal(SIGINT, siginthandler);
    my_putstr("\n$>", 0, 0);
}

void main_loop(char **env)
{
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    do {
        signal(SIGINT, siginthandler);
        display_prompt();
        if ((read = getline(&line, &len, stdin)) == -1)
            exit (0);
        if (no_bin(env, line) == 2)
            go_fork(env, my_str_to_word_array(line));
    } while (read != -1 && no_bin(env, line) != -1);
}

int main(int ac, char **av, char **env)
{
    if (ac != 1)
        return (84);
    main_loop(env);
    return (0);
}