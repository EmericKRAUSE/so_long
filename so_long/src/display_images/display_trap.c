/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_trap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:34:17 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/02 11:05:05 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static	void	draw_trap(mlx_t *mlx, int y, int x, int j)
{
	int	pixels;
	int	i;

	pixels = 128;
	i = 0;
	while (i < 5)
	{
		mlx_image_to_window(mlx, g_game.image_map.image_trap[i], \
		x * pixels, y * pixels);
		g_game.image_map.image_trap[i++]->instances[j].enabled = false;
	}
}

void	display_trap(mlx_t *mlx, t_game *game)
{
	int	pixels;
	int	y;
	int	x;
	int	j;

	pixels = 128;
	y = -1;
	j = 0;
	while (++y < game->map.y)
	{
		x = -1;
		while (++x < game->map.x)
		{
			if (game->map.tab[y][x] == 'T')
			{
				draw_trap(mlx, y, x, j);
				j++;
			}
		}
	}
}