/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:01:05 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/15 11:32:50 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

/****
* STRUCT IMAGES */
typedef struct image_map
{
	mlx_texture_t	*texture_background;
	mlx_texture_t	*texture_wall;
	mlx_texture_t	*texture_collectible;
	mlx_texture_t	*texture_exit[4];
	mlx_texture_t	*texture_trap[9];
	mlx_image_t		*image_background;
	mlx_image_t		*image_wall;
	mlx_image_t		*image_collectible;
	mlx_image_t		*image_exit[4];
	mlx_image_t		*image_trap[9];
}					t_image_map;

typedef struct image_player
{
	mlx_texture_t	*texture_character;
	mlx_texture_t	*texture_right_animation[6];
	mlx_texture_t	*texture_left_animation[6];
	mlx_texture_t	*texture_up_animation[6];
	mlx_image_t		*image_character;
	mlx_image_t		*image_right_animation[6];
	mlx_image_t		*image_left_animation[6];
	mlx_image_t		*image_up_animation[6];
}					t_image_player;

typedef struct image_ui
{
	mlx_texture_t	*texture_win;
	mlx_texture_t	*texture_lose;
	mlx_image_t		*image_win;
	mlx_image_t		*image_lose;
}					t_image_ui;

// ************************************** //

typedef struct list_component
{
	struct list_component	*next;
	int						y;
	int						x;
	int						nb;
	char					type;
}							t_list_component;

typedef struct map
{
	char		**tab;
	int			x;
	int			y;
	int			collectible;
	int			trap;
	int			exit;
	int			position;
	char		*component;
}				t_map;

typedef struct player
{
	int	y;
	int	x;
	int	time;
	int	animation;
	int	collectible;
	int	movement;
}		t_player;

/****
* STRUCT ANIMATION */

typedef struct time
{
	int	time;
	int	animation_trap;
	int	animation_exit;
}		t_time;

/****
* STRUCT GAME */
typedef struct game
{
	t_map					map;
	t_player				player;
	t_image_map				image_map;
	t_image_player			image_player;
	t_image_ui				image_ui;
	t_list_component		*list_component;
	t_time					time;
	mlx_image_t				*movement_string;
	int						pixel;
	int						is_over;
}							t_game;

extern t_game			g_game;

/****
* DISPLAY IMAGES */
void				display_exit(mlx_t *mlx, t_game *game);
void				display_images(mlx_t *mlx, t_game *game);
void				display_left_animation(mlx_t *mlx, \
t_game *game, int y, int x);
void				display_map(mlx_t *mlx, t_game *game);
void				display_player(mlx_t *mlx, t_game *game, int y, int x);
void				display_right_animation(mlx_t *mlx, \
t_game *game, int y, int x);
void				display_trap(mlx_t *mlx, t_game *game);
void				display_ui(mlx_t *mlx, t_game *game);
void	display_up_animation(mlx_t *mlx, t_game *game, int y, int x);

/****
* ANIMATIONS */
void				animation_left(void);
void				animation_right(void);
void				animation_up(void);
void				reset_animation(void);
void				update_trap(void);
void				update_exit(void);

/****
* COLLISIONS */
int					collision_event(t_list_component *temp);

/****
* MOVEMENTS */
void				moove_down(void);
void				moove_left(void);
void				moove_right(void);
void				moove_up(void);

/****
* GAME_STATE */
void				game_win(void);
void				game_lose(void);

/****
* HOOKS */
void				hook_close(void *param);
void				hook_collision(void);
void				hook_movement(void *param);
void				hook_trap(void);

/****
* PARSING */
int					create_map(t_map *map);
void				fill_map(t_map *map, char *file);
void				free_map(t_map map);
int					get_map_size(t_map *map, char *file);
int					get_position(t_map flooded_map, char c);
t_map				init_map(void);
t_map				map_parser(char *file);
int					path_is_valid(t_map *map);

/****
* INIT IMAGES */
void				init_image_exit(mlx_t *mlx);
void				init_image_map(mlx_t *mlx);
void				init_image_player(mlx_t *mlx);
void				init_image_trap(mlx_t *mlx);
void				init_image_ui(mlx_t *mlx);
void				init_images(mlx_t *mlx);
void				init_left_animation(mlx_t *mlx);
void				init_right_animation(mlx_t *mlx);
void				init_up_animation(mlx_t *mlx);

/****
* RESIZE IMAGES */
void				resize_image_exit(void);
void				resize_image_map(void);
void				resize_image_player(void);
void				resize_image_trap(void);
void				resize_image_ui(void);
void				resize_images(void);

/****
* UTILS */
void				ft_error(char *str);
int					ft_strcmp(char *s1, char *s2);
int					finder(char *str, char to_find);
t_list_component	*create_node(t_list_component *head, \
int y, int x, char type);
void				print_list(t_list_component *head);
void				free_list(t_list_component **head);

#endif