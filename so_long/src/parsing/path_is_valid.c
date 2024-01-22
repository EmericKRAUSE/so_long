/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_is_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:46:21 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/22 10:35:33 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/****
* Alogithme flood fill en incrementant les variables collectible et exit
*/
static	void	flood_fill(t_map *flooded_map, int y, int x)
{
	if (y < 0 || y >= flooded_map->y || x < 0 || x >= flooded_map->x)
		return ;
	if (flooded_map->tab[y][x] == '1' || flooded_map->tab[y][x] == 'X')
		return ;
	if (flooded_map->tab[y][x] == 'C')
		flooded_map->collectible++;
	else if (flooded_map->tab[y][x] == 'E')
		flooded_map->exit++;
	flooded_map->tab[y][x] = 'X';
	flood_fill(flooded_map, y - 1, x);
	flood_fill(flooded_map, y + 1, x);
	flood_fill(flooded_map, y, x + 1);
	flood_fill(flooded_map, y, x - 1);
}

/****
* Duplique le tableau de tableau et les coordonees x et y
*/
static	t_map	map_dup(t_map *map)
{
	t_map	map_dup;
	int		y;
	int		x;

	map_dup = init_map();
	map_dup.x = map->x;
	map_dup.y = map->y;
	create_map(&map_dup);
	y = 0;
	while (y < map_dup.y)
	{
		x = 0;
		map_dup.tab[y][map->x] = '\0';
		while (x < map_dup.x)
		{
			map_dup.tab[y][x] = map->tab[y][x];
			x++;
		}
		y++;
	}
	return (map_dup);
}

/****
* Verifie que le chemin vers la sortie est valide
*/
int	path_is_valid(t_map *map)
{
	t_map	flooded_map;

	flooded_map = map_dup(map);
	flood_fill(&flooded_map, get_position(flooded_map, 'y'), \
	get_position(flooded_map, 'x'));
	if (flooded_map.collectible != map->collectible || \
	flooded_map.exit != map->exit)
	{
		free_map(*map);
		free_map(flooded_map);
		return (0);
	}
	free_map(flooded_map);
	return (1);
}
