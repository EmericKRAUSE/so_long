/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_trap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:24:12 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/02 09:55:16 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	hook_trap(void *param)
{
	g_game.trap_animation.time ++;
	if (g_game.trap_animation.time % 10 == 0)
	{
		update_trap(param);
		g_game.trap_animation.animation++;
		if (g_game.trap_animation.animation == 5)
			g_game.trap_animation.animation = 0;
		g_game.trap_animation.time = 0;	
	}
}