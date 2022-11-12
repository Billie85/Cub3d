#include "cub3d.h"

/* void	split_line(t_map_info *map)
{
	int	i;
	int	atoi_i;
	char **str;
	
	i = 0;
	atoi_i = (int *)malloc(sizeof(int));
			str = ft_split(map->line, '\n');
			while (str[i] != NULL)
			{
				atoi_i[i] = ft_atoi(str[i]);
				printf("%d\n", atoi_i[i]);
				free(str[i]);
				i++;
			}
			free(str);
} */

int	find_0(t_map_info *map)
{

}

void	read_get_line_map(char *argv[], t_map_info *map)
{

	map->fd = open(argv[1], O_RDONLY);
	while(1)
	{
		map->line = get_next_line(map->fd);
		printf("%s", map->line);
		if (map->line == NULL)
			break;
			if(ft_strchr(map->line, ZERO) != 0)
			{
				printf("found!\n");
			}
			else
			printf("not found\n");
			free(map->line);
	}
}

int main(int argc, char *argv[])
{
	t_map_info *map;

	map = (t_map_info *)malloc(sizeof(t_map_info));//忘れがち
	read_get_line_map(argv, map);
	return (0);
}