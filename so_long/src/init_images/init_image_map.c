/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:50:08 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/06 13:23:22 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_image_map(mlx_t *mlx, t_image_map *images)
{
	images->texture_background = mlx_load_png("../assets/map/background.png");
	images->texture_wall = mlx_load_png("../assets/map/wall.png");
	images->texture_collectible = mlx_load_png("../assets/map/collectible.png");
	images->texture_exit = mlx_load_png("../assets/map/exit.png");
	images->image_background = \
	mlx_texture_to_image(mlx, images->texture_background);
	images->image_wall = mlx_texture_to_image(mlx, images->texture_wall);
	images->image_collectible = \
	mlx_texture_to_image(mlx, images->texture_collectible);
	images->image_exit = mlx_texture_to_image(mlx, images->texture_exit);
	init_image_trap(mlx, images);
}
