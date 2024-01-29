/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:05:29 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/29 15:20:31 by ekrause          ###   ########.fr       */
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

void	display_map(mlx_t *mlx, t_game *g_game)
{
	int		pixels;
	int		y;
	int		x;

	pixels = 128;
	y = 0;
	while (y < g_game->map.y)
	{
		x = 0;
		while (x < g_game->map.x)
		{
			mlx_image_to_window(mlx, g_game->image_map.image_background, x * pixels, y * pixels);
			if (g_game->map.tab[y][x] == '1')
			{
				mlx_image_to_window(mlx, g_game->image_map.image_wall, x * pixels, y * pixels);
				g_game->list_component = create_node(g_game->list_component, y * pixels, x * pixels, '1');
			}
			else if (g_game->map.tab[y][x] == 'C')
			{
				mlx_image_to_window(mlx, g_game->image_map.image_collectible, x * pixels, y * pixels);
				g_game->list_component = create_node(g_game->list_component, y * pixels, x * pixels, 'C');
			}
			else if (g_game->map.tab[y][x] == 'E')
			{
				mlx_image_to_window(mlx, g_game->image_map.image_exit, x * pixels, y * pixels);
				g_game->list_component = create_node(g_game->list_component, y * pixels, x * pixels, 'E');
			}
			x++;
		}
		y++;
	}
	add_data_to_node(g_game);
}

void	display_images(mlx_t *mlx, t_game *game)
{
	display_map(mlx, game);
	display_player(mlx, game, game->player.y, game->player.x);
	//display_ui(mlx, game);
}
