/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:01:05 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/17 13:14:10 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct map
{
	char		**tab;
	int			x;
	int			y;
	int			collectible;
	int			exit;
	int			position;
	int			is_valid;
}				t_map;

t_map	map_parser(char *path_map);
void	free_map(t_map map);
void	get_map_size(t_map *map, char *path_map);
t_map	init_map(void);
void	create_map(t_map *map);
void	fill_map(t_map *map, char *path_map);

void	path_is_valid(t_map *map);
int	ft_strchr(char *str, char to_find);

#endif