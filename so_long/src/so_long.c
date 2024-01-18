/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:26:25 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/18 14:52:01 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char			*g_map_name = "../maps/map";
char			*g_map_extension = ".ber";
int				g_pixels = 124;


typedef struct	image_package
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
}					image_package_t;

image_package_t	g_images;

image_package_t	init_image_package(mlx_t *mlx)
{
	image_package_t images;
	
	images.texture_background = mlx_load_png("../assets/grass.png");
	images.texture_wall = mlx_load_png("../assets/tree.png");
	images.texture_collectible = mlx_load_png("../assets/key.png");
	images.texture_exit = mlx_load_png("../assets/chest.png");
	images.texture_character = mlx_load_png("../assets/character.png");
	
	images.image_background = mlx_texture_to_image(mlx, images.texture_background);
	images.image_wall = mlx_texture_to_image(mlx, images.texture_wall);
	images.image_collectible = mlx_texture_to_image(mlx, images.texture_collectible);
	images.image_exit = mlx_texture_to_image(mlx, images.texture_exit);
	images.image_character = mlx_texture_to_image(mlx, images.texture_character);

	return (images);
}

void	display_character(t_map map, mlx_t *mlx)
{
	int x;
	int y;
	
	x = get_position(map, 'x');
	y = get_position(map, 'y');
	mlx_image_to_window(mlx, g_images.image_character, x * g_pixels, y * g_pixels);
}

void	display_map(t_map map, mlx_t *mlx)
{
	int				y;
	int				x;

	g_images = init_image_package(mlx);

	mlx_resize_image(g_images.image_background, g_pixels, g_pixels);
	mlx_resize_image(g_images.image_wall, g_pixels, g_pixels);
	mlx_resize_image(g_images.image_collectible, g_pixels, g_pixels);
	mlx_resize_image(g_images.image_exit, g_pixels, g_pixels);
	mlx_resize_image(g_images.image_character, g_pixels, g_pixels);
	
	y = 0;
	while (y < map.y)
	{
		x = 0;
		while (x < map.x)
		{
			mlx_image_to_window(mlx, g_images.image_background, x * g_pixels, y * g_pixels);
			if (map.tab[y][x] == '1')
				mlx_image_to_window(mlx, g_images.image_wall, x * g_pixels, y * g_pixels);
			else if (map.tab[y][x] == 'C')
				mlx_image_to_window(mlx, g_images.image_collectible, x * g_pixels, y * g_pixels);
			else if (map.tab[y][x] == 'E')
				mlx_image_to_window(mlx, g_images.image_exit, x * g_pixels, y * g_pixels);
			x++;
		}
		y++;
	}
	display_character(map, mlx);
}

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_W))
		g_images.image_character->instances->y -= 16;
	if (mlx_is_key_down(param, MLX_KEY_S))
		g_images.image_character->instances->y += 16;
	if (mlx_is_key_down(param, MLX_KEY_A))
		g_images.image_character->instances->x -= 16;
	if (mlx_is_key_down(param, MLX_KEY_D))
		g_images.image_character->instances->x += 16;
}

int	so_long(char *path_map)
{
	t_map		map;
	mlx_t		*mlx;
	mlx_image_t	*img;

	map = map_parser(path_map);
	if (!map.is_valid)
	{
		free_map(map);
		return (0);
	}
	
	mlx = mlx_init(map.x * g_pixels, map.y * g_pixels, "game", true);
	if (!mlx)
		return (0);

	display_map(map, mlx);

	mlx_loop_hook(mlx, hook, mlx);
	mlx_loop(mlx);
	
	free_map(map);
	mlx_terminate(mlx);
	return (1);
}

int	main(void)
{
	char	*path_map;

	path_map = ft_strcat(g_map_name, g_map_extension);
	if (!so_long(path_map))
	{
		free (path_map);
		return (1);
	}
	free (path_map);
	return (0);
}
