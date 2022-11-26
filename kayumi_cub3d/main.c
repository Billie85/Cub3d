#include "cub3d.h"

size_t	get_max_width(size_t len)
{
	size_t max_width;

	max_width = 0;
	if (len > max_width)
		max_width = len;
	return (max_width);
}

int main(int argc, char *argv[])
{
	t_map_info *map;
	int height;
	int width;
	size_t len;
	size_t max_width;
	size_t max_height;
	int	x;
	int	y;
	char **buff;

	len = 0;
	max_width = 0;
	max_height = 0;
	width = 0;
	map = (t_map_info *)malloc(sizeof(t_map_info));
	map->fd = open(argv[1], O_RDONLY);

	map->array_2d = (char **)malloc(sizeof(char *));
	
	height = 0;
	map->line = get_next_line(map->fd);
	while(map->line != NULL)
	{
		buff = map->array_2d;
		map->array_2d = (char **)malloc(sizeof(char *) * (height + 2));

		ft_memcpy(map->array_2d, buff, sizeof(char **) * height);
		free(buff);
		map->array_2d[height] = map->line;
		printf("%s", map->array_2d[height]);
		height++;
		map->line = get_next_line(map->fd);
	}
	//printf("%d", map->array_2d[0][0]);
	map->array_2d[height] = NULL;
	/* while(1)
	   {
	   map->array_2d[i] = get_next_line(map->fd);
	   if (map->array_2d[i] == NULL)
	   break;
	   len = ft_strlen(map->array_2d[i]);
	   max_width = get_max_width(len);
	   i++;
	   max_height++;
	   }
	   printf("max_width [%ld]\n", max_width);
	   printf("max_height [%ld]\n", max_height); */
	/* 	y = 0;
		while (y < max_height)
		{
		x = 0;
		while(x < max_width)
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
		printf("%c", map->array_2d[x][y]);fflush(stdout);
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
