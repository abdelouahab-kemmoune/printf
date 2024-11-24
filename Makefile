NAME = libftprintf.a
CC = cc
CFLAGS = -Wextra -Werror -Wall
SRC = printf.c ft_copyhexa.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_copyadd.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all