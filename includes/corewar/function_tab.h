/*
** EPITECH PROJECT, 2023
** tab_funciton
** File description:
** all tab function
*/

#ifndef TAB_FUNCTION
    #define TAB_FUNCTION

    typedef struct my_commands_t {
        char const* command_reg;
        int(*tab)(char *command_user);
    }my_commands_s;

    const my_commands_s FUNCTION_TAB[] = {
        {command_reg : "live", &live_command},
        {command_reg : "ld", &ld_command},
        {command_reg : "st", &st_command},
        {command_reg : "add", &add_command},
        {command_reg : "sub", &sub_command},
        {command_reg : "and", &and_command},
        {command_reg : "or", &or_command},
        {command_reg : "xor", &xor_command},
        {command_reg : "zjmp", &zjmp_command},
        {command_reg : "ldi", &ldi_command},
        {command_reg : "sti", &sti_command},
        {command_reg : "fork", &fork_command},
        {command_reg : "lld", &lld_command},
        {command_reg : "lldi", &lldi_command},
        {command_reg : "lfork", &lfork_command},
        {command_reg : "aff", &aff_command}
    };

    #define nb_builtin 16

#endif /* !TAB_FUNCTION */
