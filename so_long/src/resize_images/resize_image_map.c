/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_image_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:13:27 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/08 10:13:32 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	resize_image_map(void)
{
	mlx_resize_image(g_game.image_map.image_background, \
	g_game.pixel, g_game.pixel);
	mlx_resize_image(g_game.image_map.image_wall, \
	g_game.pixel, g_game.pixel);
	mlx_resize_image(g_game.image_map.image_collectible, \
	g_game.pixel, g_game.pixel);
	mlx_resize_image(g_game.image_map.image_exit, \
	g_game.pixel, g_game.pixel);
	resize_image_trap();
}
