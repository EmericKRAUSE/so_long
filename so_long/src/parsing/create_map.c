/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:33:49 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/19 14:22:22 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/****
* Malloc le tableau de tableau en fonction de x et y
*/
void	create_map(t_map *map)
{
	int		y;

	map->tab = malloc(sizeof(char *) * (map->y));
	if (!map->tab)
		ft_error("malloc failed");
	y = 0;
	while (y < map->y)
	{
		map->tab[y] = malloc(sizeof(char) * (map->x + 1));
		if (!map->tab[y])
		{
			free_map(*map);
			ft_error("malloc failed");
		}
		y++;
	}
}
