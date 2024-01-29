/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:26:25 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/29 11:30:08 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game			g_game;
int				g_pixels = 128;

t_player	init_player(mlx_t *mlx)
{
	t_player	player;
	
	player.y = get_position(g_game.map, 'y');
	player.x = get_position(g_game.map, 'x');
	player.collectible = 0;
	return (player);
}

// SO LONG //

int	collision_event(t_list_component *temp)
{
	if (temp->type == '1')
		return (0);
	else if (temp->type == 'C' && g_game.image_map.image_collectible->instances[temp->nb].enabled == true)
	{
		g_game.image_map.image_collectible->instances[temp->nb].enabled = false;
		g_game.player.collectible++;
	}
	else if (temp->type == 'E' && g_game.player.collectible == g_game.map.collectible)
		g_game.image_player.image_character->instances[0].enabled = false;
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
				return (1);
		temp = temp->next;
	}
	return (0);
}

void hook(void* param)
{
	int y;
	int	x;

	y = g_game.image_player.image_character->instances[0].y;
	x = g_game.image_player.image_character->instances[0].x;

    if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
        mlx_close_window(param);
    if (mlx_is_key_down(param, MLX_KEY_W) && !check_collision(y - 8, x))
		g_game.image_player.image_character->instances[0].y -= 8;
    if (mlx_is_key_down(param, MLX_KEY_S) && !check_collision(y + 8, x))
        g_game.image_player.image_character->instances[0].y += 8;
    if (mlx_is_key_down(param, MLX_KEY_A) && !check_collision(y, x - 8))
        g_game.image_player.image_character->instances[0].x -= 8;
    if (mlx_is_key_down(param, MLX_KEY_D) && !check_collision(y, x + 8))
        g_game.image_player.image_character->instances[0].x += 8;
}

static	void	so_long(char *file)
{
	mlx_t		*mlx;

	g_game.map = map_parser(file);
	mlx = mlx_init(g_game.map.x * g_pixels, g_game.map.y * g_pixels, "game", true);
	g_game.player = init_player(mlx);

	display_map(mlx, &g_game);
	display_player(mlx, &g_game, g_game.player.y, g_game.player.x);
	display_ui(mlx, &g_game);

	mlx_loop_hook(mlx, &hook, mlx);
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