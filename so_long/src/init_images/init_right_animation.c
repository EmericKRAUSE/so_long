/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_right_animation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:51:46 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/05 11:56:14 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_right_animation(mlx_t *mlx, t_image_player *images)
{
	int	i;

	i = -1;
	images->texture_right_animation[0] = \
	mlx_load_png("../assets/character/right1.png");
	images->texture_right_animation[1] = \
	mlx_load_png("../assets/character/right2.png");
	images->texture_right_animation[2] = \
	mlx_load_png("../assets/character/right3.png");
	images->texture_right_animation[3] = \
	mlx_load_png("../assets/character/right4.png");
	images->texture_right_animation[4] = \
	mlx_load_png("../assets/character/right5.png");
	while (++i < 5)
		images->image_right_animation[i] = \
		mlx_texture_to_image(mlx, images->texture_right_animation[i]);
}
