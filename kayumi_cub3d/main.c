#include "cub3d.h"

int main(int argc, char *argv[])
{
	t_map_info *map;
	int i;
	int j;
	int count = 0;

	map = (t_map_info *)malloc(sizeof(t_map_info));
	map->fd = open(argv[1], O_RDONLY);

	i = 0;
	while(1)
	{
		map->array_2d[i] = get_next_line(map->fd);
		if (map->array_2d[i] == NULL)
			break;
		i++;
	}
	for (int x = 0; x < 6; x++)
	{
		for(int y = 0; y < 12; y++)
		{
			//if (map->array_2d[x][y] == '0')
			/* {
				printf("aaaaaaaaaaaa\n");
			} */
			printf("%c ", map->array_2d[x][y]);
		}
		printf("\n");
	}
		
	close(map->fd);
	system("leaks cub3d");
	return 0;
	}

















	//一個ずつの情報を持つことができたから、
	//次は２次元配列にしてあげて上下横の情報を持たせたげる事から続ける
	//fflush(stdout);を付けてあげることでBUFFERに入ってるものを出力させないようにしてる。
