/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_line2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 05:38:34 by blyu              #+#    #+#             */
/*   Updated: 2022/12/25 05:38:35 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cast_line_ret_w(double rx, double ry, t_line *l)
{
	double	dx;
	double	dy;

	dx = now(0).x - rx;
	dy = now(0).y - ry;
	l->far = sqrt(dx * dx + dy * dy);
	img(WEST, floor((floor(ry) + 1 - ry) * BL), l->data);
}

void	cast_line_ret_n(double rx, double ry, t_line *l)
{
	double	dx;
	double	dy;

	dx = now(0).x - rx;
	dy = now(0).y - ry;
	l->far = sqrt(dx * dx + dy * dy);
	img(NORTH, floor((floor(rx) + 1 - rx) * BL), l->data);
}

void	cast_line_ret_e(double rx, double ry, t_line *l)
{
	double	dx;
	double	dy;

	dx = now(0).x - rx;
	dy = now(0).y - ry;
	l->far = sqrt(dx * dx + dy * dy);
	img(EAST, floor((ry - floor(ry)) * BL), l->data);
}

void	cast_line_ret_s(double rx, double ry, t_line *l)
{
	double	dx;
	double	dy;

	dx = now(0).x - rx;
	dy = now(0).y - ry;
	l->far = sqrt(dx * dx + dy * dy);
	img(SOUTH, floor((rx - floor(rx)) * BL), l->data);
}
