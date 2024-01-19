/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:26:25 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/19 15:05:22 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_image_package	g_images;
int				g_pixels = 124;

t_image_package	init_image_package(mlx_t *mlx)
{
	t_image_package images;
	
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

void	event(int key, void *param)
{
	mlx_t	*mlx;
	
	mlx = param;
	if (key == MLX_KEY_ESCAPE)
		printf ("test");
}

int	so_long(char *file)
{
	t_map		map;
	mlx_t		*mlx;
	mlx_image_t	*img;

	map = map_parser(file);
	int y = 0;
	while (y < map.y)
		printf("%s\n", map.tab[y++]);
	mlx = mlx_init(map.x * g_pixels, map.y * g_pixels, "game", true);
	
	display_map(map, mlx);

	mlx_key_hook(mlx, event, mlx);
	mlx_loop(mlx);
	
	free_map(map);
	mlx_terminate(mlx);
	return (1);
}

int	is_ber(char *file)
{
	int	len;

	if (!file)
		return (0);
	len = ft_strlen(file);
	if (len < 5)
		return (0);
	if (!ft_strcmp(file + len - 4, ".ber"))
		return (0);
	return 1;
}

int	main(int argc, char **argv)
{
	char	*file;

	if (argc != 2)
		ft_error("please put one argument");
	file = argv[1];
	if (!is_ber(file))
		ft_error("please put a valid file");
	file = argv[1];
	so_long(file);
	return (0);
}
