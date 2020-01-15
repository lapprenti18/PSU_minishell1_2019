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

char **search_home(char **env)
{
    int temp = 0;
    char **path;
    int boool = 0;

    for (int temp = 0; env[temp]; temp += 1) {
        if (str_ncmp("HOME=", env[temp]))
            boool = 1;
    }
    if (boool == 0)
        return (NULL);
    for (; (str_ncmp("HOME=", env[temp]) != 1); temp += 1);
    path = my_str_to_word_array_path(env[temp]);
    return (path);
}

int just_cd(char **env, last_line_t *last_line)
{
    char **home = search_home(env);

    if (home == NULL) {
        my_putstr("cd: No home directory.", 0, 1);
        return (0);
    }
    my_memset(last_line->line, 9999);
    getcwd(last_line->line, 9999);
    chdir(home[1]);
    return (0);
}

void cd_jsp(char **cd, char **env, int temp, last_line_t *last_line) 
{
    if (temp > 2)
        my_putstr("cd: Trop d'arguments.", 0, 1);
    if (cd[1][0] == '~' || temp == 1)
        just_cd(env, last_line);
}

int cd_moin(char **env, last_line_t *last_line)
{
    if (last_line->line == NULL) {
        return(just_cd(env, last_line));
    } else {
        chdir(last_line->line);
    }
}

int just_cd_argv(char **cd, char **env, last_line_t *last_line)
{
    int temp;
    int error = 0;

    for (temp = 0; cd[temp]; temp += 1);
    if (temp == 1) {
        just_cd(env, last_line);
        return (0);
    }
    cd_jsp(cd, env, temp, last_line);
    if (cd[1][0] == '-')
        return (cd_moin(env, last_line));
    if (temp == 2 && cd[1][0] != '~') {
        my_memset(last_line->line, 9999);
        getcwd(last_line->line, 9999);
        error = chdir(cd[1]);
        if (error == -1)
            perror("error");
    }
    return (0);
}

int my_cd(char *cmd, char **env, last_line_t *last_line)
{
    if (str_cmp("cd\n", cmd) == 1)
        return (just_cd(env, last_line));
    if (str_ncmp("cd ", cmd) == 1)
        return (just_cd_argv(my_str_to_word_array(cmd), env, last_line));
    else {
        cmd[my_strlen(cmd) - 1] = '\0';
        my_putstr(cat(cmd, ": Commande introuvable."), 0, 1);
    }
}

int no_bin(char **env, char *cmd, last_line_t *last_line)
{
    if (str_cmp("exit\n", cmd) == 1)
        return (-1);
    if (str_cmp("env\n", cmd) == 1)
        return (display_env(env));
    if (str_ncmp("cd", cmd) == 1) {
        my_cd(cmd, env, last_line);
        return (0);
    }
    return (2);
}