NAME		= so_long
CC			= gcc
CFLAGS		= -Wextra -Wall -Werror
INC			= -Iinclude -ldl -lglfw -pthread -lm
MAIN		= main.c
LIBMLX		= MLX42/build/libmlx42.a
LIBFT		= libft/libft.a
MAKE_LIBFT	= @make -C libft

SRC	= $(shell find src -type f -name "*.c")
OBJ	= ${SRC:.c=.o}

all: $(NAME)

$(LIBFT):
	$(MAKE_LIBFT)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(MAIN) $(OBJ) $(LIBFT) $(LIBMLX) $(INC) -o $(NAME)

clean:
	rm -rf $(OBJ)
	$(MAKE_LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE_LIBFT) fclean

re: fclean all
	$(MAKE_LIBFT) re

.PHONY: all, clean, fclean, re