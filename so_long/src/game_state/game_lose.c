/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_lose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:03:44 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/12 15:06:50 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"


void	game_lose()
{
	g_game.is_over = 1;
	g_game.image_ui.image_lose->enabled = true;
}