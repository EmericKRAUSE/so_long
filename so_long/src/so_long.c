/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:26:25 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/30 14:29:56 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game			g_game;
int				g_pixels = 128;
int				g_time = 0;
int				g_time2 = 0;
int				g_animation = 0;
int				g_animation2 = 0;
int				g_over = 0;

t_player	init_player(mlx_t *mlx)
{
	t_player	player;
	
	player.y = get_position(g_game.map, 'y');
	player.x = get_position(g_game.map, 'x');
	player.collectible = 0;
	return (player);
}

// SO LONG //

void	game_over()
{

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

void	animation1(mlx_t *mlx)
{
	g_time2 ++;
	if (g_time2 % 10 == 0)
	{
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

void hook_movement(void* param)
{
	int y;
	int	x;
	y = g_game.image_player.image_character->instances[0].y;
	x = g_game.image_player.image_character->instances[0].x;

    if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
        mlx_close_window(param);
    if (mlx_is_key_down(param, MLX_KEY_W) && check_collision(y - 8, x))
	{
		g_game.image_player.image_left_animation[0]->instances[0].y -= 8;
		g_game.image_player.image_left_animation[1]->instances[0].y -= 8;
		g_game.image_player.image_left_animation[2]->instances[0].y -= 8;
		g_game.image_player.image_left_animation[3]->instances[0].y -= 8;
		g_game.image_player.image_left_animation[4]->instances[0].y -= 8;
		g_game.image_player.image_right_animation[0]->instances[0].y -= 8;
		g_game.image_player.image_right_animation[1]->instances[0].y -= 8;
		g_game.image_player.image_right_animation[2]->instances[0].y -= 8;
		g_game.image_player.image_right_animation[3]->instances[0].y -= 8;
		g_game.image_player.image_right_animation[4]->instances[0].y -= 8;
	}
    if (mlx_is_key_down(param, MLX_KEY_S) && check_collision(y + 8, x))
	{
		g_game.image_player.image_left_animation[0]->instances[0].y += 8;
		g_game.image_player.image_left_animation[1]->instances[0].y += 8;
		g_game.image_player.image_left_animation[2]->instances[0].y += 8;
		g_game.image_player.image_left_animation[3]->instances[0].y += 8;
		g_game.image_player.image_left_animation[4]->instances[0].y += 8;
		g_game.image_player.image_right_animation[0]->instances[0].y += 8;
		g_game.image_player.image_right_animation[1]->instances[0].y += 8;
		g_game.image_player.image_right_animation[2]->instances[0].y += 8;
		g_game.image_player.image_right_animation[3]->instances[0].y += 8;
		g_game.image_player.image_right_animation[4]->instances[0].y += 8;
	}
    if (mlx_is_key_down(param, MLX_KEY_A) && check_collision(y, x - 8))
	{
		g_game.image_player.image_left_animation[0]->instances[0].x -= 8;
		g_game.image_player.image_left_animation[1]->instances[0].x -= 8;
		g_game.image_player.image_left_animation[2]->instances[0].x -= 8;
		g_game.image_player.image_left_animation[3]->instances[0].x -= 8;
		g_game.image_player.image_left_animation[4]->instances[0].x -= 8;
		g_game.image_player.image_right_animation[0]->instances[0].x -= 8;
		g_game.image_player.image_right_animation[1]->instances[0].x -= 8;
		g_game.image_player.image_right_animation[2]->instances[0].x -= 8;
		g_game.image_player.image_right_animation[3]->instances[0].x -= 8;
		g_game.image_player.image_right_animation[4]->instances[0].x -= 8;
		animation1(param);
	}
    if (mlx_is_key_down(param, MLX_KEY_D) && check_collision(y, x + 8))
	{
		g_game.image_player.image_left_animation[0]->instances[0].x += 8;
		g_game.image_player.image_left_animation[1]->instances[0].x += 8;
		g_game.image_player.image_left_animation[2]->instances[0].x += 8;
		g_game.image_player.image_left_animation[3]->instances[0].x += 8;
		g_game.image_player.image_left_animation[4]->instances[0].x += 8;
		g_game.image_player.image_right_animation[0]->instances[0].x += 8;
		g_game.image_player.image_right_animation[1]->instances[0].x += 8;
		g_game.image_player.image_right_animation[2]->instances[0].x += 8;
		g_game.image_player.image_right_animation[3]->instances[0].x += 8;
		g_game.image_player.image_right_animation[4]->instances[0].x += 8;
		animation2(param);
	}
}

void	update_trap(mlx_t *mlx)
{
	int i = 0;
	while (i < 5)
	{
		if (g_animation == 0)
			g_game.image_map.image_trap[4]->instances[i].enabled = false;
		else if (g_game.image_map.image_trap[g_animation - 1]->instances[i].enabled == true)
			g_game.image_map.image_trap[g_animation - 1]->instances[i].enabled = false;
		g_game.image_map.image_trap[g_animation]->instances[i++].enabled = true;
	}
}

void	hook_time_animation(void *param)
{
	g_time ++;
	if (g_time % 15 == 0)
	{
		update_trap(param);
		g_animation++;
		if (g_animation == 5)
			g_animation = 0;
		g_time = 0;	
	}
}

void	is_over(void *param)
{
	if (g_over == 1)
	{
		mlx_close_window(param);
	}
}

static	void	so_long(char *file)
{
	mlx_t		*mlx;

	g_game.map = map_parser(file);
	mlx = mlx_init(g_game.map.x * g_pixels, g_game.map.y * g_pixels, "game", true);
	g_game.player = init_player(mlx);

	init_images(mlx, &g_game);
	display_images(mlx, &g_game);

	mlx_loop_hook(mlx, &hook_movement, mlx);
	mlx_loop_hook(mlx, &hook_time_animation, mlx);
	mlx_loop_hook(mlx, &is_over, mlx);
	mlx_loop(mlx);
	
	free_map(g_game.map);
	free_list(&g_game.list_component);
	mlx_terminate(mlx);
}

static	int	is_ber(char *file)
{
	int	len;

	if (!file)
		return (0);
	len = ft_strlen(file);
	if (len < 5)
		return (0);
	if (!ft_strcmp(file + len - 4, ".ber"))
		return (0);
	return 1;
}

int	main(int argc, char **argv)
{
	char	*file;

	if (argc != 2)
		ft_error("please put one argument");
	file = argv[1];
	if (!is_ber(file))
		ft_error("please put a valid file");
	so_long(file);
	return (0);
}

// SO LONG //