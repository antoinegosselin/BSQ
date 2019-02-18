/*
** EPITECH PROJECT, 2018
** check_functions.c
** File description:
** check functions
*/

#include <stdlib.h>

void check_open(int fd)
{
    if (fd == -1)
        exit(84);
}

void check_read(int read_val)
{
    if (read_val <= 0)
        exit(84);
}