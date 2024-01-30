/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:47:24 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/30 10:36:06 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	resize_image_ui(mlx_t *mlx, t_game *game)
{
	int	pixels;

	pixels = 128;
	mlx_resize_image(game->image_ui.image_heart_1, pixels, pixels);
	mlx_resize_image(game->image_ui.image_slot, pixels, pixels);
}

void	resize_image_player(mlx_t *mlx, t_game *game)
{
	int	width;
	int	height;

	width = 75;
	height = 110;
	mlx_resize_image(game->image_player.image_character[0], width, height);
}

void	resize_image_trap(mlx_t *mlx, t_game *game)
{
	int	pixels;

	pixels = 128;
	mlx_resize_image(game->image_map.image_trap[0], pixels, pixels);
	mlx_resize_image(game->image_map.image_trap[1], pixels, pixels);
	mlx_resize_image(game->image_map.image_trap[2], pixels, pixels);
	mlx_resize_image(game->image_map.image_trap[3], pixels, pixels);
	mlx_resize_image(game->image_map.image_trap[4], pixels, pixels);
}

void	resize_image_map(mlx_t *mlx, t_game *game)
{
	int	pixels;

	pixels = 128;
	mlx_resize_image(game->image_map.image_background, pixels, pixels);
	mlx_resize_image(game->image_map.image_wall, pixels, pixels);
	mlx_resize_image(game->image_map.image_collectible, pixels, pixels);
	mlx_resize_image(game->image_map.image_exit, pixels, pixels);
	resize_image_trap(mlx, game);
}
