#include "cub3d.h"

int	map(size_t	h, size_t i, t_map_info *map)
{
	int y;
	int x;
	int flag[2];
	char **square_map;
	bool	check;
	bool	check_top;
	bool	check_under;

	Array_2D(map);
	check = check_direction_map(map);
	if (check == true)
	{
		if (check_map_top(map)== true)
		{
			printf("map top is okay\n");
			if (check_map_under(map) == true)
			{
				printf("map under is okay\n");
			}
			else
			printf("--map under is error--\n");
		}
			else
			printf("--map top is error--\n");
	}
	else
	{
		printf("--map direction is error--\n");
		return (0);
	}
}
//check_around_map(map);
//check_inside_the_map(map);
//remove_new_line(map);
//make_square(map);
//check_around_map(map);
//check_inside_the_map(map);
