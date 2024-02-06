/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:47:24 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/06 14:09:23 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	resize_image_ui(void)
{
	mlx_resize_image(g_game.image_ui.image_heart_1, \
	g_game.pixel, g_game.pixel);
	mlx_resize_image(g_game.image_ui.image_slot, \
	g_game.pixel, g_game.pixel);
}

void	resize_image_player(void)
{
	int	width;
	int	height;
	int	i;

	width = 68;
	height = 100;
	i = 0;
	mlx_resize_image(g_game.image_player.image_character, width, height);
	while (i < 5)
	{
		mlx_resize_image(g_game.image_player.image_right_animation[i], \
		width, height);
		mlx_resize_image(g_game.image_player.image_left_animation[i++], \
		width, height);
	}
}

void	resize_image_trap(void)
{
	int	i;

	i = 0;
	while (i < 5)
		mlx_resize_image(g_game.image_map.image_trap[i++], \
		g_game.pixel, g_game.pixel);
}

void	resize_image_map(void)
{
	mlx_resize_image(g_game.image_map.image_background, g_game.pixel, g_game.pixel);
	mlx_resize_image(g_game.image_map.image_wall, g_game.pixel, g_game.pixel);
	mlx_resize_image(g_game.image_map.image_collectible, g_game.pixel, g_game.pixel);
	mlx_resize_image(g_game.image_map.image_exit, g_game.pixel, g_game.pixel);
	resize_image_trap();
}
