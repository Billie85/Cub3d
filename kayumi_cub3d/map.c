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
	while (map->new_map_square[y])
	{
		len = ft_strlen(map->new_map_square[y]);
		if (len > map->square_width)
			map->square_width = len;
		map->square_height++;
		y++;
	}
}

bool	check_error_inside_map(t_map_info *map)
{
	if (map_inside_left(map) == true)
	{
		if (map_inside_right(map) == true)
		{
			if (map_inside_up(map) == true)
			{
				if (map_inside_down(map) == true)
				{
					printf(PURPLE"MAP IS OKAY\n"BACK);
					return (true);
				}
				else
				{
					printf(RED"6ERROR\n"BACK);
					return (false);
				}
			}
			else
			{
				printf(RED"7ERROR\n"BACK);
				return (false);
			}
		}
		else
		{
			printf(RED"8ERROR\n"BACK);
				return (false);
		}
	}
	else
	{
		printf(RED"9ERROR\n"BACK);
				return (false);
	}
}

bool	check_error_around_map(t_map_info *map)
{
	if (check_map_top(map) == true)
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
				{
					printf(RED"1ERROR\n"BACK);
					return (false);
				}
			}
			else
			{
				printf(RED"2ERROR\n"BACK);
				return (false);
			}
		}
		else
		{
			printf(RED"3ERROR\n"BACK);
			return (false);
		}
	}
	else
	{
		printf(RED"4ERROR\n"BACK);
		return (false);
	}
}

int	map(size_t	i, size_t j, t_map_info *Map)
{
	size_t	y;
	size_t	y_d;
	bool	check;
	static unsigned char	**static_map;

	if (Map == (t_map_info *) FREE_ALL)
	{	
		y = 0;
		while (static_map[y])
			free(static_map);
		y++;
	}
	else if (Map != NULL)
	{
		Array_2D(Map);
		static_map = check_direction_map(Map);
		if (static_map == false)
		{
			printf(RED"ERROR\n"BACK);
			return (false);
		}
		count_square_map(Map);
		if (check_error_around_map(Map) == false)
			return (false);
			else
			return (true);
	}
	return (static_map[i][j]);
}
