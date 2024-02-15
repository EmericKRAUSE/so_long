/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:29:54 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/15 11:26:16 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_image_exit(mlx_t *mlx)
{
	int	i;

	i = -1;
	g_game.image_map.texture_exit[0] = mlx_load_png("assets/map/exit1.png");
	g_game.image_map.texture_exit[1] = mlx_load_png("assets/map/exit2.png");
	g_game.image_map.texture_exit[2] = mlx_load_png("assets/map/exit3.png");
	g_game.image_map.texture_exit[3] = mlx_load_png("assets/map/exit4.png");
	while (++i < 4)
		g_game.image_map.image_exit[i] = \
		mlx_texture_to_image \
		(mlx, g_game.image_map.texture_exit[i]);
}
