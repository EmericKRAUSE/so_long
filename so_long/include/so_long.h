/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:01:05 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/22 10:05:14 by ekrause          ###   ########.fr       */
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
* STRUCT */
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

typedef struct image_package
{
	mlx_texture_t	*texture_background;
	mlx_texture_t	*texture_wall;
	mlx_texture_t	*texture_collectible;
	mlx_texture_t	*texture_exit;
	mlx_texture_t	*texture_character;

	mlx_image_t		*image_background;
	mlx_image_t		*image_wall;
	mlx_image_t		*image_collectible;
	mlx_image_t		*image_exit;
	mlx_image_t		*image_character;
}					t_image_package;

/****
* PARSING */
int	create_map(t_map *map);
void	fill_map(t_map *map, char *file);
void	free_map(t_map map);
int	get_map_size(t_map *map, char *file);
int		get_position(t_map flooded_map, char c);
t_map	init_map(void);
t_map	map_parser(char *file);
int	path_is_valid(t_map *map);

/****
* UTILS */
void	ft_error(char *str);
int		ft_strchr(char *str, char to_find);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

#endif