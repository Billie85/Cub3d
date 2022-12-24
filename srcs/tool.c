#include "cub3d.h"

void	free_list(void	*vp)
{
	size_t	i;
	char	**p;

	p = vp;
	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	return ;
}
