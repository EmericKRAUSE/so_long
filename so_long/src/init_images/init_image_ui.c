/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_ui.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:50:49 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/12 12:15:39 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_image_ui(mlx_t *mlx)
{
	g_game.image_ui.texture_heart_1 = mlx_load_png("assets/UI/heart-1.png");
	g_game.image_ui.texture_slot = mlx_load_png("assets/UI/slot.png");
	g_game.image_ui.image_heart_1 = mlx_texture_to_image \
	(mlx, g_game.image_ui.texture_heart_1);
	g_game.image_ui.image_slot = mlx_texture_to_image \
	(mlx, g_game.image_ui.texture_slot);
}
