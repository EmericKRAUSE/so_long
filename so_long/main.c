#include "MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// MAPPING MAPPING //

typedef struct map_size
{
	int	x;
	int y;
	int is_valid;
}	t_map_size;

t_map_size	get_map_size(int fd)
{
	t_map_size	map;
	int			readed;
	int			x;
	char		buf;

	map.x = 0;
	map.y = 0;
	map.is_valid = 1;
	readed = 1;
	x = 0;
	while(buf != '\n')
	{
		readed = read(fd, &buf, 1);
		if (buf != '\n')
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
				return(map);
			}
			map.y++;
			x = 0;
		}
		else
			x++;
	}
	printf("x     :%d\n", map.x);
	printf("y     :%d\n", map.y);
	printf("valid :%d\n", map.is_valid);
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
	int		fd;
	t_map_size map;
	//char	*buf;

	fd = open(path_map, O_RDONLY);
	map = get_map_size(fd);
	//map_is_valid(fd);


	//get_map_size(fd);
	//read(fd, buf, 10);
	//return ;
}

// MAPPING MAPPING //

int main(void)
{
	void *mlx_ptr;
	void *texture_ptr;
	void *img_ptr;

	//mlx_ptr = mlx_init(1920, 1080, "game", true);
	//texture_ptr = mlx_load_png("./assets/Dirt.png");
	//img_ptr = mlx_texture_to_image(mlx_ptr, texture_ptr);
	
	//mlx_image_to_window(mlx_ptr, img_ptr, 0, 0);
	map_parser("./map.ber");
	//mlx_loop(mlx_ptr);

	//mlx_delete_image(mlx_ptr, img_ptr);
	//mlx_delete_texture(texture_ptr);
	//mlx_terminate(mlx_ptr);
	return (0);
}