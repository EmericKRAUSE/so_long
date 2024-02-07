/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:41:20 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/07 14:39:08 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_images(mlx_t *mlx)
{
	init_image_map(mlx);
	init_image_player(mlx);
	init_image_ui(mlx);
	resize_image_map();
	resize_image_player();
	resize_image_ui();
}
