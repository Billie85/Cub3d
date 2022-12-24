/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_inside.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 05:40:34 by blyu              #+#    #+#             */
/*   Updated: 2022/12/25 05:40:36 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_map.h"

int	is_space(char c);
int	is_map_elm(char c);

bool	map_inside_down(t_map_info *map)
{
	size_t	x;
	size_t	y;
	size_t	flag;

	y = 1;
	flag = 1;
	while (map->new_map_square[y])
	{
		x = 1;
		while (map->new_map_square[y][x])
		{
			if (is_space(map->new_map_square[y][x]))
			{
				if (is_map_elm(map->new_map_square[y + 1][x]))
					flag = true;
				else
					flag = false;
			}
			x++;
			if (flag == false)
				return (false);
		}
		y++;
	}
	return (flag);
}

bool	map_inside_up(t_map_info *map)
{
	size_t	x;
	size_t	y;
	size_t	flag;

	y = 1;
	flag = 1;
	while (map->new_map_square[y])
	{
		x = 1;
		while (map->new_map_square[y][x])
		{
			if (is_space(map->new_map_square[y][x]))
			{
				if (is_map_elm(map->new_map_square[y - 1][x]))
					flag = true;
				else
					flag = false;
			}
			x++;
			if (flag == false)
				return (false);
		}
		y++;
	}
	return (flag);
}

bool	map_inside_right(t_map_info *map)
{
	size_t	x;
	size_t	y;
	size_t	flag;

	y = 1;
	flag = 1;
	while (map->new_map_square[y])
	{
		x = 1;
		while (map->new_map_square[y][x])
		{
			if (is_space(map->new_map_square[y][x]))
			{
				if (is_map_elm(map->new_map_square[y][x + 1]))
					flag = true;
				else
					flag = false;
			}
			x++;
			if (flag == false)
				return (false);
		}
		y++;
	}
	return (flag);
}

bool	map_inside_left(t_map_info *map)
{
	size_t	x;
	size_t	y;
	size_t	flag;

	flag = 1;
	y = 1;
	while (map->new_map_square[y])
	{
		x = 1;
		while (map->new_map_square[y][x])
		{
			if (is_space(map->new_map_square[y][x]))
			{
				if (is_map_elm(map->new_map_square[y][x -1]))
					flag = true;
				else
					flag = false;
			}
			x++;
			if (flag == false)
				return (false);
		}
		y++;
	}
	return (flag);
}
