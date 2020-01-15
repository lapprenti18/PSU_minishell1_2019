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

void main_loop(char **env, last_line_t *last_line)
{
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int no_binary = 0;

    do {
        signal(SIGINT, siginthandler);
        display_prompt();
        if ((read = getline(&line, &len, stdin)) == -1) {
            if (isatty(0))
                my_putstr("exit", 0, 1);
            exit (0);
        }
        no_binary = no_bin(env, line, last_line);
        if (no_binary == 2)
            go_fork(env, my_str_to_word_array(line));
        no_binary = 0;
    } while (read != -1 && no_binary != -1);
}

int main(int ac, char **av, char **env)
{
    last_line_t last_line;

    last_line.line = malloc(sizeof(char) * 9999);
    if (ac != 1)
        return (84);
    main_loop(env, &last_line);
    return (0);
}