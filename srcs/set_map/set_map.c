#include "set_map.h"

int	set_map(char *file_name)
{
	t_map_info	*Map;
	int		return_value;
	size_t	i;
	bool	r;

	Map = (t_map_info *)malloc(sizeof(t_map_info));
	Map->fd = open(file_name, O_RDONLY);
	Map->array_2d = (char **)malloc(sizeof(char *));
	r = map (0, 0, Map);
	close(Map->fd);
	i = 0;
	while (Map->array_2d[i])
	{
		free(Map->array_2d[i]);
		i++;
	}
	free(Map->array_2d);
	free(Map);
	if(r == false)
		return (1);
	else
		return (0);
}
