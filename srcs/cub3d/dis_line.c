/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 05:38:46 by blyu              #+#    #+#             */
/*   Updated: 2022/12/25 05:38:47 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dis_line1(t_line *l, size_t i);

void	dis_line(t_line *l, size_t i)
{
	double	y;
	double	pic_l;
	int		d;

	pic_l = tan((SEE / 2) * M_PI) * l->far * 2 / BL;
	d = DIS_H / 2 - 1;
	y = BL / 2 - MINI_NUM;
	while (d >= 0)
	{
		if (y >= 0)
		{
			dis(i, d, l->data[(int)floor(y)], CLOR);
			y -= pic_l;
		}
		else
			dis(i, d, ceiling(0), CLOR);
		d--;
	}
	dis_line1(l, i);
}

void	dis_line1(t_line *l, size_t i)
{
	double	y;
	double	pic_l;
	int		d;

	pic_l = tan((SEE / 2) * M_PI) * l->far * 2 / BL;
	d = DIS_H / 2;
	y = BL / 2;
	while (d < DIS_H)
	{
		if (y < BL)
		{
			dis(i, d, l->data[(int)floor(y)], CLOR);
			y += pic_l;
		}
		else
			dis(i, d, flooring(0), CLOR);
		d++;
	}
}
