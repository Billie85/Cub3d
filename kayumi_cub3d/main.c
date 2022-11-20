#include "cub3d.h"

char *remove_zero(char *str)
{
	size_t  i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '0')
			return (str);
	}
}

int main(int argc, char *argv[])
{
	t_map_info *map;
	char **split;
	char *find;
	char *hoge;
	char *check_wall;
	int i;

	i = 0;
	map = (t_map_info *)malloc(sizeof(t_map_info));
	map->fd = open(argv[1], O_RDONLY);
	map->line = get_next_line(map->fd);
	while (map->line[i] != '\0')
	{
		if (map->line[i] != ' ' && map->line[i] != '1')
		{
			//printf("the map it's wrong\n");
			break;
		}
		else
			//printf("it's okay\n");
		i++;
	}
	//free(map->line);

    while(map->line)//map->line != NULL
    {
        i = 0;
        while(map->line[i])
        {
            printf("%c", map->line[i]);fflush(stdout);
            i++;
        }
        free(map->line);
        map->line = get_next_line(map->fd);
    }

	close(map->fd);
    system("leaks cub3d");
	return 0;
}
//一個ずつの情報を持つことができたから、
//次は２次元配列にしてあげて上下横の情報を持たせたげる事から続ける
