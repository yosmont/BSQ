/*
** EPITECH PROJECT, 2017
** ls
** File description:
** lsd
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "../include/BSQ.h"

int bsq_line_len(char *str)
{
	int len = 0;

	while (str[len] != '\n')
		len++;
	return(len);
}

int check_square(char *str, int size, t_rectsize bsq, int pos)
{
	for(int j = 0; j <= size; j++)
		for(int i = 0; i <= size; i++)
			if (str[pos + i + j * (bsq.width + 1)] != '.')
				return(1);
	return(0);
}

int getsize(int i, char *str, t_rectsize bsq)
{
	int size = 1;

	while(check_square(str, size, bsq, i) != 1) {
		size++;
	}
	return(size);
}

t_possize found_the_big_one(char *str, t_rectsize bsq)
{
	t_possize biggest;
	t_possize tmp;

	biggest.size = 0;
	for(int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '.') {
			tmp.pos = i;
			tmp.size = getsize(i, str, bsq);
			if (tmp.size > biggest.size)
				biggest = tmp;
		}
	}
	return(biggest);
}

int main(int ac, char **av)
{
	char *file;
	int fd;
	int size;
	t_rectsize bsq;
	t_possize biggest;
	struct stat buf;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return(84);
	stat(av[1], &buf);
	file = malloc(sizeof(char) * (long)(long)buf.st_size);
	size = read(fd, file, (long)(long)buf.st_size);
	bsq.height = my_getnbr(file);
	for (char c = file[0]; c != '\n'; file++, size--)
		c = file[0];
	biggest = found_the_big_one(file, bsq);
	bsq.width = bsq_line_len(file);
	if (biggest.size == 0) {
		write(1, file, size);
		return(0);
	}
	for(int j = 0; j < biggest.size; j++)
		for(int i = 0; i < biggest.size; i++)
			file[biggest.pos + i + j * (bsq.width + 1)] = 'x';
	write(1, file, size);
	return(0);
}
