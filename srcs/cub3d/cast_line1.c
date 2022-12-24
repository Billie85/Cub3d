/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_line1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 05:38:26 by blyu              #+#    #+#             */
/*   Updated: 2022/12/25 05:38:27 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cast_line_ret_e(double rx, double ry, t_line *l);
void	cast_line_ret_n(double rx, double ry, t_line *l);
void	cast_line_ret_w(double rx, double ry, t_line *l);
void	cast_line_ret_s(double rx, double ry, t_line *l);

void	cast_line1(t_line *l, t_f *fx, t_f *fy)
{
	size_t	x;
	size_t	y;
	int		f;

	x = floor(now(0).x);
	y = floor(now(0).y);
	while (map(x, y, 0) != BLOCK)
	{
		f = 1;
		if (fx->a * (x + 1) + fx->b > (y + 1))
			f = 0;
		if (f)
			x++;
		else
			y++;
	}
	if (f)
		cast_line_ret_w(x, fx->a * x + fx->b, l);
	else
		cast_line_ret_s(fy->a * y + fy->b, y, l);
	return ;
}

void	cast_line2(t_line *l, t_f *fx, t_f *fy)
{
	size_t	x;
	size_t	y;
	int		f;

	x = floor(now(0).x) + 1;
	y = floor(now(0).y);
	while (map(x - 1, y, 0) != BLOCK)
	{
		f = 1;
		if (fx->a * (x - 1) + fx->b > (y + 1))
			f = 0;
		if (f)
			x--;
		else
			y++;
	}
	if (f)
		cast_line_ret_e(x, fx->a * x + fx->b, l);
	else
		cast_line_ret_s(fy->a * y + fy->b, y, l);
	return ;
}

void	cast_line3(t_line *l, t_f *fx, t_f *fy)
{
	size_t	x;
	size_t	y;
	int		f;

	x = floor(now(0).x) + 1;
	y = floor(now(0).y) + 1;
	while (map(x - 1, y - 1, 0) != BLOCK)
	{
		f = 1;
		if (fx->a * (x - 1) + fx->b < (y - 1))
			f = 0;
		if (f)
			x--;
		else
			y--;
	}
	if (f)
		cast_line_ret_e(x, fx->a * x + fx->b, l);
	else
		cast_line_ret_n(fy->a * y + fy->b, y, l);
	return ;
}

void	cast_line4(t_line *l, t_f *fx, t_f *fy)
{
	size_t	x;
	size_t	y;
	int		f;

	x = floor(now(0).x);
	y = floor(now(0).y) + 1;
	while (map(x, y - 1, 0) != BLOCK)
	{
		f = 1;
		if (fx->a * (x + 1) + fx->b < (y - 1))
			f = 0;
		if (f)
			x++;
		else
			y--;
	}
	if (f)
		cast_line_ret_w(x, fx->a * x + fx->b, l);
	else
		cast_line_ret_n(fy->a * y + fy->b, y, l);
	return ;
}
