/*
** EPITECH PROJECT, 2023
** asm_structures
** File description:
** asm_structures
*/

#ifndef ASM_STRUCTURES_H_
    #define ASM_STRUCTURES_H_

    typedef struct body_s {
        char *command;
        char **args;
        struct body_s *next;
        struct body_s *previous;
    }body_t;

    body_t *add_at_end(char **args, char *command, body_t *list);
    body_t *get_body(char const *pathname);
    body_t *remove_bottom(body_t *list);
    body_t *remove_body_top(body_t *head);

#endif /* !ASM_STRUCTURES_H_ */
