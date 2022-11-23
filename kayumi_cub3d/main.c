#include "cub3d.h"

int main(int argc, char *argv[])
{
	t_map_info *map;
	int i;
	size_t len;
	size_t max_width;
	size_t max_height;
	int	x;
	int	y;
	
	i = 0;
	len = 0;
	max_width = 0;
	max_height = 0;
	map = (t_map_info *)malloc(sizeof(t_map_info));
	map->fd = open(argv[1], O_RDONLY);
	while(1)
	{
		map->array_2d[i] = get_next_line(map->fd);
		if (map->array_2d[i] == NULL)
			break;
		len = ft_strlen(map->array_2d[i]);
		if (len > max_width)
			max_width = len;
		i++;
		max_height++;
	}
	/* printf("height %ld\n", max_height);
	printf("width %ld\n", max_width); */

//マップが大きいとちょっと文字化けするかも。
	y = 0;
	while (y < max_height)
	{
		x = 0;
		while(x < max_width)
		{
			if (map->array_2d[y][x] == '0')
			{
				printf("down [%c]\n", map->array_2d[y + 1][x]);//4
				printf("up [%c]\n", map->array_2d[y - 1][x]);//2
				printf("left [%c]\n", map->array_2d[y][x - 1]);//8
				printf("right [%c]\n", map->array_2d[y][x + 1]);//5
			}
			//printf("%c", map->array_2d[x][y]);fflush(stdout);
			x++;
		}
		y++;
	}
	close(map->fd);
	system("leaks cub3d");
	return 0;
	}

















	//一個ずつの情報を持つことができたから、
	//次は２次元配列にしてあげて上下横の情報を持たせたげる事から続ける
	//fflush(stdout);を付けてあげることでBUFFERに入ってるものを出力させないようにしてる。
