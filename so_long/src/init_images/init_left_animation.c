/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_left_animation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:51:20 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/12 12:15:48 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_left_animation(mlx_t *mlx)
{
	int	i;

	i = -1;
	g_game.image_player.texture_left_animation[0] = \
	mlx_load_png("assets/character/left1.png");
	g_game.image_player.texture_left_animation[1] = \
	mlx_load_png("assets/character/left2.png");
	g_game.image_player.texture_left_animation[2] = \
	mlx_load_png("assets/character/left3.png");
	g_game.image_player.texture_left_animation[3] = \
	mlx_load_png("assets/character/left4.png");
	g_game.image_player.texture_left_animation[4] = \
	mlx_load_png("assets/character/left5.png");
	while (++i < 5)
		g_game.image_player.image_left_animation[i] = \
		mlx_texture_to_image \
		(mlx, g_game.image_player.texture_left_animation[i]);
}
