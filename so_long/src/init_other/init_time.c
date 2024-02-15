/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:07:16 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/15 15:19:58 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_time(void)
{
	g_game.time.time = 0;
	g_game.time.animation_trap = 0;
	g_game.time.animation_exit = 0;
}
