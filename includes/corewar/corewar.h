/*
** EPITECH PROJECT, 2023
** CoreWar
** File description:
** corewar
*/

#include "struct_corewar.h"
#ifndef COREWAR_H_
    #define COREWAR_H_
    #include "op.h"

    int transform_big_to_little(int value);
    int check_already_exit(list_t *list, int value, int nbr_or_place);

        /* parcers */
    int check_flag_a(base_vm_s_t *base_vm, need_parcers_s_t *need_parcers,
    char const *const *av, int *i);
    int check_flag_n(base_vm_s_t *base_vm, need_parcers_s_t *need_parcers,
    char const *const *av, int *i);
    int check_flag_dump(base_vm_s_t *base_vm, need_parcers_s_t *need_parcers,
    char const *const *av, int *i);
    int check_flags_and_create_champ(char const *const *av,
    base_vm_s_t *base_vm, need_parcers_s_t *need_parcers, int *i);
    int create_champ(base_vm_s_t *base_vm, char const *const *av, int *i,
    need_parcers_s_t *need_parcers);
    int move_to_end(list_t **list_tmp);
    int parcers(base_vm_s_t *base_vm, char const *const *av);

        /* toolbox */
    int free_all(int *map, base_vm_s_t *base_vm);
    int free_struct(base_vm_s_t *base_vm);
    int help(int ac, char const *const *av);
    int complement(int num, int bits);

        /* vm */
    int check_dump(base_vm_s_t *base_vm, int *map);
    int virtual_machine(char const *const *av);
    int game(base_vm_s_t *base_vm, int *map);
    int execution_command(base_vm_s_t *base_vm, list_t *champ, int *map);
    int update_cycle_to_die(base_vm_s_t *base_vm, int *map);
    int coding_byte_function(int decimal, coding_byte_s_t *coding_byte);
    int move_byte(coding_byte_s_t *coding_byte, int index_or_n);
    int win_case(base_vm_s_t *base_vm);

        /* init */
    int *init_map(base_vm_s_t *champ_list);
    list_t *init_id_champ(list_t *champ_list);
    int get_len_empty(int *map, int i);

        /* command */
    int add_command(base_vm_s_t *base_vm, list_t *champ, int *map);
    int live_command(base_vm_s_t *base_vm, list_t *champ, int *map);
    int replace_value(list_t *champ, int *map, int move, int register_pos);
    int take_register_pos(int decimal);
    int aff_command(base_vm_s_t *base_vm, list_t *champ, int *map);
    int and_command(base_vm_s_t *base_vm, list_t *champ, int *map);
    int fork_command(base_vm_s_t *base_vm, list_t *champ, int *map);
    int ldi_command(base_vm_s_t *base_vm, list_t *champ, int *map);
    int lfork_command(base_vm_s_t *base_vm, list_t *champ, int *map);
    int lld_command(base_vm_s_t *base_vm, list_t *champ, int *map);
    int ld_command(base_vm_s_t *base_vm, list_t *champ, int *map);
    int zjmp_command(base_vm_s_t *base_vm, list_t *champ, int *map);
    int xor_command(base_vm_s_t *base_vm, list_t *champ, int *map);
    int sub_command(base_vm_s_t *base_vm, list_t *champ, int *map);
    int sti_command(base_vm_s_t *base_vm, list_t *champ, int *map);
    int st_command(base_vm_s_t *base_vm, list_t *champ, int *map);
    int or_command(base_vm_s_t *base_vm, list_t *champ, int *map);
    int lldi_command(base_vm_s_t *base_vm, list_t *champ, int *map);

#endif /* !COREWAR_H_ */
