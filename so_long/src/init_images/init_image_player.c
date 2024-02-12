/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:52:31 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/12 12:15:28 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_image_player(mlx_t *mlx)
{
	g_game.image_player.texture_character = \
	mlx_load_png("assets/character/character.png");
	g_game.image_player.image_character = \
	mlx_texture_to_image(mlx, g_game.image_player.texture_character);
}
