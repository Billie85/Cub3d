/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 05:39:17 by blyu              #+#    #+#             */
/*   Updated: 2022/12/25 05:39:18 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../set_map/set_map.h"

void	count_square_map(t_map_info *map)
{
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
	if (map_inside_left(map) && map_inside_right(map) && \
	map_inside_up(map) && map_inside_down(map))
		return (true);
	else
		return (false);
}

bool	check_error_around_map(t_map_info *map)
{
	if (check_map_top(map) && check_map_under(map) && \
	check_map_left(map) && check_map_right(map))
	{
		check_error_inside_map(map);
		return (true);
	}
	else
		return (false);
}

void	rev_map(char	**map)
{
	size_t	l;
	size_t	y;
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

bool	set_now(char	**map);
void	free_list(void	*vp);

int	map(size_t	x, size_t y, t_map_info *Map)
{
	static char		**static_map;
	static size_t	w;
	static size_t	h;

	if (Map == (t_map_info *) FREE_ALL)
		free_list((void *)static_map);
	else if (Map != NULL)
	{
		array_2d(Map);
		static_map = check_direction_map(Map);
		if (static_map == false)
			return (false);
		count_square_map(Map);
		w = Map->square_width;
		h = Map->square_height;
		rev_map(static_map);
		if (check_error_around_map(Map) == false || \
		set_now(static_map) == false)
			return (false);
		return (true);
	}
	if (x >= w || y >= h)
		return (MAP_ERROR);
	return ((int)static_map[y][x]);
}
