SRC =	c_flag.c ft_printf.c i_flag.c min_flag.c min_flag2.c p_flag.c point_flag.c \
	s_flag.c solve_int_precision.c star_flag.c utils.c utils2.c uxper_flag.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I./

NAME = libftprintf.a 

$(NAME): $(SRC) printf.h
	gcc $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME) libftprintf.a

all: $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
