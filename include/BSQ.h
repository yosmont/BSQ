/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** BSQ header
*/

typedef struct position_and_size {
	int pos;
	int size;
} t_possize;

typedef struct rectangle_size {
	int width;
	int height;
} t_rectsize;

int bsq_line_len(char *str);
int check_square(char *str, int size, t_rectsize bsq, int pos);
int getsize(int i, char *str, t_rectsize bsq);
t_possize found_the_big_one(char *str, t_rectsize bsq);
t_possize found_the_big_one(char *str, t_rectsize bsq);
int my_getnbr(char const *str);
int my_nbrlen(int nbr);
