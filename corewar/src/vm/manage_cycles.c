/*
** EPITECH PROJECT, 2023
** manage_cycles.c
** File description:
** manage the cycles
*/

#include "corewar.h"
#include "macro.h"
#include "proto_lib_my.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

static int kill_champion(base_vm_s_t *base_vm)
{
    for (list_t *tmp = base_vm->champ; tmp != NULL; tmp = tmp->next) {
        if (tmp->info_champ.cycle_to_die < 1){
            tmp->info_champ.is_alive = false;
            base_vm->game_info.champ_live -= 1;
        }
    }
    return OK;
}

char *int_to_hexa(int nbr)
{
    int len = 0;
    int tmp = nbr;
    for (; tmp != 0; len++) {
        tmp /= 16;
    }
    char *hexa = malloc(sizeof(char) * (len + 1));
    if (hexa == NULL)
        return NULL;
    hexa[len] = '\0';
    for (int i = len - 1; nbr != 0; i--) {
        int j = nbr % 16;
        if (j < 10)
            hexa[i] = j + '0';
        else
            hexa[i] = j + 'A' - 10;
        nbr /= 16;
    }
    return hexa;
}

static void print_first_column(int line_counter, int i)
{
    char *hexa = int_to_hexa(line_counter);

    write(1, "\n", 1);
    if (i + 1 == MEM_SIZE)
        return;
    write(1, hexa, my_strlen(hexa));
    if (line_counter >= 256)
        write(1, "0 : ", 4);
    else if (line_counter >= 16)
        write(1, "0  : ", 5);
    else
        write(1, "0   : ", 6);
    free(hexa);
}

static int display_memory(int *map)
{
    char hexa_chars[] = "0123456789ABCDEF";
    int count = 0;
    int line_counter = 0;
    write(1, "0    : ", 7);
    for (int i = 0; i < MEM_SIZE; i++) {
        if (map[i] == -1)
            write(1, "00", 2);
        else {
            write(1, &hexa_chars[map[i] / 16], 1);
            write(1, &hexa_chars[map[i] % 16], 1);
        }
        count++;
        if (count % 32 == 0) {
            line_counter += 2;
            count = 0;
            print_first_column(line_counter, i);
        } else
            write(1, " ", 1);
    }
    return OK;
}

int update_cycle_to_die(base_vm_s_t *base_vm, int *map)
{
    if (base_vm->game_info.nbr_live > 39){
        base_vm->game_info.len_cycle_to_die -= CYCLE_DELTA;
        base_vm->game_info.nbr_live = 0;
        for (list_t *tmp = base_vm->champ; tmp != NULL; tmp = tmp->next)
            tmp->info_champ.cycle_to_die -= CYCLE_DELTA;
    }
    if (base_vm->game_info.dump > 0)
        base_vm->game_info.dump -= 1;
    if (base_vm->game_info.dump == 0) {
        display_memory(map);
        base_vm->game_info.dump = -1;
    }
    kill_champion(base_vm);
    return OK;
}
