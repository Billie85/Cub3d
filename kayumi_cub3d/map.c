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

void	check_error_inside_map(t_map_info * map)
{
	if (map_inside_left(map) == true)
	{
		printf("map inside left is okay\n");
		if (map_inside_right(map) == true)
		{
			printf("map inside right is okay\n");
			if (map_inside_up(map) == true)
			{
				printf("map inside up is okay\n");
				if (map_inside_down(map) == true)
				{
					printf(PURPLE"MAP IS OKAY\n"BACK);
				}
				else
					printf(RED"ERROR\n"BACK);
			}
			else
				printf(RED"ERROR\n"BACK);
		}
		else
			printf(RED"ERROR\n"BACK);
	}
	else
		printf(RED"ERROR\n"BACK);
}

void	check_error_around_map(t_map_info * map, bool check)
{
	if (check == true)
	{
		if (check_map_top(map)== true)
		{
			if (check_map_under(map) == true)
			{
				if (check_map_left(map) == true)
				{
					if (check_map_right(map) == true)
					{
						check_error_inside_map(map);
					}
					else
						printf(RED"ERROR\n"BACK);
				}
				else
					printf(RED"ERROR\n"BACK);
			}
			else
				printf(RED"ERROR\n"BACK);
		}
		else
			printf(RED"ERROR\n"BACK);
	}
	else
		printf(RED"ERROR\n"BACK);
}

int	map(size_t	x, size_t y, t_map_info *map, char *ch)
{
	bool	check;

	if (ch == NULL)
	{
		Array_2D(map);
		check = check_direction_map(map);
		count_square_map(map);
		check_error_around_map(map, check);
	}
/* 	else if (ch == FREE_ALL)
	{
		free(map->new_map_square);
		printf("i'm going to free\n");
	} */
	return (map->new_map_square[x][y]);
}