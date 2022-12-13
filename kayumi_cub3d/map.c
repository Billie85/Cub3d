#include "cub3d.h"

int	map(size_t	h, size_t i, t_map_info *map)
{
	int y;
	int x;
	char **square_map;
	bool	check;

	Array_2D(map);
	check = check_direction_map(map);//
	if (check == 1)
	{
		printf("map is okay\n");
		y = 0;
		while (map->new_map_square[y])
		{
			printf("%s\n", map->new_map_square[y]);  fflush(stdout);
			y++;
		}
	}
	else
	{
		printf("--map is error--\n");
		return (0);
	}
	//check_around_map(map);
	//check_inside_the_map(map);
	//remove_new_line(map);
	//make_square(map);
	//check_around_map(map);
	//check_inside_the_map(map);
}
