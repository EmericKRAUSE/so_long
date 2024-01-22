/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:33:49 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/22 09:48:42 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/****
* Malloc le tableau de tableau en fonction de x et y
*/
int	create_map(t_map *map)
{
	int		y;

	map->tab = malloc(sizeof(char *) * (map->y));
	if (!map->tab)
		return (0);
	y = 0;
	while (y < map->y)
	{
		map->tab[y] = malloc(sizeof(char) * (map->x + 1));
		if (!map->tab[y])
		{
			free_map(*map);
			return (0);
		}
		y++;
	}
	return (1);
}
