/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_image_ui.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:12:19 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/12 15:30:55 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	resize_image_ui(void)
{
	int	m;

	m = 8;
	mlx_resize_image(g_game.image_ui.image_win, \
	g_game.image_ui.image_win->width * m, \
	g_game.image_ui.image_win->height * m);
	mlx_resize_image(g_game.image_ui.image_lose, \
	g_game.image_ui.image_lose->width * m, \
	g_game.image_ui.image_lose->height * m);
}
