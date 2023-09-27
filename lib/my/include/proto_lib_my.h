/*
** EPITECH PROJECT, 2023
** other
** File description:
** proto_lib
*/

#include "linked_list.h"

#ifndef PROTO_LIB_MY_H_
    #define PROTO_LIB_MY_H_

        /* file */
    int overwrite_to_file(char *str, char *filename);
    int write_to_file(char *str, char *filename);
    char *open_file(char const *file);

        /* list */
    list_t *add_node_in_list(list_t *list);
    int print_room_list(list_t *list, char *str);
    list_t *free_list(list_t *list);
    list_t *create_node(void);
    int my_list_len(list_t *list);
    int print_list(list_t *list);

        /* spliter */
    char **my_complexspliter(char const *str, char *separator,
    int nbr_parameter);
    char **my_splitstr(char const *str, int separator);
    char **my_str_to_word_array(char const *str);

        /* str */
    int my_strncmp(char const *s1, char const *s2, int n);
    int my_str_isalpha_num(char const *str, int i);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strcat(char *dest, char const *src);
    int my_all_str_isalpha_num(char const *str);
    int my_str_isalpha(char const *str);
    int my_str_isnum(char const *str);
    char *my_strcpy(char const *src);
    int my_strlen(char const *str);
    int my_putstr(char const *str);
    int my_put_nbr(int nb);
    int my_putchar(char c);

        /* tab */
    char **reduce_tab(char **src, char *str);
    char **tab_generator(int y, int x);
    char **my_tabcpy(char **src);
    int my_tablen(char **tab);

        /* other */
    int char_to_int(char const *str);

#endif /* !PROTO_LIB_H_ */
