/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:30:36 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/12 14:57:46 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	display_ui(mlx_t *mlx, t_game *game)
{
	int	win_width;
	int	win_height;
	int	img_width;
	int	img_height;

	win_width = g_game.map.x * g_game.pixel;
	win_height = g_game.map.y * g_game.pixel;
	img_width = g_game.image_ui.image_win->width;
	img_height = g_game.image_ui.image_win->height;
	mlx_image_to_window(mlx, game->image_ui.image_win, (win_width - win_width / 2) \
	- (img_width / 2), (win_height - win_height / 2) - (img_height / 2));
	mlx_image_to_window(mlx, game->image_ui.image_lose, (win_width - win_width / 2) \
	- (img_width / 2), (win_height - win_height / 2) - (img_height / 2));
	g_game.image_ui.image_win->enabled = false;
	g_game.image_ui.image_lose->enabled = false;
}
