/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:05:29 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/30 11:31:17 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	display_ui(mlx_t *mlx, t_game *game)
{
	int	pixels;
	int	x;

	pixels = 128;
	x = 0;
	mlx_image_to_window(mlx, game->image_ui.image_heart_1, \
	0, game->map.y * pixels - pixels * 2);
	while (x < 4)
	{
		mlx_image_to_window(mlx, game->image_ui.image_slot, \
		x * pixels, game->map.y * pixels - pixels);
		x++;
	}
}

void	display_player(mlx_t *mlx, t_game *game, int y, int x)
{
	int	pixels;

	pixels = 128;
	mlx_image_to_window(mlx, game->image_player.image_character[0], \
	x * pixels, y * pixels);
	mlx_image_to_window(mlx, game->image_player.image_character[1], \
	x * pixels, y * pixels);
	mlx_image_to_window(mlx, game->image_player.image_character[2], \
	x * pixels, y * pixels);
	mlx_image_to_window(mlx, game->image_player.image_character[3], \
	x * pixels, y * pixels);
	mlx_image_to_window(mlx, game->image_player.image_character[4], \
	x * pixels, y * pixels);
	game->image_player.image_character[1]->instances[0].enabled = false;
	game->image_player.image_character[2]->instances[0].enabled = false;
	game->image_player.image_character[3]->instances[0].enabled = false;
	game->image_player.image_character[4]->instances[0].enabled = false;
}

void	display_trap(mlx_t *mlx, t_game *game)
{
	int	pixels;
	int	y;
	int	x;

	pixels = 128;
	y = -1;
	while (++y < game->map.y)
	{
		x = -1;
		while (++x < game->map.x)
		{
			if (game->map.tab[y][x] == 'T')
			{
				mlx_image_to_window(mlx, game->image_map.image_trap[0], \
				x * pixels, y * pixels);
				mlx_image_to_window(mlx, game->image_map.image_trap[1], \
				x * pixels, y * pixels);
				mlx_image_to_window(mlx, game->image_map.image_trap[2], \
				x * pixels, y * pixels);
				mlx_image_to_window(mlx, game->image_map.image_trap[3], \
				x * pixels, y * pixels);
				mlx_image_to_window(mlx, game->image_map.image_trap[4], \
				x * pixels, y * pixels);
			}
		}
	}
	game->image_map.image_trap[0]->instances->enabled = false;
	game->image_map.image_trap[1]->instances->enabled = false;
	game->image_map.image_trap[2]->instances->enabled = false;
	game->image_map.image_trap[3]->instances->enabled = false;
	game->image_map.image_trap[4]->instances->enabled = false;
}

void	display_map(mlx_t *mlx, t_game *game)
{
	int	pixels;
	int	y;
	int	x;

	pixels = 128;
	y = -1;
	while (++y < game->map.y)
	{
		x = -1;
		while (++x < game->map.x)
		{
			mlx_image_to_window(mlx, game->image_map.image_background, \
			x * pixels, y * pixels);
			if (game->map.tab[y][x] == '1')
				mlx_image_to_window(mlx, game->image_map.image_wall, \
				x * pixels, y * pixels);
			else if (game->map.tab[y][x] == 'C')
				mlx_image_to_window(mlx, game->image_map.image_collectible, \
				x * pixels, y * pixels);
			else if (game->map.tab[y][x] == 'E')
				mlx_image_to_window(mlx, game->image_map.image_exit, \
				x * pixels, y * pixels);
		}
	}
}

void	add_to_list(t_game *game)
{
	int	pixels;
	int	y;
	int	x;

	pixels = 128;
	y = -1;
	while (++y < game->map.y)
	{
		x = -1;
		while (++x < game->map.x)
		{
			if (game->map.tab[y][x] == '1')
				game->list_component = create_node(game->list_component, \
				y * pixels, x * pixels, '1');
			else if (game->map.tab[y][x] == 'C')
				game->list_component = create_node(game->list_component, \
				y * pixels, x * pixels, 'C');
			else if (game->map.tab[y][x] == 'E')
				game->list_component = create_node(game->list_component, \
				y * pixels, x * pixels, 'E');
			else if (game->map.tab[y][x] == 'T')
				game->list_component = create_node(game->list_component, \
				y * pixels, x * pixels, 'T');
		}
	}
	add_data_to_node(game);
}

void	display_images(mlx_t *mlx, t_game *game)
{
	display_map(mlx, game);
	display_trap(mlx, game);
	add_to_list(game);
	display_player(mlx, game, game->player.y, game->player.x);
	display_ui(mlx, game);
}
