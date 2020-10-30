FILES = *.c
FLAGS = -Wall -Wextra -Werror
NAME = libft.a

all:		$(NAME)

$(NAME):
			gcc -c $(FILES) $(FLAGS)
			ar rc $(NAME) ft*.o

clean:
			rm -f ./*.o

fclean:		clean
			rm -f $(NAME) 

re:			fclean all

.PHONY:		all clean fclean re