/*
** EPITECH PROJECT, 2017
** my_nbrlen
** File description:
** sfdsj
*/

int my_nbrlen(int nbr)
{
	int size = 0;

	while(nbr != 0) {
		nbr = nbr / 10;
		size++;
	}
	return(size);
}
