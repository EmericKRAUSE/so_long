/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:07:33 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/26 15:29:11 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	display_player(mlx_t *mlx, t_game *g_game, int y, int x)
{
	int pixels;
	int width;
	int	height;

	width = 75;
	height = 110;
	pixels = 128;
	g_game->image_player = init_image_player(mlx);

	//mlx_resize_image(g_game->image_player.image_character, width, height);
	mlx_resize_image(g_game->image_player.image_sword, pixels, pixels);
	
	mlx_image_to_window(mlx, g_game->image_player.image_character, x * pixels, y * pixels);
	mlx_image_to_window(mlx, g_game->image_player.image_sword, x * pixels + 32, y * pixels - 16);
}