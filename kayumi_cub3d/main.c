#include "cub3d.h"

size_t largest_word(char *s[100])
{
	size_t	i;
	size_t	len;
	size_t	longest;
	size_t	j;

	longest = ft_strlen(s[3]);
	printf("%ld\n", longest);
	 i = 1;
	while(i < len)
	{
		len = ft_strlen(s[i]);
		if (longest < len)
		{
			longest = len;
			j = i;
		}
		i++;
	}
	//printf("%s", s[i]);
	return(longest);
}

int main(int argc, char *argv[])
{
	t_map_info *map;
	int i;
	size_t len;
	size_t max_width;
	size_t max_height;
	
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
	for (int x = 0; x < max_height; x++)
	{
		for(int y = 0; y < max_width -1; y++)
		{
		/* 	if (map->array_2d[x][y] == '0')
			{
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
