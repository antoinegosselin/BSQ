/*
** EPITECH PROJECT, 2018
** free_arrays.c
** File description:
** free my arrays
*/

#include <stdlib.h>

void my_free_char_array(char **array, int size)
{
    for (int count = 0; count < size; count++)
        free(array[count]);
    free(array);
}

void my_free_int_array(int **array, int size)
{
    for (int count = 0; count < size; count++)
        free(array[count]);
    free(array);
}