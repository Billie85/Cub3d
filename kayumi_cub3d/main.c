#include "cub3d.h"

size_t	get_max_width(size_t len)
{
	size_t max_width;

	max_width = 0;
	if (len > max_width)
		max_width = len;
	return (max_width);
}

char **Array_2D(t_map_info *map)
{
	char **buff;
	size_t	len;

	map->height = 0;
	map->max_height = 0;
	map->max_width = 0;
	map->line = get_next_line(map->fd);

	while(map->line != NULL)
	{
		buff = map->array_2d;
		map->array_2d = (char **)malloc(sizeof(char *) * (map->width + 2));
		ft_memcpy(map->array_2d, buff, sizeof(char **) * map->width);
		free(buff);
		map->array_2d[map->width] = map->line;
		len = ft_strlen(map->array_2d[map->width]);
		map->width++;
		map->max_height++;
		map->line = get_next_line(map->fd);
		map->max_width = get_max_width(len);
	}
	return (map->array_2d);
}

int main(int argc, char *argv[])
{
	t_map_info *map;
	int width;
	size_t len;
	int	x;
	int	y;
	char **array;

	len = 0;
	width = 0;
	map = (t_map_info *)malloc(sizeof(t_map_info));
	map->fd = open(argv[1], O_RDONLY);

	map->array_2d = (char **)malloc(sizeof(char *));
	array = Array_2D(map);
	y = 0;
	while(y < map->max_height)
	{
		x = 0;
		while(x < map->max_width)
		{
			if (array[y][x] == '0')
			{
				if (array[DOWN][x] != ' ' && array[UP][x] != ' ' && array[y][LEFT] != ' ' && array[y][RIGHT] != ' ')
					printf("it's okay!!!\n");
				else
				{
					printf("ERROR!!\n");
					break;
				}
			}
			x++;
		}
		printf("\n");
		y++;
	}
	/* printf("max_width %ld\n", map->max_width);
	printf("max_height %ld\n", map->max_height); */
/* 	 y = 0;
	while (array[y] < map->max_height)
	{
		x = 0;
		while(array[x] < map->max_width)
		{
			if (map->array_2d[y][x] == '0')
			{
				if (map->array_2d[DOWN][x] != ' ' && map->array_2d[UP][x] != ' ' && map->array_2d[y][LEFT] != ' ' && map->array_2d[y][RIGHT] != ' ')
					printf("it's okay!!!\n");
				else
				{
					printf("ERROR!!\n");
					break;
				}
			}
			printf("%c\n", array[x][y]);fflush(stdout);
			x++;
		}
		y++;
	} */
	close(map->fd);
	system("leaks cub3d");
	return 0;
}

















//一個ずつの情報を持つことができたから、
//次は２次元配列にしてあげて上下横の情報を持たせたげる事から続ける
//fflush(stdout);を付けてあげることでBUFFERに入ってるものを出力させないようにしてる。
