#include "MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// MAPPING MAPPING //

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

t_map	init_map()
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

void	get_map_size(t_map *map, char *path_map)
{
	int			readed;
	int			x;
	int			fd;
	char		buf;

	readed = 1;
	x = 0;
	fd = open(path_map, O_RDONLY);
	buf = ' ';
	while(buf != '\n')
	{
		readed = read(fd, &buf, 1);
		if (buf != '\n')
			map->x++;
	}
	map->y++;
	while (readed > 0)
	{
		readed = read(fd, &buf, 1);
		if (buf == '\n' || readed == 0)
		{
			if (x != map->x)
			{
				map->is_valid = 0;
				return ;
			}
			map->y++;
			x = 0;
		}
		else
			x++;
	}
	close(fd);
}

void	free_map(t_map map)
{
	int y;
	
	if (!map.tab)
		return ;
	y = 0;
	while(y < map.y)
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
	y = 0;
	x = 0;
	while(readed > 0)
	{
		readed = read(fd, &buf, 1);
		if (buf == '\n' || readed == 0)
		{
			map->tab[y][x] = '\0';
			x = 0;
			y++;
		}
		else
		{
			map->tab[y][x] = buf;
			x++;
		}
	}
	y = 0;
	close (fd);
}

int	ft_strchr(char *str, char to_find)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == to_find)
			return (1);
		i++;
	}
	return (0);
}

int	map_component_is_valid(t_map *map)
{
	char component[6] = "10CEP";
	int y;
	int x;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (map->tab[y][x])
		{
			if (!ft_strchr(component, map->tab[y][x]))
				return (map->is_valid = 0);
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
		return (map->is_valid = 0);
	return (map->is_valid);
}

int	map_wall_is_valid(t_map *map)
{
	int y;
	int x;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while(map->tab[y][x])
		{
			if ((y == 0 || y == map->y - 1 ||\
			x == 0 || x == map->x - 1) && map->tab[y][x] != '1')
				return (map->is_valid = 0);
			x++;
		}
		y++;
	}
	return (map->is_valid);
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
	if (!map_component_is_valid(&map))
	{
		free_map(map);
		return (map);
	}
	if (!map_wall_is_valid(&map))
		free_map(map);
	return (map);
}

// MAPPING MAPPING //

void	display_map(t_map map, void *mlx_ptr)
{
	void	*texture_dirt;
	void	*texture_tree;
	void	*texture_key;
	void	*texture_chest;

	void	*img_dirt;
	void	*img_tree;
	void	*img_key;
	void	*img_chest;

	int y;
	int x;
	int y_pixels;
	int	x_pixels;

	y_pixels = 128;
	x_pixels = 128;

	texture_dirt = mlx_load_png("./assets/Grass2.png");
	img_dirt = mlx_texture_to_image(mlx_ptr, texture_dirt);
	mlx_resize_image(img_dirt, x_pixels, y_pixels);

	texture_tree = mlx_load_png("./assets/Tree.png");
	img_tree = mlx_texture_to_image(mlx_ptr, texture_tree);
	mlx_resize_image(img_tree, x_pixels, y_pixels);

	texture_key = mlx_load_png("./assets/Key.png");
	img_key = mlx_texture_to_image(mlx_ptr, texture_key);
	mlx_resize_image(img_key, x_pixels, y_pixels / 1.5);

	texture_chest = mlx_load_png("./assets/Chest_Locked.png");
	img_chest = mlx_texture_to_image(mlx_ptr, texture_chest);
	mlx_resize_image(img_chest, x_pixels, y_pixels);

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
				mlx_image_to_window(mlx_ptr, img_dirt, x * x_pixels, y * y_pixels);
			x++;
		}
		y++;
	}
}

int main(void)
{
	char	*path_map;
	t_map	map;
	void	*mlx_ptr;

	path_map = "./map.ber";
	map = map_parser(path_map);
	if (!map.is_valid)
		return (1);

	mlx_ptr = mlx_init(map.x * 128, map.y * 128, "game", true);
	display_map(map, mlx_ptr);
	
	mlx_loop(mlx_ptr);

	//mlx_delete_image(mlx_ptr, img_ptr);
	//mlx_delete_texture(texture_ptr);
	mlx_terminate(mlx_ptr);
	return (0);
}