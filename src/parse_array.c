/*
** EPITECH PROJECT, 2018
** parse_array.c
** File description:
** parse the arrays
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "bsq.h"
#include "check_malloc.h"

int **malloc_int_array(int nb_line, int nb_col)
{
    int **int_array = check_malloc_int_array(nb_line);

    for (int count = 0; count < nb_line; count++)
        int_array[count] = check_malloc_int(nb_col + 1);
    return (int_array);
}

char **parse_array_end(int **int_array, char **array, int nb_line)
{
    int lines_parsed = 0;

    for (int count = 0; lines_parsed < nb_line; count++) {
        if (int_array[lines_parsed][count] == 0)
            array[lines_parsed][count] = 'o';
        if (int_array[lines_parsed][count] >= 1)
            array[lines_parsed][count] = '.';
        if (int_array[lines_parsed][count] == -1) {
            array[lines_parsed][count] = '\n';
            lines_parsed++;
            count = -1;
        }
    }
    array[lines_parsed] = 0;
    return (array);
}

static int check_error(char **array, int lines_parsed, int count)
{
    int nb = 0;

    if (array[lines_parsed][count] != '.')
        nb++;
    if (array[lines_parsed][count] != 'o')
        nb++;
    if (array[lines_parsed][count] != '\n')
        nb++;
    if (nb == 3) {
        write(2, "Syntax error\n", 13);
        exit(84);
    }
    return (nb);
}

int **parse_array_first(char **array, int nb_line, int nb_col)
{
    int lines_parsed = 0;
    int **int_array = malloc_int_array(nb_line, nb_col);

    for (int count = 0; lines_parsed < nb_line; count++) {
        if (check_error(array, lines_parsed, count) == 3)
            exit(84);
        if (array[lines_parsed][count] == '.')
            int_array[lines_parsed][count] = 1;
        if (array[lines_parsed][count] == 'o')
            int_array[lines_parsed][count] = 0;
        if (array[lines_parsed][count] == '\n') {
            int_array[lines_parsed][count] = -1;
            lines_parsed++;
            count = -1;
        }
    }
    return (int_array);
}