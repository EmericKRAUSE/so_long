/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:36:18 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/02 10:24:12 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	moove_up(void)
{
	int	i;

	i = 0;
	g_game.image_player.image_character->instances[0].y -= 8;
	while (i < 5)
	{
		g_game.image_player.image_left_animation[i]->instances[0].y -= 8;
		g_game.image_player.image_right_animation[i++]->instances[0].y -= 8;
	}
}
