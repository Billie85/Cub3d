#include "cub3d.h"

void	Array_2D(t_map_info *map) //2次元配列にしている。関数
{
	char **buff;
	size_t	len;
	size_t	i;
	size_t	len01;

	map->height = 0;
	map->max_height = 0;
	map->max_width = 0;
	map->line = get_next_line(map->fd);

	while(map->line != NULL)
	{
		buff = map->array_2d;
		map->array_2d = (char **)malloc(sizeof(char *) * (map->height + 2));
		ft_memcpy(map->array_2d, buff, sizeof(char **) * map->height);
		free(buff);
		map->array_2d[map->height] = map->line;
		map->height++;
		map->max_height++;
		len = ft_strlen(map->line);
		if (len > map->max_width)
			map->max_width = len;
		map->line = get_next_line(map->fd);
	}
	map->array_2d[map->height] = NULL;

	//printf("%d-----------------\n",__LINE__);
	i = 0;
	map->height = 0;

	int x;
	int y;

	y = 0;
	while (y < map->max_height)//改行を見つけたらヌル終端にしてあげてる。関数
	{
		x = 0;
		while (x < map->max_width)
		{
			if (map->array_2d[y][x] == '\n')
				map->array_2d[y][x] = '\0';
			//printf("%c", map->array_2d[y][x]);fflush(stdout);
			x++;
		}
		y++;
	}
	while (map->array_2d[i])//ここで四角の部分を整えてあげてる。関数
	{
		map->new_malloc = (char *)malloc(sizeof(char ) * map->max_width + 1);
		ft_memset(map->new_malloc, '9', sizeof(char) * map->max_width);
		ft_memcpy(map->new_malloc, map->array_2d[i], ft_strlen(map->array_2d[i]));
		free(map->array_2d[i]);
		map->array_2d[i] = map->new_malloc;
		printf("%s\n", map->array_2d[i]);
		i++;
	}

	/* 
	   int	x = 0;
	   int	y = 0;
	   while(y < map->max_height)
	   {
	   x = 0;
	   while(x < map->max_width)
	   {
	//一旦ヌルまでの文字列を数えてみる。
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
	printf("%c", map->array_2d[y][x]);
	x++;
	}
	printf("\n");
	y++;
	} */
	//printf("------[%c]------\n", map->array_2d[0][14]);
	//printf("%d-----------------\n",__LINE__);fflush(stdout);
	//return (map->new_malloc);
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
	Array_2D(map);
	printf("max_height %ld\n", map->max_height);
	printf("max_width %ld\n", map->max_width);
	/* while(y < map->max_height)
	   {
	   x = 0;
	   while(x < map->max_width)
	   {
	//一旦ヌルまでの文字列を数えてみる。
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
	printf("%c", array[y][x]);
	x++;
	}
	printf("\n");
	y++;
	} */
	close(map->fd);
	system("leaks cub3d");
	return 0;
}

//一個ずつの情報を持つことができたから、
//次は２次元配列にしてあげて上下横の情報を持たせたげる事から続ける
//fflush(stdout);を付けてあげることでBUFFERに入ってるものを出力させないようにしてる。
