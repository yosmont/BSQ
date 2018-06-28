/*
** EPITECH PROJECT, 2017
** lmkjdsf
** File description:
** lkjdsqmf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>

void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(printf, simple_string, .init = redirect_all_std)
{
	write(1, "Hello world", 11);
	cr_assert_stdout_eq_str("Hello world");
	//list = list->next;
	//cr_assert_eq_str(list->void, "hello");
}
