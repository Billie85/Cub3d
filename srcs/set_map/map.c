#include "set_map.h"

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
	printf("aaaaaaa\n");
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
	return (true);
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
		*c = SPACE;
		n->r = 0.5;
		now(n);
	}
	else if (*c == 'E')
	{
		if (*f)
			return(1);
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
		*c = SPACE;
		n->r = 1.5;
		now(n);
	}
	else if (*c == 'W')
	{
		if (*f)
			return(1);
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
		*c = BACK;
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

	f = false;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			n.x = (double)x + 0.5;
			n.x = (double)y + 0.5;
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
	size_t	y;
	static char	**static_map;
	static size_t w;
	static size_t h;

	if (Map == (t_map_info *) FREE_ALL)
	{
		y = 0;
		while (static_map[y])
			free(static_map[y]);
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
		w = Map->square_width;
		h = Map->square_height;
		rev_map(static_map);
		if (check_error_around_map(Map) == false || set_now(static_map) == false)
			return (false);
		return (true);
	}
	if (x >= w || y >= h)
		return (MAP_ERROR);
	return ((int)static_map[x][y]);
}
