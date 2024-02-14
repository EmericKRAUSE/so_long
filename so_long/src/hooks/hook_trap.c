/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_trap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:24:12 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/14 14:45:57 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	update_exit(void)
{
	int	i;

	i = 0;
	if (g_game.time.animation_exit == 0)
		g_game.image_map.image_exit[8]->instances[i].enabled = false;
	else if (g_game.image_map.image_exit \
	[g_game.time.animation_exit - 1] \
	->instances[i].enabled == true)
		g_game.image_map.image_exit[g_game.time.animation_exit - 1] \
		->instances[i].enabled = false;
	g_game.image_map.image_exit[g_game.time.animation_exit] \
	->instances[i++].enabled = true;
}

void	hook_trap(void)
{
	if (g_game.is_over == 1)
		return ;
	g_game.time.time ++;
	if (g_game.time.time % 10 == 0)
	{
		update_trap();
		update_exit();
		g_game.time.animation_trap++;
		if (g_game.time.animation_trap == 9)
			g_game.time.animation_trap = 0;
		g_game.time.time = 0;
	}
}
