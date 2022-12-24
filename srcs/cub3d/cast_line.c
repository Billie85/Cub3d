/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 05:38:19 by blyu              #+#    #+#             */
/*   Updated: 2022/12/25 05:38:20 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cast_line_init(double r, t_f *fx, t_f *fy);
void	cast_line1(t_line *l, t_f *fx, t_f *fy);
void	cast_line2(t_line *l, t_f *fx, t_f *fy);
void	cast_line3(t_line *l, t_f *fx, t_f *fy);
void	cast_line4(t_line *l, t_f *fx, t_f *fy);

void	cast_line(t_now *n, t_line *l)
{
	t_f	fx;
	t_f	fy;

	cast_line_init(n->r, &fx, &fy);
	if (n->r < 0.5)
		cast_line1(l, &fx, &fy);
	else if (n->r < 1.0)
		cast_line2(l, &fx, &fy);
	else if (n->r < 1.5)
		cast_line3(l, &fx, &fy);
	else
		cast_line4(l, &fx, &fy);
}

void	cast_line_init(double r, t_f *fx, t_f *fy)
{
	fx->a = tan(r * M_PI);
	fx->b = now(0).y - tan(r * M_PI) * now(0).x;
	fy->a = 1.0 / tan(r * M_PI);
	fy->b = now(0).x - now(0).y / tan(r * M_PI);
}
