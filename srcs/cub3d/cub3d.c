/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 05:38:40 by blyu              #+#    #+#             */
/*   Updated: 2022/12/25 05:38:41 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move1(t_now *n);
void	cast_line(t_now *n, t_line *l);
void	dis_line(t_line *l, size_t i);

int	cub3d(void	*p)
{
	(void)p;
	move();
	cast();
	return (0);
}

void	move(void)
{
	double	ra;
	t_now	n;

	n = now(0);
	if ((key(0) & GO_) == GO_F)
		ra = 0;
	else if ((key(0) & GO_) == GO_L)
		ra = 0.5;
	else if ((key(0) & GO_) == GO_B)
		ra = 1;
	else if ((key(0) & GO_) == GO_R)
		ra = 1.5;
	if ((key(0) & GO_) != GO_NONE)
	{
		n.x += cos((n.r + ra) * M_PI) * GO_LEN;
		n.y += sin((n.r + ra) * M_PI) * GO_LEN;
	}
	move1(&n);
}

void	move1(t_now *n)
{
	if ((key(0) & TRN_) == TRN_L)
		n->r += TRN_LEN;
	else if ((key(0) & TRN_) == TRN_R)
		n->r -= TRN_LEN;
	while (n->r >= 2.0)
		n->r -= 2.0;
	while (n->r < 0.0)
		n->r += 2.0;
	*n = now(n);
}

void	cast(void)
{
	size_t	i;
	t_now	n;
	t_line	l;

	n = now(0);
	n.r += SEE / 2;
	i = 0;
	while (i < DIS_W)
	{
		while (n.r >= 2.0)
			n.r -= 2.0;
		while (n.r < 0.0)
			n.r += 2.0;
		cast_line(&n, &l);
		l.far *= cos((now(0).r - n.r) * M_PI);
		if (l.far < 0)
			l.far *= -1;
		dis_line(&l, i);
		n.r -= SEE / DIS_W;
		i++;
	}
	dis(0, 0, 0, FLUSH);
	return ;
}
