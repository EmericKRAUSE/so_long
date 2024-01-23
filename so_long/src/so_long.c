/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:26:25 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/23 15:01:49 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game			g_game;
int				g_pixels = 124;

t_images	init_images(mlx_t *mlx)
{
	t_images	images;
	
	images.texture_background = mlx_load_png("../assets/grass.png");
	images.texture_wall = mlx_load_png("../assets/log.png");
	images.texture_collectible = mlx_load_png("../assets/egg.png");
	images.texture_exit = mlx_load_png("../assets/chicken-house.png");
	images.texture_trap = mlx_load_png("../assets/trap.png");
	images.texture_lifebar_empty = mlx_load_png("../assets/lifebar1.png");
	images.texture_lifebar_full = mlx_load_png("../assets/lifebar2.png");
	images.texture_character = mlx_load_png("../assets/chicken.png");
	
	images.image_background = mlx_texture_to_image(mlx, images.texture_background);
	images.image_wall = mlx_texture_to_image(mlx, images.texture_wall);
	images.image_collectible = mlx_texture_to_image(mlx, images.texture_collectible);
	images.image_exit = mlx_texture_to_image(mlx, images.texture_exit);
	images.image_trap = mlx_texture_to_image(mlx, images.texture_trap);
	images.image_lifebar_empty = mlx_texture_to_image(mlx, images.texture_lifebar_empty);
	images.image_lifebar_full = mlx_texture_to_image(mlx, images.texture_lifebar_full);
	images.image_character = mlx_texture_to_image(mlx, images.texture_character);
	return (images);
}

t_player	init_player(mlx_t *mlx)
{
	t_player	player;
	
	player.y = get_position(g_game.map, 'y');
	player.x = get_position(g_game.map, 'x');
	player.collectible = 0;
	return (player);
}

void	display_character(mlx_t *mlx, int y, int x)
{
	mlx_resize_image(g_game.images.image_character, g_pixels, g_pixels);
	mlx_image_to_window(mlx, g_game.images.image_character, x * g_pixels, y * g_pixels);
}

void	display_map(mlx_t *mlx)
{
	int		y;
	int		x;

	g_game.images = init_images(mlx);

	mlx_resize_image(g_game.images.image_background, g_pixels, g_pixels);
	mlx_resize_image(g_game.images.image_wall, g_pixels, g_pixels);
	mlx_resize_image(g_game.images.image_collectible, g_pixels, g_pixels);
	mlx_resize_image(g_game.images.image_exit, g_pixels, g_pixels);
	mlx_resize_image(g_game.images.image_trap, g_pixels, g_pixels);
	mlx_resize_image(g_game.images.image_lifebar_empty, g_pixels, g_pixels);
	mlx_resize_image(g_game.images.image_lifebar_full, g_pixels, g_pixels);
	
	y = 0;
	while (y < g_game.map.y)
	{
		x = 0;
		while (x < g_game.map.x)
		{
			mlx_image_to_window(mlx, g_game.images.image_background, x * g_pixels, y * g_pixels);
			if (g_game.map.tab[y][x] == '1')
				mlx_image_to_window(mlx, g_game.images.image_wall, x * g_pixels, y * g_pixels);
			else if (g_game.map.tab[y][x] == 'C')
				mlx_image_to_window(mlx, g_game.images.image_collectible, x * g_pixels, y * g_pixels);
			else if (g_game.map.tab[y][x] == 'E')
				mlx_image_to_window(mlx, g_game.images.image_exit, x * g_pixels, y * g_pixels);
			else if (g_game.map.tab[y][x] == 'T')
				mlx_image_to_window(mlx, g_game.images.image_trap, x * g_pixels, y * g_pixels);
			x++;
		}
		y++;
	}
	//mlx_image_to_window(mlx, g_game.images.image_lifebar_empty, 0, 0);
	mlx_image_to_window(mlx, g_game.images.image_lifebar_full, 0, g_game.map.y * g_pixels - g_pixels);
}

void	delete_image_map(mlx_t *mlx)
{
	mlx_delete_image(mlx, g_game.images.image_background);
	mlx_delete_image(mlx, g_game.images.image_wall);
	mlx_delete_image(mlx, g_game.images.image_collectible);
	mlx_delete_image(mlx, g_game.images.image_exit);
	mlx_delete_image(mlx, g_game.images.image_character);
	mlx_delete_image(mlx, g_game.images.image_trap);
}

void	is_collectible(mlx_t *mlx, int y, int x)
{
		if (g_game.map.tab[y][x] == 'C')
		{
			g_game.map.tab[y][x] = '0';
			delete_image_map(mlx);
			display_map(mlx);
			display_character(mlx, y, x);
			g_game.player.collectible++;
		}
}

void	is_exit(mlx_t *mlx, int y, int x)
{
	if (g_game.map.tab[y][x] == 'E' && g_game.player.collectible == g_game.map.collectible)
	{
		mlx_texture_t *win_texture = mlx_load_png("../assets/win2.png");
		mlx_image_t *win_image = mlx_texture_to_image(mlx, win_texture);
		mlx_resize_image(win_image, 1920 / 2, 1080 / 2);
		mlx_image_to_window(mlx, win_image, 1920 / 2, 1080 / 2);
	}
}

void	is_trap(mlx_t *mlx, int y, int x)
{
	char *str = "loose";
	if (g_game.map.tab[y][x] == 'T')
	{
		mlx_delete_image(mlx, g_game.images.image_lifebar_full);
		mlx_image_to_window(mlx, g_game.images.image_lifebar_empty, 0, g_game.map.y * g_pixels - g_pixels);
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	mlx_t *mlx;

	int	y = g_game.images.image_character->instances->y / g_pixels;
	int x = g_game.images.image_character->instances->x / g_pixels;

	mlx = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS && g_game.map.tab[y - 1][x] != '1')
	{
		g_game.images.image_character->instances->y -= g_pixels;
		is_collectible(mlx, y - 1, x);
		is_exit(mlx, y - 1, x);
		is_trap(mlx, y - 1, x);
	}
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS && g_game.map.tab[y + 1][x] != '1')
	{
		g_game.images.image_character->instances->y += g_pixels;
		is_collectible(mlx, y + 1, x);
		is_exit(mlx, y + 1, x);
		is_trap(mlx, y + 1, x);
	}
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS && g_game.map.tab[y][x - 1] != '1')
	{
		g_game.images.image_character->instances->x -= g_pixels;
		is_collectible(mlx, y, x - 1);
		is_exit(mlx, y, x - 1);
		is_trap(mlx, y, x - 1);
	}
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS && g_game.map.tab[y][x + 1] != '1')
	{
		g_game.images.image_character->instances->x += g_pixels;
		is_collectible(mlx, y, x + 1);
		is_exit(mlx, y, x + 1);
		is_trap(mlx, y, x + 1);
	}
		
}

// SO LONG //

static	void	so_long(char *file)
{
	mlx_t		*mlx;

	g_game.map = map_parser(file);
	mlx = mlx_init(g_game.map.x * g_pixels, g_game.map.y * g_pixels, "game", true);
	g_game.player = init_player(mlx);

	display_map(mlx);
	display_character(mlx, g_game.player.y, g_game.player.x);

	mlx_key_hook(mlx, &key_hook, mlx);
	mlx_loop(mlx);
	
	free_map(g_game.map);
	mlx_terminate(mlx);
}

static	int	is_ber(char *file)
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
	so_long(file);
	return (0);
}

// SO LONG //
