/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_image_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:12:53 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/15 12:56:36 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	resize_image_player(void)
{
	int	width;
	int	height;
	int	i;

	width = 68;
	height = 100;
	i = 0;
	mlx_resize_image(g_game.image_player.image_character, width, height);
	while (i < 6)
	{
		mlx_resize_image(g_game.image_player.image_right_animation[i], \
		width, height);
		mlx_resize_image(g_game.image_player.image_left_animation[i], \
		width, height);
		mlx_resize_image(g_game.image_player.image_up_animation[i++], \
		width, height);
	}
}
