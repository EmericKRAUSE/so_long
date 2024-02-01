/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:19:25 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/01 11:50:16 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	reset_animation()
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (g_game.image_player.image_left_animation[i]->instances[0].enabled = true);
			g_game.image_player.image_left_animation[i]->instances[0].enabled = false;
		if (g_game.image_player.image_right_animation[i]->instances[0].enabled = true);
			g_game.image_player.image_right_animation[i++]->instances[0].enabled = false;
	}
}

void	animation1(mlx_t *mlx)
{
	g_time2 ++;
	if (g_time2 % 10 == 0)
	{
		g_game.image_player.image_character->instances[0].enabled = false;
		reset_animation();
		if (g_animation2 == 0)
			g_game.image_player.image_left_animation[4]->instances[0].enabled = false;
		else if (g_game.image_player.image_left_animation[g_animation2 - 1]->instances[0].enabled == true)
			g_game.image_player.image_left_animation[g_animation2 - 1]->instances[0].enabled = false;
		g_game.image_player.image_left_animation[g_animation2]->instances[0].enabled = true;
		g_animation2++;
		if (g_animation2 == 5)
			g_animation2 = 0;
		g_time2 = 0;	
	}
}

void	animation2(mlx_t *mlx)
{
	g_time2 ++;
	if (g_time2 % 10 == 0)
	{
		g_game.image_player.image_character->instances[0].enabled = false;
		reset_animation();
		if (g_animation2 == 0)
			g_game.image_player.image_right_animation[4]->instances[0].enabled = false;
		else if (g_game.image_player.image_right_animation[g_animation2 - 1]->instances[0].enabled == true)
			g_game.image_player.image_right_animation[g_animation2 - 1]->instances[0].enabled = false;
		g_game.image_player.image_right_animation[g_animation2]->instances[0].enabled = true;
		g_animation2++;
		if (g_animation2 == 5)
			g_animation2 = 0;
		g_time2 = 0;	
	}
}

int	collision_event(t_list_component *temp)
{
	if (temp->type == '1')
		return (0);
	else if (temp->type == 'C' && g_game.image_map.image_collectible->instances[temp->nb].enabled == true)
	{
		g_game.image_map.image_collectible->instances[temp->nb].enabled = false;
		g_game.player.collectible++;
	}
	else if (temp->type == 'T' && g_game.image_map.image_trap[temp->nb]->instances->enabled == true)
		g_over = 1;
	else if (temp->type == 'E' && g_game.player.collectible == g_game.map.collectible)
		g_over = 1;
	return (1);
}

int	check_collision(int y, int x)
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

void	moove_up()
{
	int	i;

	i = 0;
	g_game.image_player.image_character->instances[0].y -= 8;
	while (i < 5)
	{
		g_game.image_player.image_left_animation[i]->instances[0].y -= 8;
		g_game.image_player.image_right_animation[i++]->instances[0].y -= 8;
	}
}

void	moove_down()
{
	int	i;

	i = 0;
	g_game.image_player.image_character->instances[0].y += 8;
	while (i < 5)
	{
		g_game.image_player.image_left_animation[i]->instances[0].y += 8;
		g_game.image_player.image_right_animation[i++]->instances[0].y += 8;
	}
}

void	moove_left()
{
	int	i;

	i = 0;
	g_game.image_player.image_character->instances[0].x -= 8;
	while (i < 5)
	{
		g_game.image_player.image_left_animation[i]->instances[0].x -= 8;
		g_game.image_player.image_right_animation[i++]->instances[0].x -= 8;
	}
}

void	moove_right()
{
	int	i;

	i = 0;
	g_game.image_player.image_character->instances[0].x += 8;
	while (i < 5)
	{
		g_game.image_player.image_left_animation[i]->instances[0].x += 8;
		g_game.image_player.image_right_animation[i++]->instances[0].x += 8;
	}
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
		animation1(param);
	}
    if (mlx_is_key_down(param, MLX_KEY_D) && check_collision(y, x + 8))
	{
		moove_right();
		animation2(param);
	}
	if (!mlx_is_key_down(param, MLX_KEY_W) && !mlx_is_key_down(param, MLX_KEY_S) && !mlx_is_key_down(param, MLX_KEY_A) && !mlx_is_key_down(param, MLX_KEY_D))
	{
		reset_animation();
		g_game.image_player.image_character->instances[0].enabled = true;
	}
}