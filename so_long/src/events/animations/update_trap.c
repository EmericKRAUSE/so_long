/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   udpate_trap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:51:12 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/14 14:43:57 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	update_trap(void)
{
	int	i;

	i = 0;
	while (i < g_game.map.trap)
	{
		if (g_game.time.animation_trap == 0)
			g_game.image_map.image_trap[8]->instances[i].enabled = false;
		else if (g_game.image_map.image_trap \
		[g_game.time.animation_trap - 1] \
		->instances[i].enabled == true)
			g_game.image_map.image_trap[g_game.time.animation_trap - 1] \
			->instances[i].enabled = false;
		g_game.image_map.image_trap[g_game.time.animation_trap] \
		->instances[i++].enabled = true;
	}
}
