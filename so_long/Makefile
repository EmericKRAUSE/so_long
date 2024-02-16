NAME		= so_long
CC			= gcc
CFLAGS		= -Wextra -Wall -Werror
INC			= -Iinclude -ldl -lglfw -pthread -lm
MAIN		= main.c
LIBMLX		= MLX42/build/libmlx42.a
LIBFT		= libft/libft.a
MAKE_LIBFT	= @make -C libft

SRC			=	src/display_images/display_down_animation.c\
				src/display_images/display_exit.c\
				src/display_images/display_images.c\
				src/display_images/display_left_animation.c\
				src/display_images/display_map.c\
				src/display_images/display_player.c\
				src/display_images/display_right_animation.c\
				src/display_images/display_trap.c\
				src/display_images/display_ui.c\
				src/display_images/display_up_animation.c\
				src/events/animations/animation_down.c\
				src/events/animations/animation_left.c\
				src/events/animations/animation_right.c\
				src/events/animations/animation_up.c\
				src/events/animations/reset_animation.c\
				src/events/animations/update_trap.c\
				src/events/animations/update_exit.c\
				src/events/collisions/collision_event.c\
				src/events/movements/move_down.c\
				src/events/movements/move_left.c\
				src/events/movements/move_right.c\
				src/events/movements/move_up.c\
				src/game_state/game_lose.c\
				src/game_state/game_win.c\
				src/hooks/hook_close.c\
				src/hooks/hook_collision.c\
				src/hooks/hook_movement.c\
				src/hooks/hook_time.c\
				src/init_images/init_down_animation.c\
				src/init_images/init_image_exit.c\
				src/init_images/init_image_map.c\
				src/init_images/init_image_player.c\
				src/init_images/init_image_trap.c\
				src/init_images/init_image_ui.c\
				src/init_images/init_images.c\
				src/init_images/init_left_animation.c\
				src/init_images/init_right_animation.c\
				src/init_images/init_up_animation.c\
				src/init_other/init_player.c\
				src/init_other/init_time.c\
				src/parsing/create_map.c\
				src/parsing/fill_map.c\
				src/parsing/free_map.c\
				src/parsing/get_map_size.c\
				src/parsing/get_position.c\
				src/parsing/init_map.c\
				src/parsing/map_parser.c\
				src/parsing/path_is_valid.c\
				src/resize_images/resize_image_exit.c\
				src/resize_images/resize_image_map.c\
				src/resize_images/resize_image_player.c\
				src/resize_images/resize_image_trap.c\
				src/resize_images/resize_image_ui.c\
				src/resize_images/resize_images.c\
				src/utils.c
				
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