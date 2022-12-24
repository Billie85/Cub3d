/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 05:39:21 by blyu              #+#    #+#             */
/*   Updated: 2022/12/25 05:39:22 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../set_map/set_map.h"

int	setting_now1(char *c, int *f, t_now *n);
int	setting_now2(char *c);

int	setting_now(char *c, int *f, t_now *n)
{
	if (*c == 'N')
	{
		if (*f)
			return (1);
		*f = 1;
		*c = SPACE;
		n->r = 0.5;
		now(n);
	}
	else if (*c == 'E')
	{
		if (*f)
			return (1);
		*f = 1;
		*c = SPACE;
		n->r = 1.0;
		now(n);
	}
	else
		return (setting_now1(c, f, n));
	return (0);
}

int	setting_now1(char *c, int *f, t_now *n)
{
	if (*c == 'S')
	{
		if (*f)
			return (1);
		*f = 1;
		*c = SPACE;
		n->r = 1.5;
		now(n);
	}
	else if (*c == 'W')
	{
		if (*f)
			return (1);
		*f = 1;
		*c = SPACE;
		n->r = 0.0;
		now(n);
	}
	else
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
	t_now	n;

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
