#include "../cub3d.h"

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
