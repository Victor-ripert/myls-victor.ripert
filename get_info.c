/*
** EPITECH PROJECT, 2024
** my_ls
** File description:
** act like ls command with alRdrt flags
*/
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "my_ls.h"

static char *get_permission_type(mode_t st_mode)
{
    char *perm = my_str_dup("----------");

    if (S_ISDIR(st_mode)) {
        perm[0] = 'd';
    }
    if (S_ISCHR(st_mode)) {
        perm[0] = 'c';
    }
    if (S_ISBLK(st_mode)) {
        perm[0] = 'b';
    }
    return perm;
}

static char *get_permission_usr(mode_t st_mode)
{
    char *perm = get_permission_type(st_mode);

    if (st_mode & S_IRUSR) {
        perm[1] = 'r';
    }
    if (st_mode & S_IWUSR) {
        perm[2] = 'w';
    }
    if (st_mode & S_IXUSR) {
        perm[3] = 'x';
    }
    return perm;
}

static char *get_permission_grp(mode_t st_mode)
{
    char *perm = get_permission_usr(st_mode);

    if (st_mode & S_IRGRP) {
        perm[4] = 'r';
    }
    if (st_mode & S_IWGRP) {
        perm[5] = 'w';
    }
    if (st_mode & S_IXGRP) {
        perm[6] = 'x';
    }
    return perm;
}

static char *get_permission_oth(mode_t st_mode)
{
    char *perm = get_permission_grp(st_mode);

    if (st_mode & S_IROTH) {
        perm[7] = 'r';
    }
    if (st_mode & S_IWOTH) {
        perm[8] = 'w';
    }
    if (st_mode & S_IXOTH) {
        perm[9] = 'x';
    }
    return perm;
}

char *uid_to_str(uid_t usr_id)
{
    struct passwd *pwd;
    char *name;

    pwd = getpwuid(usr_id);
    name = my_str_dup(pwd->pw_name);
    return name;
}

char *gid_to_str(gid_t grp_id)
{
    struct group *grp;
    char *name;

    grp = getgrgid(grp_id);
    name = my_str_dup(grp->gr_name);
    return name;
}

char *del_last_char(char *str)
{
    char *result = my_str_dup(str);

    result[my_strlen(str) - 1] = '\0';
    return result;
}

void get_info(lk_list_t **begin, param_t *params)
{
    struct stat sb;
    lk_list_t *temp;

    temp = (*begin);
    while (temp != NULL) {
        stat(temp->info->path, &sb);
        temp->info->permission = get_permission_oth(sb.st_mode);
        temp->info->nb_link = sb.st_nlink;
        temp->info->owner = uid_to_str(sb.st_uid);
        temp->info->group = gid_to_str(sb.st_gid);
        temp->info->size = sb.st_size;
        temp->info->modi = my_str_dup(del_last_char(ctime(&sb.st_mtime)));
        temp->info = temp->info;
        temp = temp->next;
    }
}
