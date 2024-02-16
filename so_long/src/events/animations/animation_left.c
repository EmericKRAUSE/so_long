/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:31:38 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/16 11:09:36 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	animation_left(void)
{
	if (g_game.player.time % 10 == 0)
	{
		g_game.image_player.image_character->instances[0].enabled = false;
		reset_animation();
		if (g_game.player.animation == 0)
			g_game.image_player.image_left_animation[5] \
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
		if (g_game.player.animation == 6)
			g_game.player.animation = 0;
		g_game.player.time = 0;
	}
	g_game.player.time ++;
}
