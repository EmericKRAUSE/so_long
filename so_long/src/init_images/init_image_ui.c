/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_ui.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:00:13 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/25 15:10:33 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_image_ui	init_image_ui(mlx_t *mlx)
{
	t_image_ui	images;

	images.texture_heart_1 = mlx_load_png("../assets/UI/heart-1.png");
	images.texture_heart_2 = mlx_load_png("../assets/UI/heart-5.png");
	images.texture_inventory = mlx_load_png("../assets/UI/inventory.png");
	images.texture_slot = mlx_load_png("../assets/UI/slot.png");

	images.image_heart_1 = mlx_texture_to_image(mlx, images.texture_heart_1);
	images.image_heart_2 = mlx_texture_to_image(mlx, images.texture_heart_2);
	images.image_inventory = mlx_texture_to_image(mlx, images.texture_inventory);
	images.image_slot = mlx_texture_to_image(mlx, images.texture_slot);
	return (images);
}