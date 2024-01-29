/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:41:20 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/29 15:16:13 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static	t_image_ui	init_image_ui(mlx_t *mlx)
{
	t_image_ui	images;

	images.texture_heart_1 = mlx_load_png("../assets/UI/heart-1.png");
	images.texture_slot = mlx_load_png("../assets/UI/slot.png");
	images.image_heart_1 = mlx_texture_to_image(mlx, images.texture_heart_1);
	images.image_slot = mlx_texture_to_image(mlx, images.texture_slot);
	return (images);
}

static	t_image_player	init_image_player(mlx_t *mlx)
{
	t_image_player	images;

	images.texture_character[0] = \
	mlx_load_png("../assets/character/warrior1.png");
	images.texture_character[1] = \
	mlx_load_png("../assets/character/warrior2.png");
	images.texture_character[2] = \
	mlx_load_png("../assets/character/warrior3.png");
	images.texture_character[3] = \
	mlx_load_png("../assets/character/warrior4.png");
	images.texture_character[4] = \
	mlx_load_png("../assets/character/warrior5.png");
	images.image_character[0] = \
	mlx_texture_to_image(mlx, images.texture_character[0]);
	images.image_character[1] = \
	mlx_texture_to_image(mlx, images.texture_character[1]);
	images.image_character[2] = \
	mlx_texture_to_image(mlx, images.texture_character[2]);
	images.image_character[3] = \
	mlx_texture_to_image(mlx, images.texture_character[3]);
	images.image_character[4] = \
	mlx_texture_to_image(mlx, images.texture_character[4]);
	return (images);
}

static	t_image_map	init_image_map(mlx_t *mlx)
{
	t_image_map	images;

	images.texture_background = mlx_load_png("../assets/map/background.png");
	images.texture_wall = mlx_load_png("../assets/map/wall.png");
	images.texture_collectible = mlx_load_png("../assets/map/collectible.png");
	images.texture_exit = mlx_load_png("../assets/map/exit.png");
	images.image_background = \
	mlx_texture_to_image(mlx, images.texture_background);
	images.image_wall = mlx_texture_to_image(mlx, images.texture_wall);
	images.image_collectible = \
	mlx_texture_to_image(mlx, images.texture_collectible);
	images.image_exit = mlx_texture_to_image(mlx, images.texture_exit);
	return (images);
}

void	init_images(mlx_t *mlx, t_game *game)
{
	game->image_map = init_image_map(mlx);
	game->image_player = init_image_player(mlx);
	game->image_ui = init_image_ui(mlx);
	resize_image_map(mlx, game);
	resize_image_player(mlx, game);
	resize_image_ui(mlx, game);
}
