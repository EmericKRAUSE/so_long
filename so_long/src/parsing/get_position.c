/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:02:35 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/19 14:22:49 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/****
* Renvoie les coordonnees x et y corespondant
* a la position de depart du personnage
*/
int	get_position(t_map flooded_map, char c)
{
	int	y;
	int	x;

	y = 0;
	while (y < flooded_map.y)
	{
		x = 0;
		while (x < flooded_map.x)
		{
			if (flooded_map.tab[y][x] == 'P')
			{
				if (c == 'y')
					return (y);
				else if (c == 'x')
					return (x);
			}
			x++;
		}
		y++;
	}
	return (0);
}
