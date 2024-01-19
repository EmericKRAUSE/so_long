/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:56:28 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/19 13:11:28 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/****
* Remplie le tableau de tableau
* avec le contenue du fichier passe en argument */
void	fill_map(t_map *map, char *file)
{
	int		fd;
	int		readed;
	char	buf;
	int		y;
	int		x;

	fd = open(file, O_RDONLY);
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
