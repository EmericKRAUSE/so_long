/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:41:18 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/01 13:19:25 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	reset_animation()
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (g_game.image_player.image_left_animation[i]->instances[0].enabled = true);
			g_game.image_player.image_left_animation[i]->instances[0].enabled = false;
		if (g_game.image_player.image_right_animation[i]->instances[0].enabled = true);
			g_game.image_player.image_right_animation[i++]->instances[0].enabled = false;
	}
}
