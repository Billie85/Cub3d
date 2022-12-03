#include "cub3d.h"

void	remove_new_line(t_map_info *map)//改行を見つけたらヌル終端にしてあげてる。関数
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->max_height)
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
}

void	make_square(t_map_info * map)//ここで四角の部分を整えてあげてる
{
	size_t	i;

	i = 0;
	while (map->array_2d[i])
	{
		map->new_malloc = (char *)malloc(sizeof(char ) * map->max_width + 1);
		ft_memset(map->new_malloc, ' ', sizeof(char) * map->max_width);
		ft_memcpy(map->new_malloc, map->array_2d[i], ft_strlen(map->array_2d[i]));
		free(map->array_2d[i]);
		map->array_2d[i] = map->new_malloc;
		i++;
	}
}

void	check_around_map(t_map_info *map)
//周りが1で囲まれているかどうかを確認する関数を作る。
//マップの周りが１もしくは空白があった場合はOKにしてる。
//freeするエラー処理だったりもう少し書かないといけないかも。
{
	size_t x;
	size_t y;
	size_t	topmost_y;
	size_t	lowest_y;
	size_t	left_x;
	size_t	right_x;

	x = 0;
	topmost_y = 0;
	lowest_y = map->max_height -1;
	while (x < map->max_width)
	{
		if (map->array_2d[topmost_y][x] != '1' && map->array_2d[topmost_y][x] != ' ')
		{
			printf("ERROR001\n");
			break;
		}
		if (map->array_2d[lowest_y][x] != '1' && map->array_2d[lowest_y][x] != ' ')
		{
			printf("ERROR001002\n");
			break;
		}
		x++;
	}

	y = 0;
	left_x = 0;
	right_x = map->max_width -2;
	while (y < map->max_height)
	{
		if (map->array_2d[y][left_x] != '1' && map->array_2d[y][left_x] != ' ')
		{
			printf("ERROR!!\n");
			break;

		}
		if (map->array_2d[y][right_x] != '1' && map->array_2d[y][right_x] != ' ')
		{
			printf("ERROR!!\n");
			break;
		}
		y++;
	}
}

void	check_inside_the_map(t_map_info *map)
{
	size_t	x;
	size_t	y;

	printf("[%c]\n", map->array_2d[1][1]);
	y = 1;
	while (y < map->max_height)
	{
		x = 1;
		while (x < map->max_width)
		{
			if (map->array_2d[y][x] == '0')
			{
				if (map->array_2d[DOWN][x] == ' '  || map->array_2d[UP][x] == ' ' || map->array_2d[y][LEFT] == ' ' || map->array_2d[y][RIGHT] == ' ')
				printf("ERROR WE HAVE A SPACE!!!\n");
				break;
			}
			x++;
		}
		y++;
	}
}

void	Array_2D(t_map_info *map)//2次元配列にしている
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

	i = 0;
	map->height = 0;
}

size_t main(size_t argc, char *argv[])
{
	t_map_info *map;
	t_map_path *path_map;
	size_t width;
	size_t len;
	size_t	x;
	size_t	y;
	char **array;

	len = 0;
	width = 0;
	map = (t_map_info *)malloc(sizeof(t_map_info));
	path_map = (t_map_path *)malloc(sizeof(t_map_path));
	map->fd = open(argv[1], O_RDONLY);

	map->array_2d = (char **)malloc(sizeof(char *));
	Array_2D(map);
	remove_new_line(map);
	make_square(map);
	check_inside_the_map(map);
	check_around_map(map);
	printf("max_height %ld\n", map->max_height);
	printf("max_width %ld\n", map->max_width);
	close(map->fd);
	system("leaks cub3d");
	return 0;
}

//一個ずつの情報を持つことができたから、
//次は２次元配列にしてあげて上下横の情報を持たせたげる事から続ける
//fflush(stdout);を付けてあげることでBUFFERに入ってるものを出力させないようにしてる。
