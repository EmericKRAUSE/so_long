/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:01:05 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/02 10:36:30 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h> // A ENLEVER //
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
	mlx_texture_t	*texture_exit;
	mlx_texture_t	*texture_trap[5];
	mlx_image_t		*image_background;
	mlx_image_t		*image_wall;
	mlx_image_t		*image_collectible;
	mlx_image_t		*image_exit;
	mlx_image_t		*image_trap[5];
}					t_image_map;

typedef struct image_player
{
	mlx_texture_t	*texture_character;
	mlx_texture_t	*texture_right_animation[5];
	mlx_texture_t	*texture_left_animation[5];
	mlx_image_t		*image_character;
	mlx_image_t		*image_right_animation[5];
	mlx_image_t		*image_left_animation[5];
}					t_image_player;

typedef struct image_ui
{
	mlx_texture_t	*texture_heart_1;
	mlx_texture_t	*texture_inventory;
	mlx_texture_t	*texture_slot;
	mlx_image_t		*image_heart_1;
	mlx_image_t		*image_inventory;
	mlx_image_t		*image_slot;
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
}		t_player;

/****
* STRUCT ANIMATION */

typedef struct trap_animation
{
	int	time;
	int	animation;
}		t_trap_animation;

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
	t_trap_animation		trap_animation;
}							t_game;

extern t_game			g_game;
extern int				g_pixels;
extern int				g_over;

/****
* PARSING */
int		create_map(t_map *map);
void	fill_map(t_map *map, char *file);
void	free_map(t_map map);
int		get_map_size(t_map *map, char *file);
int		get_position(t_map flooded_map, char c);
t_map	init_map(void);
t_map	map_parser(char *file);
int		path_is_valid(t_map *map);

/****
* INIT IMAGES */
void	init_images(mlx_t *mlx, t_game *game);

/****
* DISPLAY IMAGES */
void	display_images(mlx_t *mlx, t_game *game);
void	display_left_animation(mlx_t *mlx, t_game *game, int y, int x);
void	display_map(mlx_t *mlx, t_game *game);
void	display_player(mlx_t *mlx, t_game *game, int y, int x);
void	display_right_animation(mlx_t *mlx, t_game *game, int y, int x);
void	display_trap(mlx_t *mlx, t_game *game);
void	display_ui(mlx_t *mlx, t_game *game);

/****
* RESIZE IMAGES */
void	resize_image_map(mlx_t *mlx, t_game *game);
void	resize_image_player(mlx_t *mlx, t_game *game);
void	resize_image_ui(mlx_t *mlx, t_game *game);

/****
* UTILS */
void	ft_error(char *str);
int		ft_strchr(char *str, char to_find);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
t_list_component	*create_node(t_list_component *head, int y, int x, char type);
void	print_list(t_list_component *head);
void	free_list(t_list_component **head);
void	add_data_to_node(t_game *game);
void	add_to_list(t_game *game);

/****
* HOOKS */
void	hook_movement(void *param);
void	hook_trap(void *param);

/****
* EVENTS */
int		collision_event(t_list_component *temp);

/****
* ANIMATIONS */
void	animation_left(mlx_t *mlx);
void	animation_right(mlx_t *mlx);
void	reset_animation(void);
void	update_trap(mlx_t *mlx);

/****
* MOVEMENTS */
void	moove_down(void);
void	moove_left(void);
void	moove_right(void);
void	moove_up(void);

#endif