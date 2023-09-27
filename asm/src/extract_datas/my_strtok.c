/*
** EPITECH PROJECT, 2022
** my_strtok
** File description:
** splits a str into toks
*/
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "asm.h"
#include "my_str.h"

char **my_strtok(char const *str, char const *tok)
{
    int d = 0;
    int i = 0;
    int tok_len = 0;
    char **dest = malloc(sizeof(char *) * (nb_tok(str, tok) + 1));
    if (dest == NULL)
        return (NULL);
    int len = my_strlen(str);
    while (i < len) {
        tok_len = tok_size(&str[i], tok);
        if (tok_len > 0) {
            dest[d] = malloc(sizeof(char) * (tok_len + 1));
            my_strncpy(dest[d], &str[i], tok_len);
            dest[d][tok_len] = '\0';
            d++;
        }
        i = i + tok_len + 1;
    }
    dest[nb_tok(str, tok)] = NULL;
    return (dest);
}
