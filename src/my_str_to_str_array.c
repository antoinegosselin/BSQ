/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "check_malloc.h"

static int words_count(char const *str, int str_len)
{
    int words_count = 0;

    for (int i = 0; i < str_len; i++) {
        if (str[i] == '\n')
            words_count++;
    }
    return (words_count);
}

char **my_str_to_str_array(char const *str)
{
    int pos[6] = { 0, 0, 0, 0, 0, 0 };
    int word_count = words_count(str, my_strlen(str));
    char **return_array = check_malloc_char_array(word_count + 1);

    while (pos[3] < word_count) {
        pos[2] = pos[1];
        while (str[pos[1]] != '\n')
            pos[1]++;
        pos[1]++;
        pos[5] = (pos[5] == 0) ? (pos[1] - pos[2] + 1) : pos[5];
        if ((pos[1] - pos[2] + 1) != pos[5])
            exit(84);
        return_array[pos[3]] = check_malloc_char(pos[1] - pos[2] + 1);
        for (pos[4] = 0; pos[2] < pos[1]; pos[4]++) {
            return_array[pos[3]][pos[4]] = str[pos[2]++];
        }
        return_array[pos[3]++][pos[4]] = '\0';
    }
    return_array[pos[3]] = 0;
    return (return_array);
}