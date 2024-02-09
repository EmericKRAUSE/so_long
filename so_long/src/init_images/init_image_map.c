/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:50:08 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/09 15:09:17 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_image_map(mlx_t *mlx)
{
	g_game.image_map.texture_background = mlx_load_png \
	("../assets/map/background.png");
	g_game.image_map.texture_wall = mlx_load_png \
	("../assets/map/wall.png");
	g_game.image_map.texture_collectible = mlx_load_png \
	("../assets/map/collectible.png");
	g_game.image_map.texture_exit = mlx_load_png \
	("../assets/map/exit.png");
	g_game.image_map.image_background = mlx_texture_to_image \
	(mlx, g_game.image_map.texture_background);
	g_game.image_map.image_wall = mlx_texture_to_image \
	(mlx, g_game.image_map.texture_wall);
	g_game.image_map.image_collectible = mlx_texture_to_image \
	(mlx, g_game.image_map.texture_collectible);
	g_game.image_map.image_exit = mlx_texture_to_image \
	(mlx, g_game.image_map.texture_exit);
}
