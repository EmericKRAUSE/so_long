/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:19:25 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/15 13:34:53 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static	int	check_collision(int y, int x)
{
	t_list_component	*temp;

	temp = g_game.list_component;
	while (temp)
	{
		if (!(y + g_game.image_player.image_character->height \
		<= (unsigned int)temp->y \
		|| y >= temp->y + g_game.pixel \
		|| x + g_game.image_player.image_character->width <= \
		(unsigned int)temp->x \
		|| x >= temp->x + g_game.pixel))
			if (temp->type == '1')
				return (0);
		temp = temp->next;
	}
	return (1);
}

static	void	reset_player(void)
{
	reset_animation();
	g_game.image_player.image_character->instances[0].enabled = true;
}

static	void	put_movement(mlx_t *mlx)
{
	char	*str;

	mlx_delete_image(mlx, g_game.movement_string);
	str = ft_itoa(g_game.player.movement);
	g_game.movement_string = mlx_put_string(mlx, str, 0, 0);
	free(str);
}

void	hook_movement(void *param)
{
	int		y;
	int		x;

	if (g_game.is_over == 1)
		return ;
	y = g_game.image_player.image_character->instances[0].y;
	x = g_game.image_player.image_character->instances[0].x;
	if (mlx_is_key_down(param, MLX_KEY_W) && check_collision(y - 8, x))
		moove_up();
	else if (mlx_is_key_down(param, MLX_KEY_S) && check_collision(y + 8, x))
		moove_down();
	else if (mlx_is_key_down(param, MLX_KEY_A) && check_collision(y, x - 8))
		moove_left();
	else if (mlx_is_key_down(param, MLX_KEY_D) && check_collision(y, x + 8))
		moove_right();
	else
		reset_player();
	put_movement(param);
}
