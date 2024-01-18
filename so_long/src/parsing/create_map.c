/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:33:49 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/18 09:43:10 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// Initialise la t_map avec les valeurs par defaut //

t_map	init_map(void)
{
	t_map	map;

	map.tab = NULL;
	map.x = 0;
	map.y = 0;
	map.collectible = 0;
	map.exit = 0;
	map.position = 0;
	map.is_valid = 1;
	return (map);
}

// Free le tableau de tableau //

void	free_map(t_map map)
{
	int	y;

	if (!map.tab)
		return ;
	y = 0;
	while (y < map.y)
	{
		free(map.tab[y]);
		y++;
	}
	free(map.tab);
}

// Remplie le tableau de tableau //
// avec le contenue du fichier passe en argument //

void	fill_map(t_map *map, char *path_map)
{
	int		fd;
	int		readed;
	char	buf;
	int		y;
	int		x;

	fd = open(path_map, O_RDONLY);
	readed = 1;
	buf = ' ';
	y = 0;
	x = 0;
	while (y < map->y)
	{
		readed = read(fd, &buf, 1);
		if (buf == '\n' || readed == 0)
		{
			map->tab[y++][x] = '\0';
			x = 0;
		}
		else
			map->tab[y][x++] = buf;
	}
	close (fd);
}

// Malloc le tableau de tableau en fonction de x et y //

void	create_map(t_map *map)
{
	int		y;

	map->tab = malloc(sizeof(char *) * (map->y));
	if (!map->tab)
	{
		map->is_valid = 0;
		return ;
	}
	y = 0;
	while (y < map->y)
	{
		map->tab[y] = malloc(sizeof(char) * (map->x + 1));
		if (!map->tab[y])
		{
			free_map(*map);
			map->is_valid = 0;
			return ;
		}
		y++;
	}
}
