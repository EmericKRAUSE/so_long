/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_down_animation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:11:46 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/15 14:51:55 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	display_down_animation(mlx_t *mlx, t_game *game, int y, int x)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		mlx_image_to_window(mlx, game \
		->image_player.image_down_animation[i], \
		x * g_game.pixel, y * g_game.pixel);
		game->image_player.image_down_animation[i++] \
		->instances[0].enabled = false;
	}
}
