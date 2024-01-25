/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:05:29 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/25 15:38:00 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	display_map(mlx_t *mlx, t_game *g_game)
{
	int		pixels;
	int		y;
	int		x;

	pixels = 128;
	g_game->image_map = init_image_map(mlx);

	mlx_resize_image(g_game->image_map.image_background, pixels, pixels);
	mlx_resize_image(g_game->image_map.image_wall, pixels, pixels);
	mlx_resize_image(g_game->image_map.image_collectible, pixels, pixels);
	mlx_resize_image(g_game->image_map.image_exit, pixels, pixels);
	mlx_resize_image(g_game->image_map.image_trap, pixels, pixels);
	
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
				g_game->list_wall = create_node(g_game->list_wall, y * pixels, x * pixels);
			}
			else if (g_game->map.tab[y][x] == 'C')
				mlx_image_to_window(mlx, g_game->image_map.image_collectible, x * pixels, y * pixels);
			else if (g_game->map.tab[y][x] == 'E')
				mlx_image_to_window(mlx, g_game->image_map.image_exit, x * pixels, y * pixels);
			else if (g_game->map.tab[y][x] == 'T')
				mlx_image_to_window(mlx, g_game->image_map.image_trap, x * pixels, y * pixels);
			x++;
		}
		y++;
	}
}