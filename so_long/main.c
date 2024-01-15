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
	int		is_valid;
}			t_map;

void	get_map_size(t_map map, char *path_map)
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
		map.x++;
	}
	map.y++;
	while (readed > 0)
	{
		readed = read(fd, &buf, 1);
		if (buf == '\n' || readed == 0)
		{
			if (x != map.x)
			{
				map.is_valid = 0;
				return ;
			}
			map.y++;
			x = 0;
		}
		else
			x++;
	}
	close(fd);
}

char **fill_map(char **map, t_map_size map_size, char *path_map)
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
			map[y][x] = '\0';
			x = 0;
			y++;
		}
		else
		{
			map[y][x] = buf;
			x++;
		}
	}
	y = 0;
	close (fd);
	return (map);
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

t_map create_map(t_map map)
{
	int		y;
	int		i;

	map.tab = malloc(sizeof(char *) * (map.y));
	if (!map.tab)
	{
		map.is_valid = 0;
		return (map);
	}
	y = 0;
	while (y < map.y)
	{
		map.tab[y] = malloc(sizeof(char) * (map.x + 1));
		if (!map.tab[y])
		{
			free_map(map.tab);
			map.is_valid = 0;
			return (map);	
		}
		y++;
	}
	return (map);
}

int	map_wall_is_valid(char **map, t_map_size map_size)
{
	int y;
	int x;

	y = 0;
	while (y < map_size.y)
	{
		x = 0;
		while(map[y][x])
		{
			if ((y == 0 || y == map_size.y - 1 ||\
			x == 0 || x == map_size.x - 1) && map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
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

int	map_component_is_valid(char **map, t_map_size map_size)
{
	char component[6] = "10CEP";
	int exit;
	int collectible;
	int position;
	int y;
	int x;

	exit = 0;
	collectible = 0;
	position = 0;
	y = 0;
	while (y < map_size.y)
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_strchr(component, map[y][x]))
				return (0);
			if (map[y][x] == 'C')
				collectible++;
			else if (map[y][x] == 'E')
				exit++;
			else if (map[y][x] == 'P')
				position++;
			x++;
		}
		y++;
	}
	if (collectible <= 0 || exit != 1 || position != 1)
		return (0);
	return (1);
}

void	display_map(char **map, t_map_size map_size)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < map_size.y)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				collectible++;
			else if (map[y][x] == 'E')
				exit++;
			else if (map[y][x] == 'P')
				position++;
		}
		y++;
	}
}

t_map	map_parser(char *path_map)
{
	t_map	map;

	map = init_map();
	get_map_size(&map, path_map);
	if (!map_size.is_valid)
		return ;

	map = create_map(map);
	if (!map)
		return ;
	map = fill_map(map, map_size, path_map);
	if (!map_component_is_valid(map, map_size))
	{
		free_map(map, map_size);
		return ;
	}
	if (!map_wall_is_valid(map, map_size))
	{
		free_map(map, map_size);
		return ;
	}
	int y = 0;
	while (y < map_size.y)
	{
		printf("%s\n", map[y]);
		y++;
	}
	return (map);
	free_map(map, map_size);
}

t_map	init_map()
{
	t_map	map;

	map.tab = NULL;
	map.x = 0;
	map.y = 0;
	map.is_valid = 1;

	return (map);
}

// MAPPING MAPPING //

int main(void)
{
	char	*path_map;
	t_map	map;
	void	*mlx_ptr;
	void	*texture_ptr;
	void	*img_ptr;

	path_map = "./map.ber";
	map = map_parser(path_map);

	//mlx_ptr = mlx_init(1920, 1080, "game", true);
	//img_ptr = mlx_texture_to_image(mlx_ptr, texture_ptr);
	
	//mlx_image_to_window(mlx_ptr, img_ptr, 0, 0);
	display_map(map);
	
	//mlx_loop(mlx_ptr);

	//mlx_delete_image(mlx_ptr, img_ptr);
	//mlx_delete_texture(texture_ptr);
	//mlx_terminate(mlx_ptr);
	return (0);
}