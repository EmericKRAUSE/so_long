NAME	= so_long
CC		= gcc
CFLAGS	= -Wextra -Wall -Werror
MAIN	= main.c
LIBFT	= libft/libft.a
LIBMLX	= MLX42/build/libmlx42.a
INC		= -Iinclude -ldl -lglfw -pthread -lm
MAKE_LIBFT	= @make -C libft

SRC	= $(shell find src -type f -name "*.c")
OBJ	= ${SRC:.c=.o}

all: $(NAME)

$(LIBFT):
	$(MAKE_LIBFT)

$(NAME): $(LIBFT)
	$(CC) $(MAIN) $(SRC) $(LIBFT) $(LIBMLX) $(INC) -o $(NAME)

clean:
	rm -rf $(OBJ)
	$(MAKE_LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE_LIBFT) fclean

re: clean all
	$(MAKE_LIBFT) re

.PHONY: all, clean, fclean, re