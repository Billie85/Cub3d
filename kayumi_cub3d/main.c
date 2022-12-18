#include "cub3d.h"

/* init_game を作ってあげる。->そこには最初にどの画像が必要になってくるかの情報が必要
->mlx_xpm_file_to_imageを使って画像を渡してあげる。
第2引数 ->最終的にdisplay_griを使って画面に映し出す。*/

//やるべき作業
//1.x y の座標を返してあげる関数(map関数の完成を優先させてあげる。)
//2.色の処理
//3.マップと方向の分け目を作ってあげる。方向がマップの方向に来てしまうとダメだから。
//もしかしたら最初の方向の処理の部分で、マップの所まで見てしまってるから、それでマップと方向の区別が必要になってきてる。
//4. 1 0 spを大文字で返す処理
//5. 方向の部分でpathを渡してあげる処理
//6. 画像の読み込みの処理が必要->画像を読み込んでその画像のpathを方向の関数に渡してあげる処理。


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

size_t main(size_t argc, char *argv[])
{
	void	*mlx;
	void	*win;
	void	*mlx_win;
	void	*img;
	char	*relative_path = "./animal.xpm";
	int		img_width;
	int		img_height;
	t_map_info	*Map;
	t_map_info	*hoge;
	size_t	width;
	size_t	len;
	int	retur_value;

	size_t	x = 1;
	size_t	y = 1;
	len = 0;
	width = 0;
	//mlx = mlx_init();
	//mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	//img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	Map = (t_map_info *)malloc(sizeof(t_map_info));
	Map->fd = open(argv[1], O_RDONLY);
	Map->array_2d = (char **)malloc(sizeof(char *));
	retur_value = map(x, y, Map, NULL);
	printf("return is ->[%c]\n", retur_value);
	close(Map->fd);
	system("leaks cub3d");
	return (0);
}
//fflush(stdout);を付けてあげることでBUFFERに入ってるものを出力させないようにしてる。