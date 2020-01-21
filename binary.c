/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "my.h"

char **search_path(env_t *new_env)
{
    int temp = 0;
    char **path;

    if (new_env->good_env[0] == NULL)
        return (NULL);
    for (; new_env->good_env[temp] && str_ncmp("PATH=", \
new_env->good_env[temp]) != 1; temp += 1);
    if (new_env->good_env[temp] == NULL)
            return (NULL);
    path = my_str_to_word_array_path(new_env->good_env[temp]);
    return (path);
}

void exection(char *cmd, env_t *new_env, char **command)
{
    pid_t pid;

    pid = fork();
    if (pid == 0){
        execve(cmd, command, new_env->good_env);
        exit (84);
    } else {
        wait(&pid);
        if (pid > 130 && pid < 140) {
            my_putstr("Segmentation fault", 0, 1);
            return;
        }
    }
}

void print_error(char **cmd)
{
    if (errno == 13)
        my_putstr(cat(cmd[0], ": Permission denied."), 0, 1);
    if (errno == 2)
        my_putstr(cat(cmd[0], ": Command not found."), 0, 1);
    if (errno == ENOEXEC)
        my_putstr(cat(cmd[0], ": Exec format err\
        or. Wrong Architecture."), 0, 1);
}

void no_trace(env_t *new_env, char **cmd)
{
    pid_t pid;

    pid = fork();
    if (pid == 0){
        execve(cmd[0], cmd, new_env->good_env);
        print_error(cmd);
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

void go_fork(env_t *new_env, char **cmd)
{
    char **path = search_path(new_env);
    int acces = 0;
    int temp;

    if (!cmd[0])
        return;
    if (path == NULL) {
        my_putstr(cat(cmd[0], ": Command not found."), 0, 1);
        return;
    }
    if (cmd[0][0] == '/')
        return (no_trace(new_env, cmd));
    for (temp = 1; path[temp]; temp += 1) {
        if ((acces = access(cat(cat(path[temp], "/"), cmd[0]), X_OK)) == 0)
            break;
    }
    if (acces == 0)
        exection(cat(cat(path[temp], "/"), cmd[0]), new_env, cmd);
    else
        my_putstr(cat(cmd[0], ": Command not found."), 0, 1);
}