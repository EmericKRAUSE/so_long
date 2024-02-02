/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   udpate_trap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:51:12 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/02 09:59:47 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	update_trap(mlx_t *mlx)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (g_game.trap_animation.animation == 0)
			g_game.image_map.image_trap[4]->instances[i].enabled = false;
		else if (g_game.image_map.image_trap \
		[g_game.trap_animation.animation - 1] \
		->instances[i].enabled == true)
			g_game.image_map.image_trap[g_game.trap_animation.animation - 1] \
			->instances[i].enabled = false;
		g_game.image_map.image_trap[g_game.trap_animation.animation] \
		->instances[i++].enabled = true;
	}
}