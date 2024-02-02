/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:05:29 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/02 12:54:46 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static	void	add_data_to_node(t_game *game)
{
	t_list_component	*temp;
	int					c;
	int					t;

	temp = game->list_component;
	c = 0;
	t = 0;
	while (temp)
	{
		if (temp->type == 'C')
			temp->nb = c++;
		else if (temp->type == 'T')
			temp->nb = t++;
		else
			temp->nb = 0;
		temp = temp->next;
	}
}

static	void	add_to_list(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map.y)
	{
		x = -1;
		while (++x < game->map.x)
		{
			if (game->map.tab[y][x] == '1')
				game->list_component = create_node(game->list_component, \
				y * g_game.pixel, x * g_game.pixel, '1');
			else if (game->map.tab[y][x] == 'C')
				game->list_component = create_node(game->list_component, \
				y * g_game.pixel, x * g_game.pixel, 'C');
			else if (game->map.tab[y][x] == 'E')
				game->list_component = create_node(game->list_component, \
				y * g_game.pixel, x * g_game.pixel, 'E');
			else if (game->map.tab[y][x] == 'T')
				game->list_component = create_node(game->list_component, \
				y * g_game.pixel, x * g_game.pixel, 'T');
		}
	}
	add_data_to_node(game);
}

void	display_images(mlx_t *mlx, t_game *game)
{
	display_map(mlx, game);
	display_trap(mlx, game);
	add_to_list(game);
	display_player(mlx, game, game->player.y, game->player.x);
	display_ui(mlx, game);
}
