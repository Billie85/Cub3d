#include "cub3d.h"

void	count_square_map(t_map_info *map)
{
	size_t	x;
	size_t	y;
	size_t	len;

	y = 0;
	len = 0;
	map->square_height = 0;
	map->square_width = 0;
	while(map->new_map_square[y])
	{
		len = ft_strlen(map->new_map_square[y]);
		if (len > map->square_width)
			map->square_width = len;
		map->square_height++;
		y++;
	}
	printf("square_width [%ld]\n", map->square_width);
	printf("square_height [%ld]\n", map->square_height);
}

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
	count_square_map(map);
	if (check == true)
	{
		if (check_map_top(map)== true)
		{
			printf("map top is okay\n");
			if (check_map_under(map) == true)
			{
				printf("map under is okay\n");
				if (check_map_left(map) == true)
				{
					printf("map left side is okay\n");
					if (check_map_right(map) == true)
					{
						printf("map right is okay\n");
					}
					else
						printf("--map right side is error--\n");
				}
				else
					printf("--map left side is error--\n");
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
