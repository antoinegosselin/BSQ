/*
** EPITECH PROJECT, 2018
** read_functions.c
** File description:
** read an entire file and put it in an str
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "bsq.h"
#include "check_malloc.h"

void my_error(char const *filepath)
{
    write(2, "bsq: ", 5);
    write(2, filepath, my_strlen(filepath));
    write(2, ": No such file\n", 15);
}

int my_char_is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

void check_error(char *buffer, int nb_line)
{
    int nb = 0;

    for (int count = 0; buffer[count] != '\n'; count++) {
        if (my_char_is_num(buffer[count]) == 0)
            exit(84);
        nb = nb * 10 + buffer[count] - '0';
    }
    if (nb != nb_line)
        exit(84);
}

char *my_file_readall(char const *filepath)
{
    struct stat stats;
    int fd;
    int read_val;
    int nb_line;
    int size;
    char *buffer;

    fd = open(filepath, O_RDONLY);
    check_open(fd);
    read_val = stat(filepath, &stats);
    size = stats.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    read_val = read(fd, buffer, size);
    check_read(read_val);
    nb_line = count_line(buffer) - 1;
    check_error(buffer, nb_line);
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}