/*
** EPITECH PROJECT, 2018
** manage_square.c
** File description:
** manage the square stuct to get the min
*/

#include "my.h"
#include "bsq.h"
#include "check_malloc.h"

square_t set_square(int **int_array, int lines_parsed, int count)
{
    square_t square;

    square.top_left = int_array[lines_parsed - 1][count - 1];
    square.top_right = int_array[lines_parsed - 1][count];
    square.bot_left = int_array[lines_parsed][count - 1];
    return (square);
}

int find_min(square_t square)
{
    int min = square.top_left;

    if (square.top_right < min)
        min = square.top_right;
    if (square.bot_left < min)
        min = square.bot_left;
    return (min);
}

char **replace_with_square(char **array, max_t max)
{
    int min_x = max.x - max.value + 1;
    int min_y = max.y - max.value + 1;

    for (; min_y <= max.y; min_y++) {
        for (;min_x <= max.x; min_x++) {
            array[min_y][min_x] = 'x';
        }
        min_x = max.x - max.value + 1;
    }
    return (array);
}