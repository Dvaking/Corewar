/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-killian.trouve
** File description:
** dante
*/

#ifndef ASM
    #define ASM
    #define OK 0
    #define KO 84
    #include <stdio.h>
    #include "my_str.h"
    #include "op.h"
    #include "asm_structures.h"

    int nb_tok(char const *str, char const *tok);
    int tok_size(char const *str, char const *tok);
    int is_in_str(char const c, char const *str);
    char **my_strtok(char const *str, char const *tok);
    int help(void);
    char *create_the_name_of_the_new_file(char const* arg);
    int asm_launcher(char const *arg);
    int generate_a_bytecode_file(char const* arg);
    int get_the_extension_of_the_file(char const* arg);
    char *exa_convert(int c, int byte_nb);
    int get_function_code(char *function);
    int get_coding_byte(char **args);
    void byte_cpy(char *str, int nb_bytes, int bytes);
    int get_arg_bytes(char **args, int cap, FILE *file);
    int binary_to_deci(int binary);
    int convert_body(char *filename, char const* arg);
    int extract_header_from_file(char const* pathname, header_t *file_infos);
    int write_header_in_file(char const* arg, int calculated_prog_size,
    char *name_of_the_file);
    int endian_conversion(int nb_to_convert);
    void free_tab(char **tab);
    char *my_free_strcpy (char *dest, char *src);
    int get_nb_bytes(body_t *body, int command);
    int need_coding_byte(int command);
    int is_char(char c);
    int need_cap(int command);
    char *get_input(FILE *file, char *input);


#endif /* !ASM */
