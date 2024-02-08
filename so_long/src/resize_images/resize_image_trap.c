/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_image_trap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:13:12 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/08 10:19:22 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	resize_image_trap(void)
{
	int	i;

	i = 0;
	while (i < 5)
		mlx_resize_image(g_game.image_map.image_trap[i++], \
		g_game.pixel, g_game.pixel);
}
