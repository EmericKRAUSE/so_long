/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_image_ui.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:12:19 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/08 10:12:22 by ekrause          ###   ########.fr       */
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
