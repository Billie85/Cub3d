#include "../set_map/set_map.h"

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
	if (map_inside_left(map) && map_inside_right(map) && map_inside_up(map) && map_inside_down(map))
	{
		printf("MAP IS OKAY\n");
		return (true);
	}
	else
		return (false);
}

bool	check_error_around_map(t_map_info *map)
{
	if (check_map_top(map) && check_map_under(map) && check_map_left(map) && check_map_right(map))
	{
		check_error_inside_map(map);
		return (true);
	}
	else
		return (false);
}

void	rev_map(char	**map)
{
	size_t l;
	size_t y;
	char	*buf;

	y = 0;
	l = 0;
	while (map[l])
		l++;
	while (y < l / 2)
	{
		buf = map[y];
		map[y] = map[l - 1 - y];
		map[l - 1 - y] = buf;
		y++;
	}
}

int	setting_now1(char *c, int *f, t_now *n);
int	setting_now2(char *c);

int	setting_now(char *c, int *f, t_now 	*n)
{
	if (*c == 'N')
	{
		if (*f)
			return(1);
		*f = 1;
		*c = SPACE;
		n->r = 0.5;
		now(n);
	}
	else if (*c == 'E')
	{
		if (*f)
			return(1);
		*f = 1;
		*c = SPACE;
		n->r = 1.0;
		now(n);
	}
	else 
		return (setting_now1(c, f, n));
	return (0);
}

int	setting_now1(char *c, int *f, t_now 	*n)
{
	if (*c == 'S')
	{
		if (*f)
			return(1);
		*f = 1;
		*c = SPACE;
		n->r = 1.5;
		now(n);
	}
	else if (*c == 'W')
	{
		if (*f)
			return(1);
		*f = 1;
		*c = SPACE;
		n->r = 0.0;
		now(n);
	}else
		return (setting_now2(c));
	return (0);
}

int	setting_now2(char *c)
{
	if (*c == '0')
		*c = SPACE;
	else if (*c == '1')
		*c = BLOCK;
	else if (*c == ' ')
		*c = NONE;
	else
		return (1);
	return (0);
}


bool	set_now(char	**map)
{
	size_t	x;
	size_t	y;
	int		f;
	t_now 	n;

	f = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			n.x = (double)x + 0.5;
			n.y = (double)y + 0.5;
			if (setting_now(&map[y][x], &f, &n))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}


int	map(size_t	x, size_t y, t_map_info *Map)
{
	size_t	i;
	static char	**static_map;
	static size_t w;
	static size_t h;

	if (Map == (t_map_info *) FREE_ALL)
	{	
		i = 0;
		while (static_map[i])
		{
			free(static_map[i]);
			i++;
		}
		free(static_map);
		return (0);
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
		w = Map->square_width;
		h = Map->square_height;
		rev_map(static_map);
		if (check_error_around_map(Map) == false || set_now(static_map) == false)
			return (false);
		return (true);
	}
	if (x >= w || y >= h)
		return (MAP_ERROR);
	return ((int)static_map[y][x]);
}
