/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:36:04 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/02 10:36:06 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
