/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:52:31 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/05 11:56:20 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_image_player(mlx_t *mlx, t_image_player *images)
{
	images->texture_character = \
	mlx_load_png("../assets/character/character.png");
	images->image_character = \
	mlx_texture_to_image(mlx, images->texture_character);
	init_right_animation(mlx, images);
	init_left_animation(mlx, images);
}
