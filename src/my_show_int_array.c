/*
** EPITECH PROJECT, 2018
** my_show_int_array.c
** File description:
** display an array of int
*/

#include "my.h"

void my_show_int_array(int **array, int size)
{
    for (int count = 0; count < size; count++) {
        for (int i = 0; array[count][i] != -1; i++)
            my_put_nbr(array[count][i]);
        my_putchar('\n');
    }
    my_putchar('\n');
}