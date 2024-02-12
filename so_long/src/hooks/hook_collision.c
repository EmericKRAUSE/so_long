/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:08:38 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/12 16:12:11 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	hook_collision(void)
{
	t_list_component	*temp;
	int					y;
	int					x;

	y = g_game.image_player.image_character->instances[0].y;
	x = g_game.image_player.image_character->instances[0].x;
	temp = g_game.list_component;
	while (temp)
	{
		if (!(y + g_game.image_player.image_character->height \
		<= (unsigned int)temp->y \
		|| y >= temp->y + g_game.pixel \
		|| x + g_game.image_player.image_character->width <= \
		(unsigned int)temp->x \
		|| x >= temp->x + g_game.pixel))
			if (!collision_event(temp))
				g_game.is_over = 1;
		temp = temp->next;
	}
}
