SRC		= ft_printf.c ft_printf_utils.c ft_printf_hexa.c

NAME	= libftprintf.a

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

AR		= ar rcs

OBJ		= $(SRC:.c=.o)

all: $(NAME) move

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	@echo cleaned objects

fclean: clean
	@rm -f $(NAME)
	@echo cleaned all

re: fclean $(NAME)

test:
	gcc *.c && ./a.out
	rm -f ./a/out

move:
	mv $(NAME) ../