/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:31:38 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/06 13:25:05 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	animation_left(void)
{
	g_game.player.time ++;
	if (g_game.player.time % 10 == 0)
	{
		g_game.image_player.image_character->instances[0].enabled = false;
		reset_animation();
		if (g_game.player.animation == 0)
			g_game.image_player.image_left_animation[4] \
			->instances[0].enabled = false;
		else if (g_game.image_player.image_left_animation \
		[g_game.player.animation - 1] \
		->instances[0].enabled == true)
			g_game.image_player.image_left_animation \
			[g_game.player.animation - 1] \
			->instances[0].enabled = false;
		g_game.image_player.image_left_animation \
		[g_game.player.animation]->instances[0].enabled = true;
		g_game.player.animation++;
		if (g_game.player.animation == 5)
			g_game.player.animation = 0;
		g_game.player.time = 0;
	}
}
