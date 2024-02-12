/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_trap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:53:02 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/12 12:15:34 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_image_trap(mlx_t *mlx)
{
	int	i;

	i = -1;
	g_game.image_map.texture_trap[0] = mlx_load_png("assets/map/trap1.png");
	g_game.image_map.texture_trap[1] = mlx_load_png("assets/map/trap2.png");
	g_game.image_map.texture_trap[2] = mlx_load_png("assets/map/trap3.png");
	g_game.image_map.texture_trap[3] = mlx_load_png("assets/map/trap4.png");
	g_game.image_map.texture_trap[4] = mlx_load_png("assets/map/trap5.png");
	g_game.image_map.texture_trap[5] = mlx_load_png("assets/map/trap6.png");
	g_game.image_map.texture_trap[6] = mlx_load_png("assets/map/trap7.png");
	g_game.image_map.texture_trap[7] = mlx_load_png("assets/map/trap8.png");
	g_game.image_map.texture_trap[8] = mlx_load_png("assets/map/trap9.png");
	while (++i < 9)
		g_game.image_map.image_trap[i] = \
		mlx_texture_to_image \
		(mlx, g_game.image_map.texture_trap[i]);
}
