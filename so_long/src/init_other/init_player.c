/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:08:54 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/16 11:02:46 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_player(void)
{
	g_game.player.y = get_position(g_game.map, 'y');
	g_game.player.x = get_position(g_game.map, 'x');
	g_game.player.time = 9;
	g_game.player.animation = 0;
	g_game.player.collectible = 0;
	g_game.player.movement = 0;
}
