/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_left_animation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:31:22 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/15 13:13:45 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	display_left_animation(mlx_t *mlx, t_game *game, int y, int x)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		mlx_image_to_window(mlx, game \
		->image_player.image_left_animation[i], \
		x * g_game.pixel, y * g_game.pixel);
		game->image_player.image_left_animation[i++] \
		->instances[0].enabled = false;
	}
}
