#include "cub3d.h"

int		cub3d(void	*p)
{
	move();
	cast();
	return (0);
}

void move1(t_now *n);
void move()
{
	double ra;
	t_now n;

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

void move1(t_now *n)
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

void cast_line(t_now *n, t_line *l);

void dis_line(t_line *l, size_t i);

void cast()
{
	size_t i;
	t_now n;
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

void cast_line_init(double r, t_f *fx, t_f *fy);
void cast_line1(t_line *l, t_f *fx, t_f *fy);
void cast_line2(t_line *l, t_f *fx, t_f *fy);
void cast_line3(t_line *l, t_f *fx, t_f *fy);
void cast_line4(t_line *l, t_f *fx, t_f *fy);
void cast_line_retE(double rx, double ry, t_line *l);
void cast_line_retN(double rx, double ry, t_line *l);
void cast_line_retW(double rx, double ry, t_line *l);
void cast_line_retS(double rx, double ry, t_line *l);

void cast_line(t_now *n, t_line *l)
{
	t_f fx;
	t_f fy;
	
	cast_line_init(n->r, &fx, &fy);
	if (n->r < 0.5)
		cast_line1(l, &fx, &fy);
	else if (n->r < 1.0)
		cast_line2(l, &fx, &fy);
	else if (n->r < 1.5)
		cast_line3(l, &fx, &fy);
	else //(n->r < 2.0)
		cast_line4(l, &fx, &fy);
}

void cast_line_init(double r, t_f *fx, t_f *fy)
{
	fx->a = tan(r * M_PI);
	fx->b =  now(0).y - tan(r * M_PI) * now(0).x;
	fy->a = 1.0 / tan(r * M_PI);
	fy->b = now(0).x - now(0).y / tan(r * M_PI);
}



void cast_line1(t_line *l, t_f *fx, t_f *fy)
{
	size_t x;
	size_t y;
	double rx;
	double ry;
	int f;

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
		cast_line_retW(x, fx->a * x + fx->b, l);
	else
		cast_line_retS(fy->a * y + fy->b, y, l);
	return;

}

void cast_line2(t_line *l, t_f *fx, t_f *fy)
{
	size_t x;
	size_t y;
	double rx;
	double ry;
	int f;

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
		cast_line_retE(x, fx->a * x + fx->b, l);
	else
		cast_line_retS(fy->a * y + fy->b, y, l);
	return;

}

void cast_line3(t_line *l, t_f *fx, t_f *fy)
{
	size_t x;
	size_t y;
	double rx;
	double ry;
	int f;

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
		cast_line_retE(x, fx->a * x + fx->b, l);
	else
		cast_line_retN(fy->a * y + fy->b, y, l);
	return;

}

void cast_line4(t_line *l, t_f *fx, t_f *fy)
{
	size_t x;
	size_t y;
	double rx;
	double ry;
	int f;

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
		cast_line_retW(x, fx->a * x + fx->b, l);
	else
		cast_line_retN(fy->a * y + fy->b, y, l);
	return;

}

void cast_line_retW(double rx, double ry, t_line *l)
{
	double dx;
	double dy;

	dx = now(0).x - rx;
	dy = now(0).y - ry;
	l->far = sqrt(dx * dx + dy * dy);
	img(WEST, floor((floor(ry) + 1 - ry) * BL), l->data);
}

void cast_line_retN(double rx, double ry, t_line *l)
{
	double dx;
	double dy;

	dx = now(0).x - rx;
	dy = now(0).y - ry;
	l->far = sqrt(dx * dx + dy * dy);
	img(NORTH, floor((floor(rx) + 1 - rx) * BL), l->data);
}

void cast_line_retE(double rx, double ry, t_line *l)
{
	double dx;
	double dy;

	dx = now(0).x - rx;
	dy = now(0).y - ry;
	l->far = sqrt(dx * dx + dy * dy);
	img(EAST, floor((ry - floor(ry)) * BL), l->data);
}

void cast_line_retS(double rx, double ry, t_line *l)
{
	double dx;
	double dy;

	dx = now(0).x - rx;
	dy = now(0).y - ry;
	l->far = sqrt(dx * dx + dy * dy);
	img(SOUTH, floor((rx - floor(rx)) * BL), l->data);
}

void	dis_line1(t_line *l, size_t i);
void	dis_line(t_line *l, size_t i)
{
	double y;
	double pic_l;
	int	d;

	pic_l = tan((SEE / 2) * M_PI) * l->far * 2/ BL;
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
	double y;
	double pic_l;
	int	d;

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
