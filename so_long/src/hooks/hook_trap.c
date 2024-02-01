/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_trap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:24:12 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/01 13:28:03 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	update_trap(mlx_t *mlx)
{
	int	animation;
	int i;
	
	animation = g_game.trap_animation.animation;
	i = 0;
	while (i < 5)
	{
		if (animation == 0)
			g_game.image_map.image_trap[4]->instances[i].enabled = false;
		else if (g_game.image_map.image_trap[animation - 1]->instances[i].enabled == true)
			g_game.image_map.image_trap[animation - 1]->instances[i].enabled = false;
		g_game.image_map.image_trap[animation]->instances[i++].enabled = true;
	}
}

void	hook_trap(void *param)
{
	int	time;
	int	animation;

	time = g_game.trap_animation.time;
	animation = g_game.trap_animation.animation;
	time ++;
	if (time % 10 == 0)
	{
		update_trap(param);
		animation++;
		if (animation == 5)
			animation = 0;
		time = 0;	
	}
}