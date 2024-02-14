/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_image_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:35:58 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/14 13:36:48 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	resize_image_exit(void)
{
	int	i;

	i = 0;
	while (i < 4)
		mlx_resize_image(g_game.image_map.image_exit[i++], \
		g_game.pixel, g_game.pixel);
}