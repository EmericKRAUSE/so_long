/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_character.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:07:33 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/25 17:01:18 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	display_character(mlx_t *mlx, t_game *g_game, int y, int x)
{
	int	pixels;

	pixels = 128;
	g_game->image_character = init_image_character(mlx);

	mlx_resize_image(g_game->image_character.image_character, 56, 112);
	
	mlx_image_to_window(mlx, g_game->image_character.image_character, x * pixels, y * pixels);
}