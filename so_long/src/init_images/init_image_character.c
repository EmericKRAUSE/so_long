/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_character.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:55:22 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/25 15:58:46 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_image_character	init_image_character(mlx_t *mlx)
{
	t_image_character	images;

	images.texture_character = mlx_load_png("../assets/character/character.png");

	images.image_character = mlx_texture_to_image(mlx, images.texture_character);
	return (images);
}