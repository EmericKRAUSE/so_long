/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:12:12 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/17 13:12:47 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Renvoie la taille x du tableau de tableau //

static	int	get_map_width(int fd)
{
	int		readed;
	int		x;
	char	buf;

	readed = 1;
	x = 0;
	buf = ' ';
	while (readed > 0 && buf != '\n')
	{
		readed = read(fd, &buf, 1);
		if (buf != '\n')
			x++;
	}
	return (x);
}

// Renvoie la taille y du tableau de tableau //

static	int	get_map_height(int fd, int map_x)
{
	int		readed;
	int		x;
	int		y;
	char	buf;

	readed = 1;
	x = 0;
	y = 0;
	buf = ' ';
	while (readed > 0)
	{
		readed = read(fd, &buf, 1);
		if (buf == '\n' || readed == 0)
		{
			if (x != map_x)
				return (-1);
			y++;
			x = 0;
		}
		else
			x++;
	}
	return (y);
}

// Attribut la taille x et y a la t_map //
// et verifie si elle est bien rectangulaire //

void	get_map_size(t_map *map, char *path_map)
{
	int	fd;

	fd = open(path_map, O_RDONLY);
	if (fd == -1)
	{
		map->is_valid = 0;
		return ;
	}
	map->x = get_map_width(fd);
	map->y = get_map_height(fd, map->x) + 1;
	if (map->y == -1 || map->y == map->x)
		map->is_valid = 0;
	close(fd);
}