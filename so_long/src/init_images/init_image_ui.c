/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_ui.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:50:49 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/05 11:56:14 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_image_ui(mlx_t *mlx, t_image_ui *images)
{
	images->texture_heart_1 = mlx_load_png("../assets/UI/heart-1.png");
	images->texture_slot = mlx_load_png("../assets/UI/slot.png");
	images->image_heart_1 = mlx_texture_to_image(mlx, images->texture_heart_1);
	images->image_slot = mlx_texture_to_image(mlx, images->texture_slot);
}
