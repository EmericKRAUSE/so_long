/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_trap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:24:12 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/02 12:59:38 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	hook_trap(void *param)
{
	g_game.time.time ++;
	if (g_game.time.time % 10 == 0)
	{
		update_trap(param);
		g_game.time.animation++;
		if (g_game.time.animation == 5)
			g_game.time.animation = 0;
		g_game.time.time = 0;
	}
}
