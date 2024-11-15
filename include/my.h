/*
** EPITECH PROJECT, 2024
** flags.h
** File description:
** flags structure & functions for my_printf
*/
#include <dirent.h>
#include <stdbool.h>
#ifndef FILE_H
    #define FILE_H
int my_ls(int argc, char **argv);
typedef struct {
    char flag;
    bool present;
} ls_flag_t;
static ls_flag_t flags_tab[] = {
    {'d', false},
    {'a', false},
    {'R', false},
    {'l', false},
    {'t', false},
    {'r', false},
    {'.', false}
};
typedef struct ls_file {
    char *str;
    char *dir;
    struct ls_file *next;
} ls_file_t;
typedef ls_file_t *node_t;
static int node_size = sizeof(node_t);
node_t create_node();
node_t add_node(node_t head, char *value);
int print_node(ls_file_t *file);
typedef struct ls_info {
    char **tab;
    struct ls_info *next;
} ls_info_t;
typedef ls_info_t *node_info_t;
node_info_t create_node_info();
node_info_t add_node_info(node_info_t head, char **value);
int print_node_info(ls_info_t *file);
int print_node_info_l(ls_info_t *file);
node_t open_files(node_t files);
int files_loop(node_t files, ls_flag_t flags_tab[]);
node_info_t file_info_process(node_t name_files, char *dir_name);
int dir_processing(DIR *dirp, ls_flag_t flags_tab[], char *dir_name);
char *nbr_to_str(int nb);
int my_strlen(char const *str);
node_info_t sort_stocked_info(node_info_t info, ls_flag_t flags_tab[]);
#endif /* FILE_H */
