/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_left_animation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:51:20 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/05 11:56:14 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_left_animation(mlx_t *mlx, t_image_player *images)
{
	int	i;

	i = -1;
	images->texture_left_animation[0] = \
	mlx_load_png("../assets/character/left1.png");
	images->texture_left_animation[1] = \
	mlx_load_png("../assets/character/left2.png");
	images->texture_left_animation[2] = \
	mlx_load_png("../assets/character/left3.png");
	images->texture_left_animation[3] = \
	mlx_load_png("../assets/character/left4.png");
	images->texture_left_animation[4] = \
	mlx_load_png("../assets/character/left5.png");
	while (++i < 5)
		images->image_left_animation[i] = \
		mlx_texture_to_image(mlx, images->texture_left_animation[i]);
}
