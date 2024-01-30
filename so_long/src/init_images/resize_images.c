/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:47:24 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/30 14:22:13 by ekrause          ###   ########.fr       */
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

	width = 68;
	height = 100;
	mlx_resize_image(game->image_player.image_character, width, height);
	mlx_resize_image(game->image_player.image_right_animation[0], width, height);
	mlx_resize_image(game->image_player.image_right_animation[1], width, height);
	mlx_resize_image(game->image_player.image_right_animation[2], width, height);
	mlx_resize_image(game->image_player.image_right_animation[3], width, height);
	mlx_resize_image(game->image_player.image_right_animation[4], width, height);
	mlx_resize_image(game->image_player.image_left_animation[0], width, height);
	mlx_resize_image(game->image_player.image_left_animation[1], width, height);
	mlx_resize_image(game->image_player.image_left_animation[2], width, height);
	mlx_resize_image(game->image_player.image_left_animation[3], width, height);
	mlx_resize_image(game->image_player.image_left_animation[4], width, height);
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
