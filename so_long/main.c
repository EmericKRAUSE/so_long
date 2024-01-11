#include "MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// MAPPING MAPPING //

typedef struct map_size
{
	int	x;
	int y;
	int is_valid;
}	t_map_size;

t_map_size	get_map_size(int fd)
{
	t_map_size	map_size;
	int			readed;
	int			x;
	char		buf;

	map_size.x = 0;
	map_size.y = 0;
	map_size.is_valid = 1;
	readed = 1;
	x = 0;
	while(buf != '\n')
	{
		readed = read(fd, &buf, 1);
		if (buf != '\n')
			map_size.x++;
	}
	map_size.y++;
	while (readed > 0)
	{
		readed = read(fd, &buf, 1);
		if (buf == '\n' || readed == 0)
		{
			if (x != map_size.x)
			{
				map_size.is_valid = 0;
				return(map_size);
			}
			map_size.y++;
			x = 0;
		}
		else
			x++;
	}
	printf("%d\n", map_size.x);
	printf("%d\n", map_size.y);
	printf("%d\n", map_size.is_valid);
	return (map_size);
}

char **fill_map(char **map)
{

}

char **create_map(t_map_size map_size, )
{
	char	**map;
	char	buf;
	int		y;
	int		i;
	lseek(fd, 0, SEEK_SET);

	map = malloc(sizeof(char *) * (map_size.y));
	if (!map)
		return (NULL);
	y = 0;
	while (y < map_size.y)
	{
		map[y] = malloc(sizeof(char) * (map_size.x + 1));
		if (!map[y])
		{
			i = 0;
			while (i < y)
				free(map[i]);
			free(map);
			return(NULL);
		}
		y++;
	}
	map = fill_map(map, map_size);
	return (map);
}

/*int map_is_valid(fd)
{
	get_map_size();
	map_is_rectangle();
	map_wall_is_valid();
	map_path_is_valid();
}*/

/* a changer */ void	map_parser(const char *path_map)
{
	int			fd;
	t_map_size	map_size;
	char		**map;
	//char	*buf;

	fd = open(path_map, O_RDONLY);
	if(!fd)
		return ;
	map_size = get_map_size(fd);
	if (!map_size.is_valid)
		return ;
	map = create_map(map_size, fd);


	//get_map_size(fd);
	//read(fd, buf, 10);
	//return ;
	close (fd);
}

// MAPPING MAPPING //

int main(void)
{
	void *mlx_ptr;
	void *texture_ptr;
	void *img_ptr;
	char *path_map;

	path_map = "./map.ber";

	//mlx_ptr = mlx_init(1920, 1080, "game", true);
	//texture_ptr = mlx_load_png("./assets/Dirt.png");
	//img_ptr = mlx_texture_to_image(mlx_ptr, texture_ptr);
	
	//mlx_image_to_window(mlx_ptr, img_ptr, 0, 0);
	map_parser(path_map);
	//mlx_loop(mlx_ptr);

	//mlx_delete_image(mlx_ptr, img_ptr);
	//mlx_delete_texture(texture_ptr);
	//mlx_terminate(mlx_ptr);
	return (0);
}