/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** tmp01
*/


int my_getnbr(char const *str)
{
	int tmp = 0;
	int result = 0;
	int isneg = 0;

	while (str[tmp] != '\0') {
		while (str[tmp] >= 48 && str[tmp] <= 57) {
			result = (result * 10) + (str[tmp] - 48);
			if (str[tmp - 1] == 45)
				isneg = 1;
			if (result == 214748364)
				return(0);
			tmp++;
		}
		if (result != 0) {
			if (isneg == 1)
				result = result * (-1);
			return(result);
		}
		tmp++;
	}
}
