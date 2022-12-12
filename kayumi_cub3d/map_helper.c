#include "cub3d.h"

void	remove_new_line(t_map_info *map)//改行を見つけたらヌル終端にしてあげてる。関数
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map->array_2d[y])
	{
		x = 0;
		while (map->array_2d[y][x])
		{
			if (map->array_2d[y][x] == '\n')
			{
				map->array_2d[y][x] = '\0';
			}
			x++;
		}
		//printf("%s", map->array_2d[y]);
		y++;
	}
}

void	make_square(t_map_info * map)//ここで四角の部分を整えてあげてる
{
	size_t	i;

	i = 0;
	while (map->array_2d[i])
	{
		if (ft_strncmp(map->array_2d[i], " ", 1) == 0 || ft_strncmp(map->array_2d[i], "0", 1) == 0)
		{
			map->new_malloc = (char *)malloc(sizeof(char ) * map->max_width + 1);
			ft_memset(map->new_malloc, '-', sizeof(char) * map->max_width);
			ft_memcpy(map->new_malloc, map->array_2d[i], ft_strlen(map->array_2d[i]));
			free(map->array_2d[i]);
			map->array_2d[i] = map->new_malloc;//これなくても大丈夫
		}
		i++;
	}
	//return (map->array_2d);
	/* 	i = 0;----//出力テスト----
		while(map->array_2d[i])
		{
		printf("%s\n", map->array_2d[i]);
		i++;
		} */
}

void	check_around_map(t_map_info *map)
	//周りが1で囲まれているかどうかを確認する関数を作る。
	//マップの周りが１もしくは空白があった場合はOKにしてる。
	//freeするエラー処理だったりもう少し書かないといけないかも。
{
	size_t x;
	size_t y;
	size_t i;
	size_t j;
	size_t	topmost_y;
	size_t	lowest_y;
	size_t	left_x;
	size_t	right_x;

		y = 0;
		while(map->array_2d[y])
		{
			x = 0;
			while (map->array_2d[y][x] == ' ')
			{
				x++;
			}
			if (map->array_2d[y][x] == '1' || map->array_2d[y][x] == ' ')
		{
			printf("%c\n", map->array_2d[y][x]);
			//printf("this is a map!\n");
		}
			y++;
		}
	}

void	check_inside_the_map(t_map_info *map)
{
	size_t	x;
	size_t	y;

	//printf("[%c]\n", map->array_2d[1][1]);
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

void	Array_2D(t_map_info *map)//2次元配列にしてあげてる
{
	char **buff;
	size_t	len;
	size_t	len01;
	size_t	x, y;

	x = 0;
	y = 0;
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
		//一つの関数にできる。//もしもここでどれかなかった場合はbreakで終了してあげる。
		//違う関数でmap->array2dに格納されている文字を比較する　1 || 0 || sp がどれかあればマップになる条件を作ってあげる。
		map->line = get_next_line(map->fd);
	}
	map->array_2d[map->height] = NULL;
}
