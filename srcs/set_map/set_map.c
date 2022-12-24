#include "set_map.h"

int	set_map(char *file_name)
{
	t_map_info	*m;
	size_t		i;
	bool		r;

	m = (t_map_info *)malloc(sizeof(t_map_info));
	ft_bzero(m, sizeof(t_map_info));
	m->fd = open(file_name, O_RDONLY);
	m->array_2d = (char **)malloc(sizeof(char *));
	r = map(0, 0, m);
	close(m->fd);
	i = 0;
	while (m->array_2d[i])
	{
		free(m->array_2d[i]);
		i++;
	}
	free(m->array_2d);
	free(m);
	if (r == false)
		return (1);
	else
		return (0);
}
