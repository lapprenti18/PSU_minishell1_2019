/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include <stddef.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/sysmacros.h>

typedef struct last_line_s
{
    char *line;
} last_line_t;

typedef struct env_s
{
    char **good_env;
} env_t;

void my_putstr(char *str, int space, int slash);
int my_strlen(char *str);
char *cat(char *start, char *line);
int no_bin(env_t *new_env, char *cmd, last_line_t *last_line);
int str_cmp(char *str, char *str2);
char **my_str_to_word_array_path(char *str);
char **my_str_to_word_array(char *str);
void display_prompt(void);
void go_fork(env_t *new_env, char **cmd);
int str_ncmp(char *str, char *str2);
char *str_cpy(char *str);
char *my_memset(char *str, int size);
char **str_cpy_tab(char **tab);
int my_cd(char *cmd, env_t *new_env, last_line_t *last_line);
int just_cd_argv(char **cd, env_t *new_env, last_line_t *last_line);
int cd_moin(env_t *new_env, last_line_t *last_line);
void cd_jsp(char **cd, env_t *new_env, int temp, last_line_t *last_line);
int just_cd(env_t *new_env, last_line_t *last_line);
int display_env(env_t *new_env);
char **search_home(env_t *new_env);
int tab_lengt(char **tab);
int unsetenv_(env_t *new_env, char *cmd);
void delet_env(env_t *new_env, int incr);
void add_env(env_t *new_env, int incr, char **tab);
int new_environement(env_t *new_env, char **tab);
int setenv_(env_t *new_env, char *cmd);
void segfault(int pid);