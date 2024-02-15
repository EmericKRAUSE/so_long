/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:41:20 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/15 14:16:44 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_images(mlx_t *mlx)
{
	init_image_map(mlx);
	init_image_player(mlx);
	init_image_trap(mlx);
	init_image_exit(mlx);
	init_image_ui(mlx);
	init_left_animation(mlx);
	init_right_animation(mlx);
	init_up_animation(mlx);
	init_down_animation(mlx);
}
