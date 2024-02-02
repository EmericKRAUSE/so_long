/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_right_animation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:32:44 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/02 12:49:25 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	display_right_animation(mlx_t *mlx, t_game *game, int y, int x)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		mlx_image_to_window(mlx, game \
		->image_player.image_right_animation[i], \
		x * g_game.pixel, y * g_game.pixel);
		game->image_player.image_right_animation[i++] \
		->instances[0].enabled = false;
	}
}
