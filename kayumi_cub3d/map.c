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
		check_top =  check_map_top(map);
		printf(" check top is [%d]\n", check_top);
	/* 	if (check_top != 0)
		{

		} */
	}
			/* x = 0;
			while (map->new_map_square[13][x])
			{
				if (map->new_map_square[13][x] == '1' || map->new_map_square[13][x] == ' ')
				{
					printf("good\n");
				}
				//printf("%c", map->new_map_square[13][x]);
				x++; */
		/* 
			if (map->new_map_square[0][x] == '1' || map->new_map_square[0][x] == ' ')
				printf("the map is okay\n"); */
				/* else if (map->new_map_square[0][x] != '1' || map->new_map_square[0][x] != ' ')
				{
					break;
					printf("in the top have error\n");
				} */
	/* 	if (map->new_map_square[0][x] != '1' || map->new_map_square[0][x] != ' ')
			printf("error\n"); */
	else
	{
		printf("--map is error--\n");
		return (0);
	}
}
//check_around_map(map);
//check_inside_the_map(map);
//remove_new_line(map);
//make_square(map);
//check_around_map(map);
//check_inside_the_map(map);
