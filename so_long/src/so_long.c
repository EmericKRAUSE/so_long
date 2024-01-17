/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:26:25 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/17 13:00:55 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*void	display_map(t_map map, void *mlx_ptr)
{
	void	*texture_dirt;
	void	*texture_tree;
	void	*texture_key;
	void	*texture_chest;
	void	*texture_c;

	void	*img_dirt;
	void	*img_tree;
	void	*img_key;
	void	*img_chest;
	void	*img_c;

	int y;
	int x;
	int y_pixels;
	int	x_pixels;

	y_pixels = 128;
	x_pixels = 128;

	texture_dirt = mlx_load_png("./assets/grass.png");
	img_dirt = mlx_texture_to_image(mlx_ptr, texture_dirt);
	mlx_resize_image(img_dirt, x_pixels, y_pixels);

	texture_tree = mlx_load_png("./assets/tree.png");
	img_tree = mlx_texture_to_image(mlx_ptr, texture_tree);
	mlx_resize_image(img_tree, x_pixels, y_pixels);

	texture_key = mlx_load_png("./assets/key.png");
	img_key = mlx_texture_to_image(mlx_ptr, texture_key);
	mlx_resize_image(img_key, x_pixels, y_pixels);

	texture_chest = mlx_load_png("./assets/chest.png");
	img_chest = mlx_texture_to_image(mlx_ptr, texture_chest);
	mlx_resize_image(img_chest, x_pixels, y_pixels);

	texture_c = mlx_load_png("./assets/character.png");
	img_c = mlx_texture_to_image(mlx_ptr, texture_c);
	mlx_resize_image(img_c, x_pixels, y_pixels);

	y = 0;
	while (y < map.y)
	{
		x = 0;
		while (map.tab[y][x])
		{
			if (map.tab[y][x] == '1')
			{
				mlx_image_to_window(mlx_ptr, img_dirt, x * x_pixels, y * y_pixels);
				mlx_image_to_window(mlx_ptr, img_tree, x * x_pixels, y * y_pixels);
			}
			else if (map.tab[y][x] == '0')
				mlx_image_to_window(mlx_ptr, img_dirt, x * x_pixels, y * y_pixels);
			else if (map.tab[y][x] == 'C')
			{
				mlx_image_to_window(mlx_ptr, img_dirt, x * x_pixels, y * y_pixels);
				mlx_image_to_window(mlx_ptr, img_key, x * x_pixels, y * y_pixels);
			}
			else if (map.tab[y][x] == 'E')
			{
				mlx_image_to_window(mlx_ptr, img_dirt, x * x_pixels, y * y_pixels);
				mlx_image_to_window(mlx_ptr, img_chest, x * x_pixels, y * y_pixels);
			}
			else if (map.tab[y][x] == 'P')
			{
				mlx_image_to_window(mlx_ptr, img_dirt, x * x_pixels, y * y_pixels);
				mlx_image_to_window(mlx_ptr, img_c, x * x_pixels, y * y_pixels);
			}
			x++;
		}
		y++;
	}
}*/

int	so_long(char *path_map)
{
	int		y;
	t_map	map;
	//void	*mlx_ptr;
	map = map_parser(path_map);
	if (!map.is_valid)
	{
		free_map(map);
		return (0);
	}
	y = 0;
	while (y < map.y)
	{
		printf ("%s\n", map.tab[y]);
		y++;
	}
	free_map(map);
	//mlx_ptr = mlx_init(map.x * 128, map.y * 128, "game", true);
	//display_map(map, mlx_ptr);
	//mlx_loop(mlx_ptr);
	//mlx_delete_image(mlx_ptr, img_ptr);
	//mlx_delete_texture(texture_ptr);
	//mlx_terminate(mlx_ptr);
	return (1);
}

int	main(void)
{
	char	*path_map;

	path_map = "../maps/map.ber";
	if (!so_long(path_map))
		return (1);
	return (0);
}
