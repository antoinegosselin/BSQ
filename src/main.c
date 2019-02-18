/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main of bsq
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "bsq.h"
#include "check_malloc.h"

int **set_array(int **int_array, int nb_line)
{
    int lines_parsed = 1;
    int min;
    square_t square;

    for (int count = 1; lines_parsed < nb_line; count++) {
        if (int_array[lines_parsed][count] == -1) {
            lines_parsed++;
            count = 0;
        }
        else if (int_array[lines_parsed][count] == 0)
            int_array[lines_parsed][count] = 0;
        else {
            square = set_square(int_array, lines_parsed, count);
            min = find_min(square);
            int_array[lines_parsed][count] = min + 1;
        }
    }
    return (int_array);
}

char *array_to_str(char **array, int nb_line, int nb_col)
{
    char *str = malloc(sizeof(char) * (nb_line * (nb_col + 1) + 2));
    int count = 0;

    for (int i = 0; i < nb_line; i++) {
        for (int j = 0; array[i][j] != '\0'; j++) {
            str[count] = array[i][j];
            count++;
        }
    }
    str[count] = '\0';
    return (str);
}

void print_square(char **array, int **int_array, int nb_line, int nb_col)
{
    max_t max = get_max_pos(int_array, nb_line);
    char *str;

    array = parse_array_end(int_array, array, nb_line);
    if (max.value > 0)
        array = replace_with_square(array, max);
    str = array_to_str(array, nb_line, nb_col);
    write(1, str, my_strlen(str));
    free(str);
}

void do_actions(char **array, int nb_line, int nb_col)
{
    int **int_array;

    int_array = parse_array_first(array, nb_line, nb_col);
    int_array = set_array(int_array, nb_line);
    print_square(array, int_array, nb_line, nb_col);
    my_free_char_array(array, nb_line + 1);
    my_free_int_array(int_array, nb_line);
}

int main(int ac, char **av)
{
    char *buffer;
    char *str;
    char **array;
    int nb_line;
    int nb_col;

    if (ac != 2) {
        write(2, "Wrong number of arguments\n", 26);
        exit(84);
    }
    buffer = my_file_readall(av[1]);
    str = my_strdup(buffer + my_line_len(buffer) + 1);
    free(buffer);
    nb_line = count_line(str);
    nb_col = my_line_len(str);
    array = my_str_to_str_array(str);
    do_actions(array, nb_line, nb_col);
    free(str);
    return (0);
}