/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:00:41 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/15 13:29:37 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	animation_up(void)
{
	g_game.player.time ++;
	if (g_game.player.time % 10 == 0)
	{
		g_game.image_player.image_character->instances[0].enabled = false;
		reset_animation();
		if (g_game.player.animation == 0)
			g_game.image_player.image_up_animation[5] \
			->instances[0].enabled = false;
		else if (g_game.image_player.image_up_animation \
		[g_game.player.animation - 1] \
		->instances[0].enabled == true)
			g_game.image_player.image_up_animation \
			[g_game.player.animation - 1] \
			->instances[0].enabled = false;
		g_game.image_player.image_up_animation \
		[g_game.player.animation]->instances[0].enabled = true;
		g_game.player.animation++;
		if (g_game.player.animation == 6)
			g_game.player.animation = 0;
		g_game.player.time = 0;
	}
}
