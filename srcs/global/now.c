#include "../cub3d.h"

t_now 	now(t_now *set)
{
	static t_now n;

	if (set)
	{
//TESTn(map((size_t)floor(set->x), (size_t)floor(set->y), 0) == SPACE)
/* TESTn(floor(set->x))
TESTn(floor(set->y))
TESTn(map((size_t)floor(set->x), (size_t)floor(set->y), 0) == SPACE)
TESTc(map((size_t)floor(set->x), (size_t)floor(set->y), 0))
TESTn(map((size_t)floor(set->x), (size_t)floor(set->y), 0)) STOP */
		if (map((size_t)floor(set->x), (size_t)floor(set->y), 0) == SPACE)
			n = *set;
		else
			n.r = set->r;
	}
	return (n);
}