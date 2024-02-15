/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_down_animation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:09:31 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/15 14:59:09 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_down_animation(mlx_t *mlx)
{
	int	i;

	i = -1;
	g_game.image_player.texture_down_animation[0] = \
	mlx_load_png("assets/character/down1.png");
	g_game.image_player.texture_down_animation[1] = \
	mlx_load_png("assets/character/down2.png");
	g_game.image_player.texture_down_animation[2] = \
	mlx_load_png("assets/character/down3.png");
	g_game.image_player.texture_down_animation[3] = \
	mlx_load_png("assets/character/down4.png");
	g_game.image_player.texture_down_animation[4] = \
	mlx_load_png("assets/character/down5.png");
	g_game.image_player.texture_down_animation[5] = \
	mlx_load_png("assets/character/down6.png");
	while (++i < 6)
		g_game.image_player.image_down_animation[i] = \
		mlx_texture_to_image \
		(mlx, g_game.image_player.texture_down_animation[i]);
}
