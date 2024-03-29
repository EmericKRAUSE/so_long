/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:41:18 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/15 14:54:56 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	reset_animation(void)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (g_game.image_player.image_left_animation[i] \
		->instances[0].enabled == true)
			g_game.image_player.image_left_animation[i] \
			->instances[0].enabled = false;
		if (g_game.image_player.image_right_animation[i] \
		->instances[0].enabled == true)
			g_game.image_player.image_right_animation[i] \
			->instances[0].enabled = false;
		if (g_game.image_player.image_up_animation[i] \
		->instances[0].enabled == true)
			g_game.image_player.image_up_animation[i] \
			->instances[0].enabled = false;
		if (g_game.image_player.image_down_animation[i] \
		->instances[0].enabled == true)
			g_game.image_player.image_down_animation[i] \
			->instances[0].enabled = false;
		i++;
	}
}
