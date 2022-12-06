#include "cub3d.h"

size_t main(size_t argc, char *argv[])
{
	size_t	x = 0;
	size_t	y = 0;
	t_map_info *Map;
	t_map_info *hoge;
	size_t width;
	size_t len;

	len = 0;
	width = 0;
	Map = (t_map_info *)malloc(sizeof(t_map_info));
	Map->fd = open(argv[1], O_RDONLY);
	Map->array_2d = (char **)malloc(sizeof(char *));
	map(x, y, Map);
	printf("max_height %ld\n", Map->max_height);
	printf("max_width %ld\n", Map->max_width);
	close(Map->fd);
	system("leaks cub3d");
	return 0;
}
//一個ずつの情報を持つことができたから、
//次は２次元配列にしてあげて上下横の情報を持たせたげる事から続ける
//fflush(stdout);を付けてあげることでBUFFERに入ってるものを出力させないようにしてる。
