/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:26:25 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/01 11:49:20 by ekrause          ###   ########.fr       */
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
	if (g_time % 10 == 0)
	{
		update_trap(param);
		g_animation++;
		if (g_animation == 5)
			g_animation = 0;
		g_time = 0;	
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