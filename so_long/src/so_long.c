/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:26:25 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/09 15:43:12 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game			g_game;

void	init_player(void)
{
	g_game.player.y = get_position(g_game.map, 'y');
	g_game.player.x = get_position(g_game.map, 'x');
	g_game.player.time = 0;
	g_game.player.animation = 0;
	g_game.player.collectible = 0;
	g_game.player.movement = 0;
}

void	hook_collision(void)
{
	int	y;
	int	x;

	y = g_game.image_player.image_character->instances[0].y;
	x = g_game.image_player.image_character->instances[0].x;
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
			if (!collision_event(temp))
				g_game.is_over = 1;
		temp = temp->next;
	}
}

// SO LONG //

static	void	so_long(char *file)
{
	mlx_t		*mlx;

	g_game.map = map_parser(file);
	g_game.pixel = 128;
	mlx = mlx_init(g_game.map.x * g_game.pixel, g_game.map.y * g_game.pixel, "game", true);
	g_game.time.time = 0;
	g_game.time.animation = 0;
	g_game.is_over = 0;
	init_player();
	init_images(mlx);
	resize_images();
	display_images(mlx, &g_game);
	

	mlx_loop_hook(mlx, &hook_close, mlx);
	mlx_loop_hook(mlx, &hook_movement, mlx);
	mlx_loop_hook(mlx, (void *)&hook_collision, mlx);
	mlx_loop_hook(mlx, (void *)&hook_trap, mlx);

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