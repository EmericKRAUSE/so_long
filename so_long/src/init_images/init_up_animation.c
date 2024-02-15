/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_up_animation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:12:58 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/15 14:59:03 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_up_animation(mlx_t *mlx)
{
	int	i;

	i = -1;
	g_game.image_player.texture_up_animation[0] = \
	mlx_load_png("assets/character/up1.png");
	g_game.image_player.texture_up_animation[1] = \
	mlx_load_png("assets/character/up2.png");
	g_game.image_player.texture_up_animation[2] = \
	mlx_load_png("assets/character/up3.png");
	g_game.image_player.texture_up_animation[3] = \
	mlx_load_png("assets/character/up4.png");
	g_game.image_player.texture_up_animation[4] = \
	mlx_load_png("assets/character/up5.png");
	g_game.image_player.texture_up_animation[5] = \
	mlx_load_png("assets/character/up6.png");
	while (++i < 6)
		g_game.image_player.image_up_animation[i] = \
		mlx_texture_to_image \
		(mlx, g_game.image_player.texture_up_animation[i]);
}
