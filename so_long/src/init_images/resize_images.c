/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:47:24 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/02 12:54:05 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	resize_image_ui(mlx_t *mlx, t_game *game)
{
	mlx_resize_image(game->image_ui.image_heart_1, \
	g_game.pixel, g_game.pixel);
	mlx_resize_image(game->image_ui.image_slot, \
	g_game.pixel, g_game.pixel);
}

void	resize_image_player(mlx_t *mlx, t_game *game)
{
	int	width;
	int	height;
	int	i;

	width = 68;
	height = 100;
	i = 0;
	mlx_resize_image(game->image_player.image_character, width, height);
	while (i < 5)
	{
		mlx_resize_image(game->image_player.image_right_animation[i], width, height);
		mlx_resize_image(game->image_player.image_left_animation[i++], width, height);
	}
}

void	resize_image_trap(mlx_t *mlx, t_game *game)
{
	int	i;

	i = 0;
	while (i < 5)
		mlx_resize_image(game->image_map.image_trap[i++], \
		g_game.pixel, g_game.pixel);
}

void	resize_image_map(mlx_t *mlx, t_game *game)
{
	mlx_resize_image(game->image_map.image_background, g_game.pixel, g_game.pixel);
	mlx_resize_image(game->image_map.image_wall, g_game.pixel, g_game.pixel);
	mlx_resize_image(game->image_map.image_collectible, g_game.pixel, g_game.pixel);
	mlx_resize_image(game->image_map.image_exit, g_game.pixel, g_game.pixel);
	resize_image_trap(mlx, game);
}
