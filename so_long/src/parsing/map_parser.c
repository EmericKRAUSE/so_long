/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:40:11 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/19 11:36:33 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// Verifie que le contenue du tableau de tableau //
// et leurs nombres sont corrects //

void	map_component_is_valid(t_map *map)
{
	char	*component;
	int		y;
	int		x;

	component = "10CEP";
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (map->tab[y][x])
		{
			if (!ft_strchr(component, map->tab[y][x]))
				ft_map_error();
			if (map->tab[y][x] == 'C')
				map->collectible++;
			else if (map->tab[y][x] == 'E')
				map->exit++;
			else if (map->tab[y][x] == 'P')
				map->position++;
			x++;
		}
		y++;
	}
	if (map->collectible <= 0 || map->exit != 1 || map->position != 1)
		map->is_valid = 0;
}

// Verifie que le tableau de tableau est bien entoure de '1' //

void	map_wall_is_valid(t_map *map)
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
				ft_map_error();
			x++;
		}
		y++;
	}
}

// Parsing de la map //

t_map	map_parser(char *path_map)
{
	t_map	map;

	map = init_map();
	get_map_size(&map, path_map);
	create_map(&map);
	fill_map(&map, path_map);
	map_component_is_valid(&map);
	map_wall_is_valid(&map);
	path_is_valid(&map);
	return (map);
}
