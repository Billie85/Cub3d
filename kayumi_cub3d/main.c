#include "cub3d.h"

int main(int argc, char *argv[])
{
	t_map_info map;
	int	i;

	(void)argc;
	map.fd = open(argv[1], O_RDONLY);
	while(1)
	{
		map.line = get_next_line(map.fd);
		printf("line is %s", map.line);
		if (map.line == NULL)
			break;
	}
}