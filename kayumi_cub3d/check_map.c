#include "cub3d.h"

void	check_map(t_map_info *map)
{
	int	no_found;
	size_t	x;
	size_t	y;
	int		flag[6];

	y = 0;
	ft_bzero(flag, sizeof(flag));
	while(map->array_2d[y])
	{
		x = 0;
		while (map->array_2d[y][x] == ' ')
		{
			printf("aaa\n");
			x++;
		}
		//printf("%s", map->array_2d[y]);
		if (ft_memcmp(map->array_2d[y] + x, "NO", ft_strlen("NO")) == 0)
		{
			printf("found NO\n");
			if(flag[0] == 1)
			{
				flag[0] = 0;
				break;
			}
			else
				flag[0] = 1;
		}
		else if (ft_memcmp(map->array_2d[y] + x, "SO", ft_strlen("SO")) == 0)
		{
			printf("found SO\n");
			if(flag[1] == 1)
			{
				flag[1] = 0;
				break;
			}
			else
				flag[1] = 1;
		}
		
		else if (ft_memcmp(map->array_2d[y] + x, "WO", ft_strlen("WO")) == 0)
		{
			printf("found WO\n");
			if(flag[2] == 1)
			{
				flag[2] = 0;
				break;
			}
			else
				flag[2] = 1;
		}
		
		else if (ft_memcmp(map->array_2d[y] + x, "EA", ft_strlen("EA")) == 0)
		{
			printf("found EA\n");
			if(flag[3] == 1)
			{
				flag[3] = 0;
				break;
			}
			else
				flag[3] = 1;
		}
		y++;
		
	}
	if(!(flag[0] && flag[1] && flag[2] && flag[3]))
	{
		printf("not found!!\n");
		return (0);
	}
}
