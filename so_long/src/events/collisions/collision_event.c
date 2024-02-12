/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:30:24 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/12 15:03:40 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

int	collision_event(t_list_component *temp)
{
	if (temp->type == 'C' && g_game.image_map.image_collectible \
	->instances[temp->nb].enabled == true)
	{
		g_game.image_map.image_collectible->instances[temp->nb].enabled = false;
		g_game.player.collectible++;
	}
	else if (temp->type == 'T' && g_game.image_map.image_trap \
	[4]->instances[temp->nb].enabled == true)
		game_lose();
	else if (temp->type == 'E' && g_game.player.collectible \
	== g_game.map.collectible)
		game_win();
	return (1);
}
