NAME	= so_long.a
CC		= gcc
CFLAGS	= -Wextra -Wall -Werror
LIBFT	= libft/libft.a
MAKE_LIBFT	= @make -C libft

SRC	= $(shell find src -type f -name "*.c")
OBJ	= ${SRC:.c=.o}

all: $(NAME)

$(LIBFT):
	$(MAKE_LIBFT)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar crs $@ $^

clean:
	rm -rf $(OBJ)
	$(MAKE_LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE_LIBFT) fclean

re: clean all
	$(MAKE_LIBFT) re

.PHONY: all, clean, fclean, re