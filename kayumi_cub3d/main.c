#include "cub3d.h"

int main(int argc, char *argv[])
{
	t_map_info *map;
	int i;

	map = (t_map_info *)malloc(sizeof(t_map_info));
	map->fd = open(argv[1], O_RDONLY);
	map->line = get_next_line(map->fd);
    while(map->line != NULL)//map->line != NULL
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
//fflush(stdout);を付けてあげることでBUFFERに入ってるものを出力させないようにしてる。
