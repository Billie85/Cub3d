#include "cub3d.h"

void	map(size_t	x, size_t y, t_map_info *map)
{
	char *str;

	str = skip_direction(map);
	while(str)
	{
		printf("%s\n", str);
	}
/* 	if (skip == 1)
	{
		printf("[%s]\n", get_next_line(map->fd));
	} */
	//Array_2D(map);
	/* remove_new_line(map);
	make_square(map);
	check_inside_the_map(map);
	check_around_map(map); */
}