/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:33:55 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/01 13:33:00 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	animation_right(mlx_t *mlx)
{
	g_game.character_animation.time ++;
	if (g_game.character_animation.time % 10 == 0)
	{
		if (g_game.image_player.image_character->instances[0].enabled == true)
			g_game.image_player.image_character->instances[0].enabled = false;
		reset_animation();
		if (g_game.character_animation.animation == 0)
		{
			if (g_game.image_player.image_right_animation[4]->instances[0].enabled == true)
				g_game.image_player.image_right_animation[4]->instances[0].enabled = false;
		}
		else if (g_game.image_player.image_right_animation[g_game.character_animation.animation - 1]->instances[0].enabled == true)
			g_game.image_player.image_right_animation[g_game.character_animation.animation - 1]->instances[0].enabled = false;
		g_game.image_player.image_right_animation[g_game.character_animation.animation]->instances[0].enabled = true;
		g_game.character_animation.animation++;
		if (g_game.character_animation.animation == 5)
			g_game.character_animation.animation = 0;
		g_game.character_animation.time = 0;
	}
}