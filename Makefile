##
## EPITECH PROJECT, 2017
## makefile cat
## File description:
## build the cat
##

CC	=	gcc

OBJ	=	src/my_getnbr.c	\
		src/my_nbrlen.c	\
		src/main.c

RM	=	rm -f

NAME	=	bsq

LIB	=	-lmy -Llib/my/ -Iinclude

COM	=	$(OBJ:.c=.o)

TEST	=	tests/unittest.c

TESTNAM	=	test

TESTFLA	=	-lcriterion -coverage

TESTCOM	=	$(TEST:.c=.o)

all:	$(COM)
	$(CC) -o $(NAME) $(COM) -Iinclude
	make clean

clean:
	$(RM) $(COM)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

test_clean:
		$(RM) $(TESTCOM)

tests_run:	$(TESTCOM)
		$(CC) -o $(TESTNAM) $(TESTCOM) $(TESTFLA)
		make test_clean
		./$(TESTNAM)
