#include "cub3d.h"

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
	map (0, 0, Map);
	//return_value = map(x, y, NULL);
	//printf("map return value is ->[%c]\n", return_value);
	close(Map->fd);
	//system("leaks cub3d");
	return (0);
}
