/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_around_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 05:40:18 by blyu              #+#    #+#             */
/*   Updated: 2022/12/25 05:40:19 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_map.h"

bool	check_map_right(t_map_info *map)
{
	size_t	x;
	size_t	y;
	size_t	flag;

	y = 0;
	x = map->square_width -2;
	while (map->new_map_square[y])
	{
		if (map->new_map_square[y][x] == '1' \
		|| map->new_map_square[y][x] == ' ')
			flag = true;
		else if (map->new_map_square[y][x] != '1' \
		|| map->new_map_square[y][x] != ' ')
			flag = false;
		if (flag == false)
			return (false);
		y++;
	}
	if (flag == false)
		return (false);
	else
		return (true);
}

bool	check_map_left(t_map_info *map)
{
	size_t	x;
	size_t	y;
	size_t	flag;

	x = 0;
	y = 0;
	flag = 0;
	while (map->new_map_square[y])
	{
		if (map->new_map_square[y][x] == '1' || \
			map->new_map_square[y][x] == ' ')
			flag = true;
		else if (map->new_map_square[y][x] != '1' \
		|| map->new_map_square[y][x] != ' ')
			flag = false;
		if (flag == false)
			return (false);
		y++;
	}
	if (flag == false)
		return (false);
	else
		return (true);
}

bool	check_map_under(t_map_info *map)
{
	size_t	y;
	size_t	x;
	size_t	flag;

	y = map->square_height -1;
	x = 0;
	flag = 0;
	while (map->new_map_square[y][x])
	{
		if (map->new_map_square[y][x] == '1' || \
			map->new_map_square[y][x] == ' ')
			flag = true;
		else if (map->new_map_square[y][x] != '1' || \
				map->new_map_square[y][x] != ' ')
			flag = false;
		if (flag == false)
			return (false);
		x++;
	}
	if (flag == false)
		return (false);
	else
		return (true);
}

bool	check_map_top(t_map_info *map)
{
	size_t	y;
	size_t	x;
	size_t	flag;

	y = 0;
	x = 0;
	flag = 0;
	while (map->new_map_square[y][x])
	{
		if (map->new_map_square[y][x] == '1' || \
			map->new_map_square[y][x] == ' ')
			flag = true;
		else if (map->new_map_square[y][x] != '1' || \
				map->new_map_square[y][x] != ' ')
			flag = false;
		if (flag == false)
			return (false);
		x++;
	}
	if (flag == false)
		return (false);
	else
		return (true);
}
