/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:40:11 by ekrause           #+#    #+#             */
/*   Updated: 2024/02/02 12:29:33 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/****
* Verifie que le contenue du tableau de tableau
* et leurs nombres sont corrects
*/
static	int	map_component_is_valid(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (map->tab[y][x])
		{
			if (!ft_strchr(map->component, map->tab[y][x]))
				return (0);
			if (map->tab[y][x] == 'C')
				map->collectible++;
			else if (map->tab[y][x] == 'T')
				map->trap++;
			else if (map->tab[y][x] == 'E')
				map->exit++;
			else if (map->tab[y][x] == 'P')
				map->position++;
			x++;
		}
		y++;
	}
	return (map->collectible > 0 && map->exit == 1 && map->position == 1);
}

/****
* Verifie que le tableau de tableau est bien entoure de '1'
*/
static	int	map_wall_is_valid(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (map->tab[y][x])
		{
			if ((y == 0 || y == map->y - 1 || \
			x == 0 || x == map->x - 1) && map->tab[y][x] != '1')
			{
				free_map(*map);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

/****
* Parsing de la map
*/
t_map	map_parser(char *file)
{
	t_map	map;

	map = init_map();
	if (!get_map_size(&map, file))
		ft_error("size is not valid");
	if (!create_map(&map))
		ft_error("malloc failed");
	fill_map(&map, file);
	if (!map_component_is_valid(&map))
	{
		free_map(map);
		ft_error("components are not valid");
	}
	if (!map_wall_is_valid(&map))
		ft_error("map is not surrounded by walls");
	if (!path_is_valid(&map))
		ft_error("path is not valid");
	return (map);
}
