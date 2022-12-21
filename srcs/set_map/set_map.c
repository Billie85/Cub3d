#include "set_map.h"

int	set_map(char *file_name)
{
	t_map_info	*Map;
	int		return_value;
	size_t		x;
	size_t		y;

	x = 1;
	y = 1;
	Map = (t_map_info *)malloc(sizeof(t_map_info));
	Map->fd = open(file_name, O_RDONLY);
	Map->array_2d = (char **)malloc(sizeof(char *));
	if(map (0, 0, Map) == false)
		return (1);
		else
			return (0);
	close(Map->fd);
	return (0);
}
