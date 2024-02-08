/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_right_animation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:51:46 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/08 10:09:35 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_right_animation(mlx_t *mlx)
{
	int	i;

	i = -1;
	g_game.image_player.texture_right_animation[0] = \
	mlx_load_png("../assets/character/right1.png");
	g_game.image_player.texture_right_animation[1] = \
	mlx_load_png("../assets/character/right2.png");
	g_game.image_player.texture_right_animation[2] = \
	mlx_load_png("../assets/character/right3.png");
	g_game.image_player.texture_right_animation[3] = \
	mlx_load_png("../assets/character/right4.png");
	g_game.image_player.texture_right_animation[4] = \
	mlx_load_png("../assets/character/right5.png");
	while (++i < 5)
		g_game.image_player.image_right_animation[i] = \
		mlx_texture_to_image \
		(mlx, g_game.image_player.texture_right_animation[i]);
}
