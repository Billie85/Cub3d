#include "cub3d.h"

void	map(size_t	h, size_t i, t_map_info *map)
{
	int y;
	int x;

	Array_2D(map);
	check_map(map);
	remove_new_line(map);
	make_square(map);



/* 	y = 0;
	while(map->array_2d[y])
	{
		x = 0;
		while(map->array_2d[y][x] == '1' || map->array_2d[y][x] == '0')
		{
			make_square(map);
			if (map->array_2d[y][x] == '\n')
				map->array_2d[y][x] = '\0';
			remove_new_line(map);
			printf("%c", map->array_2d[y][x]);
			x++;
		}
			y++;
	} */
	//remove_new_line(map);
	//make_square(map);
	//check_around_map(map);
	//check_inside_the_map(map);
}
