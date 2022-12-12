#include "cub3d.h"

/* init_game を作ってあげる。->そこには最初にどの画像が必要になってくるかの情報が必要
->mlx_xpm_file_to_imageを使って画像を渡してあげる。
第2引数 ->最終的にdisplay_griを使って画面に映し出す。*/

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

	size_t	x = 0;
	size_t	y = 0;
	len = 0;
	width = 0;
	//mlx = mlx_init();
	//mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	//img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	Map = (t_map_info *)malloc(sizeof(t_map_info));
	Map->fd = open(argv[1], O_RDONLY);
	Map->array_2d = (char **)malloc(sizeof(char *));
	map(x, y, Map);
	printf("max_height %ld\n", Map->max_height);
	printf("max_width %ld\n", Map->max_width);
	close(Map->fd);
	system("leaks cub3d");
	return (0);
}
//fflush(stdout);を付けてあげることでBUFFERに入ってるものを出力させないようにしてる。
