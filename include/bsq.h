/*
** EPITECH PROJECT, 2018
** bsq.h
** File description:
** prototypes from bsq
*/

#ifndef BSQ_H_
#define BSQ_H_

char **my_str_to_str_array(char const *str);
int **malloc_int_array(int nb_line, int nb_col);
int **parse_array_first(char **array, int nb_line, int nb_col);
char **parse_array_end(int **int_array, char **array, int nb_line);
void my_show_int_array(int **array, int size);
typedef struct square_pos_s
{
    int top_left;
    int top_right;
    int bot_left;
} square_t;
typedef struct max_pos_s
{
    int x;
    int y;
    int value;
} max_t;
int **set_array(int **int_array, int nb_line);
int find_min(square_t square);
max_t init_max(void);
square_t set_square(int **int_array, int lines_parsed, int count);
max_t get_max_pos(int **int_array, int nb_line);
char **replace_with_square(char **array, max_t max);
char **parse_array_end(int **int_array, char **array, int nb_line);
void my_free_char_array(char **array, int size);
void my_free_int_array(int **array, int size);
int count_line(char *str);
char *my_file_readall(char const *filepath);
void my_error(char const *filepath);
void do_actions(char **array, int nb_line, int nb_col);
void print_square(char **array, int **int_array, int nb_line, int nb_col);
int my_line_len(char *str);
void check_open(int fd);
void check_read(int read_val);

#endif
