#include "cub3d.h"

//この関数はマップの文字列がかけてないかとか、をチェックする関数。
void	check_map(t_map_info *map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while(map->array_2d[y])
	{
		x = 0;
		while (map->array_2d[y][x] == ' ')
		{
			x++;
		}
		if (map->array_2d[y][x] == '1' || map->array_2d[y][x] == '0')
		{
			printf("this is a map!\n");
		}
		else if (map->array_2d[y][x] == 'N' || map->array_2d[y][x] == 'S' || map->array_2d[y][x] == 'W' || \
			map->array_2d[y][x] == 'E' || map->array_2d[y][x] == 'F' || map->array_2d[y][x] == 'C')
			{
				printf("this is a direction\n");
			}
		else if (map->array_2d[y][x] == '\n')
			{
				printf("sp\n");
				//x++;
			}
			else
			{
				map->array_2d[y] = NULL;
				printf("Error\n");
				break;
			}
			y++;
	}
}
