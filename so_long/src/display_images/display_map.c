/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:36:04 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/12 12:38:56 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	display_map(mlx_t *mlx, t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map.y)
	{
		x = -1;
		while (++x < game->map.x)
		{
			mlx_image_to_window(mlx, game->image_map.image_background, \
			x * g_game.pixel, y * g_game.pixel);
			if (game->map.tab[y][x] == '1')
				mlx_image_to_window(mlx, game->image_map.image_wall, \
				x * g_game.pixel, y * g_game.pixel);
			else if (game->map.tab[y][x] == 'C')
				mlx_image_to_window(mlx, game->image_map.image_collectible, \
				x * g_game.pixel, y * g_game.pixel);
			else if (game->map.tab[y][x] == 'E')
				mlx_image_to_window(mlx, game->image_map.image_exit, \
				x * g_game.pixel, y * g_game.pixel);
		}
	}
}
