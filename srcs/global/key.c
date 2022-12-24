#include "../cub3d.h"

unsigned int	key(unsigned int set)
{
	static unsigned int	k;

	if (set & GO_)
	{
		k &= TRN_;
		k |= set;
	}
	if (set & TRN_)
	{
		k &= GO_;
		k |= set;
	}
	return (k);
}
