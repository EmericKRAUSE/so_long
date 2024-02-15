/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:38:20 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/15 10:58:18 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static	void	draw_exit(mlx_t *mlx, int y, int x, int j)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_image_to_window(mlx, g_game.image_map.image_exit[i], \
		x * g_game.pixel, y * g_game.pixel);
		g_game.image_map.image_exit[i]->instances[j].enabled = false;
		i++;
	}
}

void	display_exit(mlx_t *mlx, t_game *game)
{
	int	y;
	int	x;
	int	j;

	y = -1;
	j = 0;
	while (++y < game->map.y)
	{
		x = -1;
		while (++x < game->map.x)
		{
			if (game->map.tab[y][x] == 'E')
			{
				draw_exit(mlx, y, x, j);
				j++;
			}
		}
	}
}
