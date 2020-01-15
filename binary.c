/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "my.h"

char **search_path(char **env)
{
    int temp = 0;
    char **path;

    if (env[0] == NULL)
        return (NULL);
    for (; str_ncmp("PATH=", env[temp]) != 1; temp += 1) {
        if (env[temp] == NULL)
            return (NULL);
    }
    path = my_str_to_word_array_path(env[temp]);
    return (path);
}

void exection(char *cmd, char **env, char **command)
{
    pid_t pid;

    pid = fork();
    if (pid == 0){
        execve(cmd, command, env);
        exit (84);
    } else {
        wait(&pid);
        if (pid > 130 && pid < 140) {
            my_putstr("Segmentation fault", 0, 1);
            return;
        }
    }
}

void no_trace(char **env, char **cmd)
{
    pid_t pid;

    pid = fork();
    if (pid == 0){
        execve(cmd[0], cmd, env);
        my_putstr(cat(cmd[0], ": Command not found."), 0, 1);
        exit (84);
    } else {
        wait(&pid);
        if (pid > 130 && pid < 140) {
            my_putstr("Segmentation fault", 0, 1);
            return;
        }
    }
    return;
}

void go_fork(char **env, char **cmd)
{
    char **path = search_path(env);
    int acces = 0;
    int temp;

    if (path == NULL) {
        my_putstr(cat(cmd[0], ": Command not found."), 0, 1);
        return;
    }
    if (cmd[0][0] == '/')
        return (no_trace(env, cmd));
    for (temp = 1; path[temp]; temp += 1) {
        if ((acces = access(cat(cat(path[temp], "/"), cmd[0]), X_OK)) == 0)
            break;
    }
    if (acces == 0)
        exection(cat(cat(path[temp], "/"), cmd[0]), env, cmd);
    else {
        my_putstr(cmd[0], 0, 0);
        my_putstr(": Command not found.", 0, 1);
    }
}