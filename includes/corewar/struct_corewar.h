/*
** EPITECH PROJECT, 2023
** CoreWar
** File description:
** struct_corewar
*/

#ifndef STRUCT_COREWAR_H_
    #define STRUCT_COREWAR_H_
    #include "struct_corewar.h"
    #include "linked_list.h"

    typedef struct coding_byte_s {
        char opt1[3];
        char opt2[3];
        char opt3[3];
        char opt4[3];
    } coding_byte_s_t;
    typedef struct game_parameter_s{
        int len_cycle_to_die;
        int nbr_live;
        int dump;
        int champ_live;
    } game_parameter_s_t;

    typedef struct base_vm_s {
        game_parameter_s_t game_info;
        list_t *champ;
    } base_vm_s_t;

    typedef struct need_parcers_s {
        int last_flag;
        int id_champ;
        int new_champ;
        int champ_create;
    }need_parcers_s_t;

    struct command_function {
        int command;
        int (*proto)(base_vm_s_t *base_vm, list_t *champ, int *map);
    };


    struct function {
        char *str;
        int (*proto)(base_vm_s_t *base_vm, need_parcers_s_t *need_parcers,\
        char const *const *av, int *i);
    };

#endif /* !STRUCT_COREWAR_H_ */
