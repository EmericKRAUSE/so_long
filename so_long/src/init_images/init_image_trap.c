/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_trap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:53:02 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/05 11:55:57 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_image_trap(mlx_t *mlx, t_image_map *images)
{
	images->texture_trap[0] = mlx_load_png("../assets/map/trap1.png");
	images->texture_trap[1] = mlx_load_png("../assets/map/trap2.png");
	images->texture_trap[2] = mlx_load_png("../assets/map/trap3.png");
	images->texture_trap[3] = mlx_load_png("../assets/map/trap4.png");
	images->texture_trap[4] = mlx_load_png("../assets/map/trap5.png");
	images->image_trap[0] = mlx_texture_to_image(mlx, images->texture_trap[0]);
	images->image_trap[1] = mlx_texture_to_image(mlx, images->texture_trap[1]);
	images->image_trap[2] = mlx_texture_to_image(mlx, images->texture_trap[2]);
	images->image_trap[3] = mlx_texture_to_image(mlx, images->texture_trap[3]);
	images->image_trap[4] = mlx_texture_to_image(mlx, images->texture_trap[4]);
}
