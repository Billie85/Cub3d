#include "set_map.h"

int		check_direction_map_while(t_map_info *map, size_t y, size_t *flag);
char	**check_direction_map1(t_map_info *map, size_t y, size_t *flag);

char	**check_direction_map(t_map_info *map)
{
	size_t	y;
	size_t	flag[7];

	y = 0;
	map->new_map_square = malloc(sizeof(char *) * map->max_height);
	ft_bzero(flag, sizeof(flag));
	while (map->array_2d[y])
	{
		if (check_direction_map_while(map, y, flag))
			break ;
		if (flag[6])
			return (false);
		y++;
	}
	return (check_direction_map1(map, y, flag));
}

int	check_direction_map_while(t_map_info *map, size_t y, size_t *flag)
{
	size_t	x;

	x = 0;
	while (map->array_2d[y][x] == ' ')
		x++;
	if (ft_memcmp(map->array_2d[y] + x, "NO", ft_strlen("NO")) == 0)
		flag[6] = flag[0]++;
	else if (ft_memcmp(map->array_2d[y] + x, "SO", ft_strlen("SO")) == 0)
		flag[6] = flag[1]++;
	else if (ft_memcmp(map->array_2d[y] + x, "WE", ft_strlen("WE")) == 0)
		flag[6] = flag[2]++;
	else if (ft_memcmp(map->array_2d[y] + x, "EA", ft_strlen("EA")) == 0)
		flag[6] = flag[3]++;
	else if (ft_memcmp(map->array_2d[y] + x, "F", ft_strlen("F")) == 0)
		flag[6] = flag[4]++;
	else if (ft_memcmp(map->array_2d[y] + x, "C", ft_strlen("C")) == 0)
		flag[6] = flag[5]++;
	else if (ft_strchr(map->array_2d[y] + x, '1') || \
	ft_strchr(map->array_2d[y] + x, '0'))
		return (1);
	return (0);
}

char	**check_direction_map1(t_map_info *map, size_t y, size_t *flag)
{
	size_t	new_y;

	new_y = 0;
	while (map->array_2d[y])
	{
		remove_new_line(map);
		make_square(map);
		map->new_map_square[new_y] = ft_strdup(map->array_2d[y]);
		new_y++;
		y++;
	}
	map->new_map_square[new_y] = NULL;
	if (!(flag[0] && flag[1] && flag[2] && flag[3] && flag[4] && flag[5]))
		return (false);
	else
		return (map->new_map_square);
}
