/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <emeric.yukii@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:26:25 by ekrause           #+#    #+#             */
/*   Updated: 2024/01/16 15:22:05 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// PARSING //

typedef struct map
{
	char	**tab;
	int		x;
	int		y;
	int		collectible;
	int		exit;
	int		position;
	int		is_valid;
}			t_map;

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

int	get_map_width(int fd)
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

int	get_map_height(int fd, int map_x)
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

int	ft_strchr(char *str, char to_find)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == to_find)
			return (1);
		i++;
	}
	return (0);
}

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
				map->is_valid = 0;
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
				map->is_valid = 0;
			x++;
		}
		y++;
	}
}

t_map	map_dup(t_map *map)
{
	t_map	map_dup;
	int		y;
	int		x;

	map_dup.tab = NULL;
	map_dup.x = map->x;
	map_dup.y = map->y;
	map_dup.collectible = map->collectible;
	map_dup.exit = map->exit;
	map_dup.position = map->position;
	map_dup.is_valid = map->is_valid;
	create_map(&map_dup);
	if (!map_dup.is_valid)
		return (map_dup);
	y = 0;
	while (y < map_dup.y)
	{
		x = 0;
		map_dup.tab[y][map->x] = '\0';
		while (map_dup.tab[y][x])
		{
			map_dup.tab[y][x] = map->tab[y][x];
			x++;
		}
		y++;
	}
	y = 0;
	while (y < map_dup.y)
	{
		printf ("%s\n", map_dup.tab[y]);
		y++;
	}
	free_map(map_dup);
	return (map_dup);
}

void path_is_valid(t_map *map)
{
	t_map flood_map;

	flood_map = map_dup(map);
}

t_map	map_parser(char *path_map)
{
	t_map	map;

	map = init_map();
	get_map_size(&map, path_map);
	if (!map.is_valid)
		return (map);
	create_map(&map);
	if (!map.is_valid)
		return (map);
	fill_map(&map, path_map);
	map_component_is_valid(&map);
	if (!map.is_valid)
		return (map);
	map_wall_is_valid(&map);
	map_dup(&map);
	return (map);
}

// PARSING //

/*void	display_map(t_map map, void *mlx_ptr)
{
	void	*texture_dirt;
	void	*texture_tree;
	void	*texture_key;
	void	*texture_chest;
	void	*texture_c;

	void	*img_dirt;
	void	*img_tree;
	void	*img_key;
	void	*img_chest;
	void	*img_c;

	int y;
	int x;
	int y_pixels;
	int	x_pixels;

	y_pixels = 128;
	x_pixels = 128;

	texture_dirt = mlx_load_png("./assets/grass.png");
	img_dirt = mlx_texture_to_image(mlx_ptr, texture_dirt);
	mlx_resize_image(img_dirt, x_pixels, y_pixels);

	texture_tree = mlx_load_png("./assets/tree.png");
	img_tree = mlx_texture_to_image(mlx_ptr, texture_tree);
	mlx_resize_image(img_tree, x_pixels, y_pixels);

	texture_key = mlx_load_png("./assets/key.png");
	img_key = mlx_texture_to_image(mlx_ptr, texture_key);
	mlx_resize_image(img_key, x_pixels, y_pixels);

	texture_chest = mlx_load_png("./assets/chest.png");
	img_chest = mlx_texture_to_image(mlx_ptr, texture_chest);
	mlx_resize_image(img_chest, x_pixels, y_pixels);

	texture_c = mlx_load_png("./assets/character.png");
	img_c = mlx_texture_to_image(mlx_ptr, texture_c);
	mlx_resize_image(img_c, x_pixels, y_pixels);

	y = 0;
	while (y < map.y)
	{
		x = 0;
		while (map.tab[y][x])
		{
			if (map.tab[y][x] == '1')
			{
				mlx_image_to_window(mlx_ptr, img_dirt, x * x_pixels, y * y_pixels);
				mlx_image_to_window(mlx_ptr, img_tree, x * x_pixels, y * y_pixels);
			}
			else if (map.tab[y][x] == '0')
				mlx_image_to_window(mlx_ptr, img_dirt, x * x_pixels, y * y_pixels);
			else if (map.tab[y][x] == 'C')
			{
				mlx_image_to_window(mlx_ptr, img_dirt, x * x_pixels, y * y_pixels);
				mlx_image_to_window(mlx_ptr, img_key, x * x_pixels, y * y_pixels);
			}
			else if (map.tab[y][x] == 'E')
			{
				mlx_image_to_window(mlx_ptr, img_dirt, x * x_pixels, y * y_pixels);
				mlx_image_to_window(mlx_ptr, img_chest, x * x_pixels, y * y_pixels);
			}
			else if (map.tab[y][x] == 'P')
			{
				mlx_image_to_window(mlx_ptr, img_dirt, x * x_pixels, y * y_pixels);
				mlx_image_to_window(mlx_ptr, img_c, x * x_pixels, y * y_pixels);
			}
			x++;
		}
		y++;
	}
}*/

int	so_long(char *path_map)
{
	int		y;
	t_map	map;
	//void	*mlx_ptr;
	map = map_parser(path_map);
	if (!map.is_valid)
	{
		free_map(map);
		return (0);
	}
	y = 0;
	while (y < map.y)
	{
		printf ("%s\n", map.tab[y]);
		y++;
	}
	free_map(map);
	//mlx_ptr = mlx_init(map.x * 128, map.y * 128, "game", true);
	//display_map(map, mlx_ptr);
	//mlx_loop(mlx_ptr);
	//mlx_delete_image(mlx_ptr, img_ptr);
	//mlx_delete_texture(texture_ptr);
	//mlx_terminate(mlx_ptr);
	return (1);
}

int	main(void)
{
	char	*path_map;

	path_map = "./map.ber";
	if (!so_long(path_map))
		return (1);
	return (0);
}
