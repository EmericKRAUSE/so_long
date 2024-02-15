/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:50:26 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/15 10:58:27 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	update_exit(void)
{
	if (g_game.time.animation_exit == 0)
		g_game.image_map.image_exit[3]->instances[0].enabled = false;
	else if (g_game.image_map.image_exit \
	[g_game.time.animation_exit - 1] \
	->instances[0].enabled == true)
		g_game.image_map.image_exit[g_game.time.animation_exit - 1] \
		->instances[0].enabled = false;
	g_game.image_map.image_exit[g_game.time.animation_exit] \
	->instances[0].enabled = true;
}
