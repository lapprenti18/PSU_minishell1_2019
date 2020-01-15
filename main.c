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
    int no_binary = 0;

    do {
        signal(SIGINT, siginthandler);
        display_prompt();
        if ((read = getline(&line, &len, stdin)) == -1) {
            my_putstr("exit", 0, 1);
            exit (0);
        }
        no_binary = no_bin(env, line);
        if (no_binary == 2)
            go_fork(env, my_str_to_word_array(line));
        no_binary = 0;
    } while (read != -1 && no_binary != -1);
}

char **new_env(void)
{
    char **env = malloc(sizeof(char *) * 1);

    env[0] = "PATH=/usr/bin";
    env[1] = NULL;
    return (env);
}

int main(int ac, char **av, char **env)
{
    if (ac != 1)
        return (84);
    main_loop(env);
    return (0);
}