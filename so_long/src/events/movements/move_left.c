/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:36:10 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/15 14:53:57 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	moove_left(void)
{
	int	i;

	i = 0;
	g_game.image_player.image_character->instances[0].x -= 8;
	while (i < 6)
	{
		g_game.image_player.image_left_animation[i]->instances[0].x -= 8;
		g_game.image_player.image_right_animation[i]->instances[0].x -= 8;
		g_game.image_player.image_up_animation[i]->instances[0].x -= 8;
		g_game.image_player.image_down_animation[i++]->instances[0].x -= 8;
	}
	animation_left();
	g_game.player.movement++;
}
