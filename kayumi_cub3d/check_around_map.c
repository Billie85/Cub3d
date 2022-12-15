#include "cub3d.h"

bool	check_map_under(t_map_info *map)//数の直しが必要です。
{
	size_t	y;
	size_t	x;
	size_t	flag;

	y = 13;//一番下
	x = 0;
	flag = 0;
	while (map->new_map_square[y][x])
	{
		if (map->new_map_square[y][x] == '1' || map->new_map_square[y][x] == ' ')
			flag = true;
		else if (map->new_map_square[y][x] != '1' || map->new_map_square[y][x] != ' ')
			flag = false;
		if (flag == false)
			return (false);
		x++;
	}
	if (flag == false)
		return (false);
	else
		return(true);
}

bool	check_map_top(t_map_info * map)
{
	size_t	y;
	size_t	x;
	size_t	flag;

	y = 0;
	x = 0;
	flag = 0;
	while (map->new_map_square[y][x])
	{
		//printf("%s\n", map->new_map_square[y]);
		if (map->new_map_square[y][x] == '1' || map->new_map_square[y][x] == ' ')
			flag = true;
		else if (map->new_map_square[y][x] != '1' || map->new_map_square[y][x] != ' ')
			flag = false;
		if (flag == false)
			return (false);
		x++;
	}
	if (flag == false)
		return (false);
	else
		return(true);
}
