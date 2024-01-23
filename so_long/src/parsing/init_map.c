/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:57:54 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/23 13:52:30 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/****
* Initialise la t_map avec les valeurs par defaut
*/
t_map	init_map(void)
{
	t_map	map;

	map.tab = NULL;
	map.x = 0;
	map.y = 0;
	map.collectible = 0;
	map.exit = 0;
	map.position = 0;
	map.component = "10CETP";
	return (map);
}
