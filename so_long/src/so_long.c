/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:26:25 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/22 15:17:28 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_image_package	g_images;
t_map			g_map;
int				g_pixels = 124;

t_image_package	init_image_package(mlx_t *mlx)
{
	t_image_package images;
	
	images.texture_background = mlx_load_png("../assets/grass.png");
	images.texture_wall = mlx_load_png("../assets/log.png");
	images.texture_collectible = mlx_load_png("../assets/egg.png");
	images.texture_exit = mlx_load_png("../assets/chicken-house.png");
	images.texture_character = mlx_load_png("../assets/chicken.png");
	
	images.image_background = mlx_texture_to_image(mlx, images.texture_background);
	images.image_wall = mlx_texture_to_image(mlx, images.texture_wall);
	images.image_collectible = mlx_texture_to_image(mlx, images.texture_collectible);
	images.image_exit = mlx_texture_to_image(mlx, images.texture_exit);
	images.image_character = mlx_texture_to_image(mlx, images.texture_character);

	return (images);
}

void	display_character(mlx_t *mlx)
{
	int	y;
	int	x;

	y = get_position(g_map, 'y');
	x = get_position(g_map, 'x');
	mlx_image_to_window(mlx, g_images.image_character, x * g_pixels, y * g_pixels);
}

void	display_map(void *param)
{
	mlx_t	*mlx;
	int		y;
	int		x;

	mlx = param;
	g_images = init_image_package(mlx);

	mlx_resize_image(g_images.image_background, g_pixels, g_pixels);
	mlx_resize_image(g_images.image_wall, g_pixels, g_pixels);
	mlx_resize_image(g_images.image_collectible, g_pixels, g_pixels);
	mlx_resize_image(g_images.image_exit, g_pixels, g_pixels);
	mlx_resize_image(g_images.image_character, g_pixels, g_pixels);
	
	y = 0;
	while (y < g_map.y)
	{
		x = 0;
		while (x < g_map.x)
		{
			mlx_image_to_window(mlx, g_images.image_background, x * g_pixels, y * g_pixels);
			if (g_map.tab[y][x] == '1')
				mlx_image_to_window(mlx, g_images.image_wall, x * g_pixels, y * g_pixels);
			else if (g_map.tab[y][x] == 'C')
				mlx_image_to_window(mlx, g_images.image_collectible, x * g_pixels, y * g_pixels);
			else if (g_map.tab[y][x] == 'E')
				mlx_image_to_window(mlx, g_images.image_exit, x * g_pixels, y * g_pixels);
			else if (g_map.tab[y][x] == 'P')
				mlx_image_to_window(mlx, g_images.image_character, x * g_pixels, y * g_pixels);
			x++;
		}
		y++;
	}
	//display_character(mlx);
}

void	delete_map(mlx_t *mlx)
{
	mlx_delete_image(mlx, g_images.image_background);
	mlx_delete_image(mlx, g_images.image_wall);
	mlx_delete_image(mlx, g_images.image_collectible);
	mlx_delete_image(mlx, g_images.image_exit);
	mlx_delete_image(mlx, g_images.image_character);
}

void	key_event(mlx_t *mlx, int y, int x)
{
		g_map.tab[y][x] = 'P';
		delete_map(mlx);
		display_map(mlx);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	mlx_t *mlx;

	int y = g_images.image_character->instances->y / g_pixels;
	int x = g_images.image_character->instances->x / g_pixels;

	mlx = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS && g_map.tab[y - 1][x] != '1')
	{
		g_map.tab[y][x] = '0';
		key_event(mlx, y - 1, x);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS && g_map.tab[y + 1][x] != '1')
	{
		g_map.tab[y][x] = '0';
		key_event(mlx, y + 1, x);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS && g_map.tab[y][x - 1] != '1')
	{
		g_map.tab[y][x] = '0';
		key_event(mlx, y, x - 1);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS && g_map.tab[y][x + 1] != '1')
	{
		g_map.tab[y][x] = '0';
		key_event(mlx, y, x + 1);
	}
		
}

int	so_long(char *file)
{
	mlx_t		*mlx;

	g_map = map_parser(file);
	mlx = mlx_init(g_map.x * g_pixels, g_map.y * g_pixels, "game", true);
	
	display_map(mlx);

	mlx_key_hook(mlx, &key_hook, mlx);
	mlx_loop(mlx);
	
	free_map(g_map);
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
