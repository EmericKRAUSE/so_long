/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:58:20 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/19 13:44:37 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/****
* Free le tableau de tableau */
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
	free (map.tab);
}
