#include "set_map.h"

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
		y++;
	}
}

void	make_square(t_map_info *map)
{
	size_t	i;

	i = 0;
	while (map->array_2d[i])
	{
		map->new_malloc = (char *)malloc(sizeof(char ) * map->max_width + 1);
		ft_memset(map->new_malloc, ' ', sizeof(char) * map->max_width);
		map->new_malloc[map->max_width] = '\0';
		ft_memcpy(map->new_malloc, map->array_2d[i], \
		ft_strlen(map->array_2d[i]));
		free(map->array_2d[i]);
		map->array_2d[i] = map->new_malloc;
		i++;
	}
}
