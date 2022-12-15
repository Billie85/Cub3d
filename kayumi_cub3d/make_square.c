#include "cub3d.h"

void	remove_new_line(t_map_info *map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map->array_2d[y])
	{
		x = 0;
		while (map->array_2d[y][x])
		{
			if (map->array_2d[y][x] == '\n')
			{
				map->array_2d[y][x] = '\0';
			}
			x++;
		}
		//printf("%s", map->array_2d[y]);
		y++;
	}
}

void	make_square(t_map_info * map)
{
	size_t	i;

	i = 0;
	while (map->array_2d[i])
	{
		map->new_malloc = (char *)malloc(sizeof(char ) * map->max_width + 1);
		ft_memset(map->new_malloc, ' ', sizeof(char) * map->max_width);
		ft_memcpy(map->new_malloc, map->array_2d[i], ft_strlen(map->array_2d[i]));
		free(map->array_2d[i]);
		map->array_2d[i] = map->new_malloc;
		i++;
	}
}

/* void	Array_2D(t_map_info *map)
{
	char **buff;
	size_t	len;
	size_t	len01;
	size_t	x, y;

	x = 0;
	y = 0;
	map->height = 0;
	map->max_height = 0;
	map->max_width = 0;
	map->line = get_next_line(map->fd);
	while(map->line != NULL)
	{
		buff = map->array_2d;
		map->array_2d = (char **)malloc(sizeof(char *) * (map->height + 2));
		ft_memcpy(map->array_2d, buff, sizeof(char **) * map->height);
		free(buff);
		map->array_2d[map->height] = map->line;
		map->height++;
		map->max_height++;
		len = ft_strlen(map->line);
		if (len > map->max_width)
			map->max_width = len;
		map->line = get_next_line(map->fd);
	}
	map->array_2d[map->height] = NULL;
}
 */