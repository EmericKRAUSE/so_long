/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_trap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:24:12 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/15 10:50:11 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
		g_game.time.animation_exit++;
		if (g_game.time.animation_trap == 9)
			g_game.time.animation_trap = 0;
		if (g_game.time.animation_exit == 4)
			g_game.time.animation_exit = 0;
		g_game.time.time = 0;
	}
}
