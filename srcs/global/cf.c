#include "../cub3d.h"
unsigned int	flooring(unsigned int set)
{
	static unsigned c;

	if (set)
		c = set;
	return (c);
}

unsigned int	ceiling(unsigned int set)
{
	static unsigned c;

	if (set)
		c = set;
	return (c);
}