/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:55:22 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/26 15:29:02 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_image_player	init_image_player(mlx_t *mlx)
{
	t_image_player	images;

	images.texture_character = mlx_load_png("../assets/character/petite_image_1.png");
	images.texture_sword = mlx_load_png("../assets/character/sword.png");

	images.image_character = mlx_texture_to_image(mlx, images.texture_character);
	images.image_sword = mlx_texture_to_image(mlx, images.texture_sword);
	return (images);
}