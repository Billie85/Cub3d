#include "cub3d.h"

bool	check_direction_map(t_map_info *map)
{
	int	no_found;
	size_t	x;
	size_t	y;
	size_t	new_x;
	size_t	new_y;
	int		flag[6];

	y = 0;
	new_y = 0;
	map->new_map_square = (char **)malloc(sizeof(char *) * 22);
	ft_bzero(flag, sizeof(flag));
	while(map->array_2d[y])
	{
		x = 0;
		while (map->array_2d[y][x] == ' ')
		{
			x++;
		}
		if (ft_memcmp(map->array_2d[y] + x, "NO", ft_strlen("NO")) == 0)
		{
			if(flag[0] == 1)
			{
				flag[0] = 0;
				return (false);
			}
			else
			{
				printf("found NO\n");
				flag[0] = 1;
			}
		}
		else if (ft_memcmp(map->array_2d[y] + x, "SO", ft_strlen("SO")) == 0)
		{
			if(flag[1] == 1)
			{
				flag[1] = 0;
				return (false);
			}
			else
			{
				printf("found SO\n");
				flag[1] = 1;
			}
		}
		
		else if (ft_memcmp(map->array_2d[y] + x, "WE", ft_strlen("WE")) == 0)
		{
			if(flag[2] == 1)
			{
				flag[2] = 0;
				return (false);
			}
			else
			{
				printf("found WE\n");
				flag[2] = 1;
			}
		}
		
		else if (ft_memcmp(map->array_2d[y] + x, "EA", ft_strlen("EA")) == 0)
		{
			if (flag[3] == 1)
			{
				flag[3] = 0;
				return (false);
			}
			else
			{
				printf("found EA\n");
				flag[3] = 1;
			}
		}
		else if (ft_memcmp(map->array_2d[y] + x, "F", ft_strlen("F")) == 0)
		{
			if (flag[4] == 1)
			{
				flag[4] = 0;
				return (false);
			}
			else
			{
				printf("found F\n");
				flag[4] = 1;
			}
		}
		else if (ft_memcmp(map->array_2d[y] + x, "C", ft_strlen("C")) == 0)
		{
			if (flag[5] == 1)
			{
				flag[5] = 0;
				return (false);
			}
			else
			{
				printf("found C\n");
				flag[5] = 1;
			}
		}
		else if (ft_strchr(map->array_2d[y] + x , '1') || ft_strchr(map->array_2d[y] + x , '0'))
		{
			map->new_map_square[new_y] = ft_strdup(map->array_2d[y]);
			new_y++;
			remove_new_line(map);
			make_square(map);
			//printf("%s\n", map->new_map_square[new_y]);
		}
		y++;
	}
	map->new_map_square[new_y] = NULL;
	if(!(flag[0] && flag[1] && flag[2] && flag[3] && flag[4] && flag[5]))
		return(false);
}
