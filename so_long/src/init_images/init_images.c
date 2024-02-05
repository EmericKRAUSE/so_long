/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:41:20 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/05 11:52:50 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_images(mlx_t *mlx, t_game *game)
{
	init_image_map(mlx, &game->image_map);
	init_image_player(mlx, &game->image_player);
	init_image_ui(mlx, &game->image_ui);
	resize_image_map(mlx, game);
	resize_image_player(mlx, game);
	resize_image_ui(mlx, game);
}
