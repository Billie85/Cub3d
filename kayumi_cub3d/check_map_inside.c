#include "cub3d.h"

bool	map_inside_down(t_map_info *map)
{
	size_t	x;
	size_t	y;
	size_t	flag;

	y = 1;
	flag = 1;
	while (map->new_map_square[y])
	{
		x = 1;
		while (map->new_map_square[y][x])
		{
			if (map->new_map_square[y][x] == '0' || \
				map->new_map_square[y][x] == 'N' || \
				map->new_map_square[y][x] == 'W' || \
				map->new_map_square[y][x] == 'S' || \
				map->new_map_square[y][x] == 'E')
			{
				if (map->new_map_square[y + 1][x] == '1' || \
					map->new_map_square[y + 1][x] == '0' || \
					map->new_map_square[y + 1][x] == 'N' || \
					map->new_map_square[y + 1][x] == 'W' || \
					map->new_map_square[y + 1][x] == 'S' || \
					map->new_map_square[y + 1][x] == 'E')
					flag = true;
				else
					flag = false;
			}
			x++;
			if (flag == false)
				return (false);
		}
		y++;
	}
	if (flag == false)
		return (false);
	else
		return (true);
}

bool	map_inside_up(t_map_info *map)
{
	size_t	x;
	size_t	y;
	size_t	flag;

	y = 1;
	flag = 1;
	while (map->new_map_square[y])
	{
		x = 1;
		while (map->new_map_square[y][x])
		{
			if (map->new_map_square[y][x] == '0' || \
			map->new_map_square[y][x] == 'N' || \
			map->new_map_square[y][x] == 'W' || \
			map->new_map_square[y][x] == 'S' || \
			map->new_map_square[y][x] == 'E')
			{
				if (map->new_map_square[y - 1][x] == '1' || map->new_map_square[y - 1][x] == '0' || \
				map->new_map_square[y - 1][x] == 'N' || \
				map->new_map_square[y - 1][x] == 'W' || \
				map->new_map_square[y - 1][x] == 'S' || \
				map->new_map_square[y - 1][x] == 'E')
					flag = true;
				else
					flag = false;
			}
			x++;
			if (flag == false)
				return (false);
		}
		y++;
	}
	if (flag == false)
		return (false);
	else
		return (true);
}//25

bool	map_inside_right(t_map_info *map)
{
	size_t	x;
	size_t	y;
	size_t	flag;

	y = 1;
	flag = 1;
	while (map->new_map_square[y])
	{
		x = 1;
		while (map->new_map_square[y][x])
		{
			if (map->new_map_square[y][x] == '0' || \
				map->new_map_square[y][x] == 'N' || \
				map->new_map_square[y][x] == 'W' || \
				map->new_map_square[y][x] == 'S' || \
				map->new_map_square[y][x] == 'E')
			{
				if (map->new_map_square[y][x + 1] == '1' || map->new_map_square[y][x + 1] == '0' || \
				map->new_map_square[y][x + 1] == 'N' || \
				map->new_map_square[y][x + 1] == 'W' || \
				map->new_map_square[y][x + 1] == 'S' || \
				map->new_map_square[y][x + 1] == 'E')
					flag = true;
				else
					flag = false;
			}
			x++;
			if (flag == false)
				return (false);
		}
		y++;
	}
	if (flag == false)
		return (false);
	else
		return (true);
}//25

bool	map_inside_left(t_map_info *map)
{
	size_t	x;
	size_t	y;
	size_t	flag;

	flag = 1;
	y = 1;
	while (map->new_map_square[y])
	{
		x = 1;
		while (map->new_map_square[y][x])
		{
			if (map->new_map_square[y][x] == '0' || \
				map->new_map_square[y][x] == 'N' || \
				map->new_map_square[y][x] == 'W' || \
				map->new_map_square[y][x] == 'S' || \
				map->new_map_square[y][x] == 'E')
			{
				if (map->new_map_square[y][x -1] == '1' || \
					map->new_map_square[y][x - 1] == '0' || \
					map->new_map_square[y][x - 1] == 'N' || \
					map->new_map_square[y][x - 1] == 'W' || \
					map->new_map_square[y][x - 1] == 'S' || \
					map->new_map_square[y][x - 1] == 'E')
					flag = true;
				else
					flag = false;
			}
			x++;
			if (flag == false)
				return (false);
		}
		y++;
	}
	if (flag == false)
		return (false);
	else
		return (true);
}//25