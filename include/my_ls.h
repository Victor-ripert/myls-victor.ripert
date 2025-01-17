/*
** EPITECH PROJECT, 2024
** flags.h
** File description:
** flags structure & functions for my_printf
*/

#ifndef MY_LS_H
    #define MY_LS_H

typedef struct info_s {
    char *path;
    char *file;
    char *permission;
    char *modi;
    int nb_link;
    char *owner;
    char *group;
    int size;
} info_t;

typedef struct linked_list_s {
    struct linked_list_s *previous;
    info_t *info;
    struct linked_list_s *next;
} lk_list_t;

typedef struct flags_param_s {
    char flag;
    int present;
} param_t;

int my_ls(int agrc, char **argv);
int my_strcmp(char *str_1, char *str_2);
void ls_flags(int argc, char **argv, param_t **params);
void push_to_list(lk_list_t **begin, lk_list_t *node);
void files_to_list(int argc, char **argv, lk_list_t **begin, param_t *params);
void display_list(lk_list_t *begin);
void display_list_l(lk_list_t *begin);
void select_sort(lk_list_t **head, int rev);
void swap_in_list(lk_list_t **first_node, lk_list_t **second_node);
void display_args(param_t *params);
lk_list_t *create_node(char *file, char *path);
void get_info(lk_list_t **begin, param_t *params);
char *my_str_dup(char *str);
int my_strlen(char *str);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);

#endif /* MY_LS_H */
