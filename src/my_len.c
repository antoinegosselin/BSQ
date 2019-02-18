/*
** EPITECH PROJECT, 2018
** my_len.c
** File description:
** length calculators
*/

int my_line_len(char *str)
{
    int len = 0;

    while (str[len] != '\n')
        len++;
    return (len);
}

int count_line(char *str)
{
    int len = 0;

    for (int count = 0; str[count] != '\0'; count++) {
        if (str[count] == '\n')
            len++;
    }
    return (len);
}