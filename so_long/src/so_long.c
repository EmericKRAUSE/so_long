/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:26:25 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/18 11:32:30 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*g_map_name = "../maps/map";
char	*g_map_extension = ".ber";
int		g_pixels = 124;

/*mlx_texture_t	*init_texture(void)
{
	mlx_texture_t	*texture;

	texture->width = 16;
	texture->height = 16;
	texture->bytes_per_pixel = 4;
	texture->pixels = "1";

	return(texture);
}*/


/*mlx_image_t	init_image(void)
{
	mlx_image_t image;

	width = 16;
	height = 16;
	pixels = 1;
	instances->x = 0;
	instances->y = 0;
	instances->z = 0;
	instances->enabled = true;

	return (image);
}*/

void	display_map(t_map map, mlx_t *mlx)
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

	int y;
	int x;

	texture_background = mlx_load_png("../assets/grass.png");
	image_background = mlx_texture_to_image(mlx, texture_background);
	mlx_resize_image(image_background, g_pixels, g_pixels);

	texture_wall = mlx_load_png("../assets/tree.png");
	image_wall = mlx_texture_to_image(mlx, texture_wall);
	mlx_resize_image(image_wall, g_pixels, g_pixels);

	texture_collectible = mlx_load_png("../assets/key.png");
	image_collectible = mlx_texture_to_image(mlx, texture_collectible);
	mlx_resize_image(image_collectible, g_pixels, g_pixels);

	texture_exit = mlx_load_png("../assets/chest.png");
	image_exit = mlx_texture_to_image(mlx, texture_exit);
	mlx_resize_image(image_exit, g_pixels, g_pixels);

	texture_character = mlx_load_png("../assets/character.png");
	image_character = mlx_texture_to_image(mlx, texture_character);
	mlx_resize_image(image_character, g_pixels, g_pixels);

	y = 0;
	while (y < map.y)
	{
		x = 0;
		while (x < map.x)
		{
			mlx_image_to_window(mlx, image_background, x * g_pixels, y * g_pixels);
			if (map.tab[y][x] == '1')
				mlx_image_to_window(mlx, image_wall, x * g_pixels, y * g_pixels);
			else if (map.tab[y][x] == 'C')
				mlx_image_to_window(mlx, image_collectible, x * g_pixels, y * g_pixels);
			else if (map.tab[y][x] == 'E')
				mlx_image_to_window(mlx, image_exit, x * g_pixels, y * g_pixels);
			else if (map.tab[y][x] == 'P')
				mlx_image_to_window(mlx, image_character, x * g_pixels, y * g_pixels);
			x++;
		}
		y++;
	}
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

	mlx_loop(mlx);

	//mlx_delete_image(mlx_ptr, img_ptr);
	//mlx_delete_texture(texture_ptr);
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
