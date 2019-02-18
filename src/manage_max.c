/*
** EPITECH PROJECT, 2018
** manage_max.c
** File description:
** manage_max.c
*/

#include "my.h"
#include "bsq.h"
#include "check_malloc.h"

max_t init_max(void)
{
    max_t max;

    max.value = 0;
    max.x = -1;
    max.y = -1;
    return (max);
}

max_t get_max_pos(int **int_array, int nb_line)
{
    max_t max = init_max();
    int lines_parsed = 0;

    for (int count = 0; lines_parsed < nb_line; count++) {
        if (int_array[lines_parsed][count] == -1) {
            count = -1;
            lines_parsed++;
        }
        else if (int_array[lines_parsed][count] > max.value) {
            max.value = int_array[lines_parsed][count];
            max.x = count;
            max.y = lines_parsed;
        }
    }
    return (max);
}