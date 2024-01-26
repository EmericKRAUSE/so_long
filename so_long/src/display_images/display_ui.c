/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:09:45 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/26 12:21:18 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	display_ui(mlx_t *mlx, t_game *game)
{
	int	pixels;
	int	x;

	pixels = 128;
	x = 0;
	game->image_ui = init_image_ui(mlx);

	mlx_resize_image(game->image_ui.image_heart_1, pixels, pixels);
	mlx_resize_image(game->image_ui.image_slot, pixels, pixels);

	mlx_image_to_window(mlx, game->image_ui.image_heart_1, 0, game->map.y * pixels - pixels * 2);
	while (x < 4)
	{
		mlx_image_to_window(mlx, game->image_ui.image_slot, x * pixels, game->map.y * pixels - pixels);
		x++;
	}
}