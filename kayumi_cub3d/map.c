#include "cub3d.h"

/* if (ft_strncmp(map->line, "NO", ft_strlen("NO")) == 0 || ft_strncmp(map->line, "SO", ft_strlen("SO")) == 0 || \
				ft_strncmp(map->line, "WE", ft_strlen("WE")) == 0 || ft_strncmp(map->line, "EA", ft_strlen("EA")) == 0 || \
				ft_strncmp(map->line, "F", ft_strlen("F")) == 0 || ft_strncmp(map->line, "C", ft_strlen("C")) == 0 || \
				ft_strncmp(map->line, "\n", 2) == 0 || ft_strncmp(map->line, " ", 1) == 0 || ft_strncmp(map->line, "	", 1) == 0){
				printf("%s", map->line);
				//printf("IT'S GOOD\n");
				}
				else
				{
					map->line = NULL;
					break;
				} */

void	map(size_t	h, size_t i, t_map_info *map)
{
	int y;
	int x;
	y = 0;
	Array_2D(map);

	x = 0;
	while (map->array_2d[x])
	{
		if (ft_strncmp(map->array_2d[x], "NO", ft_strlen("NO")) == 0 || ft_strncmp(map->array_2d[x], "SO", ft_strlen("SO")) == 0 || \
		ft_strncmp(map->array_2d[x], "WE", ft_strlen("WE")) == 0 || ft_strncmp(map->array_2d[x], "EA", ft_strlen("EA")) == 0 || \
		ft_strncmp(map->array_2d[x], "F", ft_strlen("F")) == 0 || ft_strncmp(map->array_2d[x], "C", ft_strlen("C")) == 0)
		{
			printf("good\n");
		}
		else if (ft_strncmp(map->array_2d[x], "\n", ft_strlen("\n")) == 0 || ft_strncmp(map->array_2d[x], " ", ft_strlen(" ")) == 0 || \
			ft_strncmp(map->array_2d[x], "	", ft_strlen("	")) == 0)
			{
				if (ft_strncmp(map->array_2d[x], "1", 2) == 0 || ft_strncmp(map->array_2d[x], "0", 2) == 0 || \
				ft_strncmp(map->array_2d[x], "N", 2) == 0 || ft_strncmp(map->array_2d[x], "\n", 1))
				{
					printf("this is a map\n");
				}
				else
				printf("this is not a map\n");
				//printf("%s", map->array_2d[x]);
				//printf("sp\n");
			}
			else if (ft_strncmp(map->array_2d[x], "1", 1) == 0 || ft_strncmp(map->array_2d[x], "0", 1) == 0 || ft_strncmp(map->array_2d[x], "N", 1) == 0)
			printf("Map!!\n");
		else
		//printf("%s", map->array_2d[x]);
		printf("no\n");
		x++;
	}
	
	
/* 	while(map->array_2d[y])
	{
		if (ft_strncmp(map->array_2d[y], "NO", ft_strlen("NO")) != 0 || ft_strncmp(map->array_2d[y], "SO", ft_strlen("SO")) != 0 || \
				ft_strncmp(map->array_2d[y], "WE", ft_strlen("WE")) != 0 || ft_strncmp(map->array_2d[y], "EA", ft_strlen("EA")) != 0 || \
				ft_strncmp(map->array_2d[y], "F", ft_strlen("F")) != 0 || ft_strncmp(map->array_2d[y], "C", ft_strlen("C")) != 0 || \
				ft_strncmp(map->array_2d[y], "\n", 2) != 0 || ft_strncmp(map->array_2d[y], " ", 1) != 0 || ft_strncmp(map->array_2d[y], "	", 1) != 0)
				{
					printf("this map is bad\n");
				}
				else
				{
					printf("this map is okay\n")
				}
				y++;
	} */
		//y++;
	//最大値を取ってしまうと本来ない部分までwhiが回ってしまうから文字化けが起きる。
/* 	while(map->array_2d[y])
	{
		x = 0;
		while(map->array_2d[y][x])
		{
			if (map->array_2d[y][x] == '1' || map->array_2d[y][x] == '0' || map->array_2d[y][x] == ' ')
			printf("%c", map->array_2d[y][x]);
			x++;
		}
		y++;
	} */
}
	/* for(int x = 0; map->array_2d[x];  x++)
	printf("%s", map->array_2d[x]); */
	//remove_new_line(map);
	/* make_square(map);
	check_inside_the_map(map);
	check_around_map(map); */
