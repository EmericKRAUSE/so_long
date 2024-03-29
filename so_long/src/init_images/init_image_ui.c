/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_ui.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:50:49 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/12 14:36:24 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_image_ui(mlx_t *mlx)
{
	g_game.image_ui.texture_win = mlx_load_png("assets/UI/you_win.png");
	g_game.image_ui.texture_lose = mlx_load_png("assets/UI/you_lose.png");
	g_game.image_ui.image_win = mlx_texture_to_image \
	(mlx, g_game.image_ui.texture_win);
	g_game.image_ui.image_lose = mlx_texture_to_image \
	(mlx, g_game.image_ui.texture_lose);
}
