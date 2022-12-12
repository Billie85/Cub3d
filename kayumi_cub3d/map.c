#include "cub3d.h"

void	map(size_t	h, size_t i, t_map_info *map)
{
	int y;
	int x;
	char **square_map;

	Array_2D(map);
	check_map(map);
	
	//remove_new_line(map);
	//make_square(map);

	/* y = 0;
	while(map->array_2d[y])
	{
		printf("%s\n", map->array_2d[y]);
		y++;
	} */
	//check_around_map(map);
	//check_inside_the_map(map);
	//remove_new_line(map);
	//make_square(map);
	//check_around_map(map);
	//check_inside_the_map(map);
}
