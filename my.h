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
#include <signal.h>

typedef struct last_line_s
{
    char *line;
} last_line_t;


void my_putstr(char *str, int space, int slash);
int my_strlen(char *str);
char *cat(char *start, char *line);
int no_bin(char **env, char *cmd, last_line_t *last_line);
int str_cmp(char *str, char *str2);
char **my_str_to_word_array_path(char *str);
char **my_str_to_word_array(char *str);
void display_prompt(void);
void go_fork( char **env, char **cmd);
int str_ncmp(char *str, char *str2);
char *str_cpy(char *str);
char *my_memset(char *str, int size);