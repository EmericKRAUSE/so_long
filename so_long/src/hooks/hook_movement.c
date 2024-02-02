/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:19:25 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/02 10:22:38 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static	int	check_collision(int y, int x)
{
	t_list_component	*temp;

	temp = g_game.list_component;

	while (temp)
	{
		if (!(y + g_game.image_player.image_character->height <= temp->y 
		|| y >= temp->y + g_pixels 
		|| x + g_game.image_player.image_character->width <= temp->x 
		|| x >= temp->x + g_pixels))
			if (!collision_event(temp))
				return (0);
		temp = temp->next;
	}
	return (1);
}

void hook_movement(void* param)
{
	int y;
	int	x;
	y = g_game.image_player.image_character->instances[0].y;
	x = g_game.image_player.image_character->instances[0].x;

    if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
    	mlx_close_window(param);
    if (mlx_is_key_down(param, MLX_KEY_W) && check_collision(y - 8, x))
		moove_up();
    if (mlx_is_key_down(param, MLX_KEY_S) && check_collision(y + 8, x))
		moove_down();
    if (mlx_is_key_down(param, MLX_KEY_A) && check_collision(y, x - 8))
	{
		moove_left();
		animation_left(param);
	}
    if (mlx_is_key_down(param, MLX_KEY_D) && check_collision(y, x + 8))
	{
		moove_right();
		animation_right(param);
	}
	if (!mlx_is_key_down(param, MLX_KEY_W) && !mlx_is_key_down(param, MLX_KEY_S) && !mlx_is_key_down(param, MLX_KEY_A) && !mlx_is_key_down(param, MLX_KEY_D))
	{
		reset_animation();
		g_game.image_player.image_character->instances[0].enabled = true;
	}
}
