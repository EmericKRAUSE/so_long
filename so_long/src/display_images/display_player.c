/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:33:34 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/02 10:33:37 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	display_player(mlx_t *mlx, t_game *game, int y, int x)
{
	int	pixels;

	pixels = 128;
	mlx_image_to_window(mlx, game->image_player.image_character, \
	x * pixels, y * pixels);
	display_right_animation(mlx, game, y, x);
	display_left_animation(mlx, game, y, x);
}
