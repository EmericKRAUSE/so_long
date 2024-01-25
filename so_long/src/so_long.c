/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:26:25 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/25 14:37:37 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game			g_game;
int				g_pixels = 128;

t_player	init_player(mlx_t *mlx)
{
	t_player	player;
	
	player.y = get_position(g_game.map, 'y');
	player.x = get_position(g_game.map, 'x');
	player.collectible = 0;
	return (player);
}

// void	delete_image_map(mlx_t *mlx)
// {
// 	mlx_delete_image(mlx, g_game.image_map.image_background);
// 	mlx_delete_image(mlx, g_game.image_map.image_wall);
// 	mlx_delete_image(mlx, g_game.image_map.image_collectible);
// 	mlx_delete_image(mlx, g_game.image_map.image_exit);
// 	mlx_delete_image(mlx, g_game.image_map.image_trap);
// 	mlx_delete_image(mlx, g_game.image_character.image_character);
// }

// void	is_collectible(mlx_t *mlx, int y, int x)
// {
// 		if (g_game.map.tab[y][x] == 'C')
// 		{
// 			g_game.map.tab[y][x] = '0';
// 			delete_image_map(mlx);
// 			display_map(mlx, g_game);
// 			display_character(mlx, g_game, y, x);
// 			g_game.player.collectible++;
// 		}
// }

// void	is_exit(mlx_t *mlx, int y, int x)
// {
// 	if (g_game.map.tab[y][x] == 'E' && g_game.player.collectible == g_game.map.collectible)
// 	{
// 		mlx_texture_t *win_texture = mlx_load_png("../assets/win2.png");
// 		mlx_image_t *win_image = mlx_texture_to_image(mlx, win_texture);
// 		mlx_resize_image(win_image, 1920 / 2, 1080 / 2);
// 		mlx_image_to_window(mlx, win_image, 1920 / 2, 1080 / 2);
// 	}
// }

// void	is_trap(mlx_t *mlx, int y, int x)
// {
// 	char *str = "loose";
// 	if (g_game.map.tab[y][x] == 'T')
// 	{
// 		//mlx_delete_image(mlx, g_game.images.image_lifebar_full);
// 		//mlx_image_to_window(mlx, g_game.images.image_lifebar_empty, 0, g_game.map.y * g_pixels - g_pixels);
// 	}
// }

// void	key_hook(mlx_key_data_t keydata, void *param)
// {
// 	mlx_t *mlx;

// 	int	y = g_game.image_character.image_character->instances->y / g_pixels;
// 	int x = g_game.image_character.image_character->instances->x / g_pixels;

// 	mlx = param;
// 	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS && g_game.map.tab[y - 1][x] != '1')
// 	{
// 		g_game.image_character.image_character->instances->y -= g_pixels;
// 		// is_collectible(mlx, y - 1, x);
// 		// is_exit(mlx, y - 1, x);
// 		// is_trap(mlx, y - 1, x);
// 	}
// 	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS && g_game.map.tab[y + 1][x] != '1')
// 	{
// 		g_game.image_character.image_character->instances->y += g_pixels;
// 		// is_collectible(mlx, y + 1, x);
// 		// is_exit(mlx, y + 1, x);
// 		// is_trap(mlx, y + 1, x);
// 	}
// 	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS && g_game.map.tab[y][x - 1] != '1')
// 	{
// 		g_game.image_character.image_character->instances->x -= g_pixels;
// 		// is_collectible(mlx, y, x - 1);
// 		// is_exit(mlx, y, x - 1);
// 		// is_trap(mlx, y, x - 1);
// 	}
// 	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS && g_game.map.tab[y][x + 1] != '1')
// 	{
// 		g_game.image_character.image_character->instances->x += g_pixels;
// 		// is_collectible(mlx, y, x + 1);
// 		// is_exit(mlx, y, x + 1);
// 		// is_trap(mlx, y, x + 1);
// 	}
		
// }

// SO LONG //

int	check_hitbox(int y, int x)
{
	t_list_wall	*temp;

	temp = g_game.list_wall;

	while (temp)
	{
		if (!(y + g_pixels <= temp->y || y >= temp->y + g_pixels || 
		x + g_pixels <= temp->x || x >= temp->x + g_pixels))
			return (1);
		temp = temp->next;
	}
	return (0);
}

void hook(void* param)
{
    mlx_t* mlx;
    mlx = param;

    if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
        mlx_close_window(param);

	int y = g_game.image_character.image_character->instances[0].y;
	int	x = g_game.image_character.image_character->instances[0].x;

    if (mlx_is_key_down(param, MLX_KEY_W) && !check_hitbox(y - 8, x))
		g_game.image_character.image_character->instances[0].y -= 8;
    if (mlx_is_key_down(param, MLX_KEY_S) && !check_hitbox(y + 8, x))
        g_game.image_character.image_character->instances[0].y += 8;
    if (mlx_is_key_down(param, MLX_KEY_A) && !check_hitbox(y, x - 8))
        g_game.image_character.image_character->instances[0].x -= 8;
    if (mlx_is_key_down(param, MLX_KEY_D) && !check_hitbox(y, x + 8))
        g_game.image_character.image_character->instances[0].x += 8;
}

static	void	so_long(char *file)
{
	mlx_t		*mlx;

	g_game.map = map_parser(file);
	mlx = mlx_init(g_game.map.x * g_pixels, g_game.map.y * g_pixels, "game", true);
	g_game.player = init_player(mlx);

	display_map(mlx, &g_game);
	//print_list(g_game.list_wall);
	display_character(mlx, &g_game, g_game.player.y, g_game.player.x);

	mlx_loop_hook(mlx, &hook, mlx);
	//mlx_key_hook(mlx, &key_hook, mlx);
	mlx_loop(mlx);
	
	free_map(g_game.map);
	free_list(&g_game.list_wall);
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
