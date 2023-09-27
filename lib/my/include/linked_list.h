/*
** EPITECH PROJECT, 2023
** LIB
** File description:
** linked_list
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_

    #include "op.h"
    #include <stdbool.h>

    typedef struct champ_param_s{
        int time_off;
        int command;
        int pc;
        int carry;
        int regist[REG_NUMBER];
    }champ_param_s_t;

    typedef struct info_champ_s{
        int nbr_prog;
        int load_mem;
        int cycle_to_die;
        char *prog_body;
        bool is_alive;
    } info_champ_s_t;

    typedef struct list_s{
        info_champ_s_t info_champ;
        header_t header;
        champ_param_s_t champ_param;
        struct list_s *next;
        struct list_s *previous;
    } list_t;

#endif /* !LINKED_LIST_H_ */
