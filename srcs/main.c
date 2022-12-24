#include "cub3d.h"

int set_head(char *file);
int set_map(char *file);

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return(printf("Error\n") * 0 + 1);
	mlx(mlx_init());
	win(mlx_new_window(mlx(0), DIS_W, DIS_H, "cub3d"));
	if (set_head(argv[1]) || set_map(argv[1]))
	{
		printf ("ERROR\n");
		return (1);
	}
	dis(0, 0, 0, SET);
	key(GO_NONE | TRN_NONE);
	mlx_loop_hook(mlx(0), cub3d, NULL);
	mlx_hook(win(0), 2, 0, set_key, NULL);
	mlx_hook(win(0), 3, 0, rm_key, NULL);
	mlx_hook(win(0), 17, 0, end_cub, NULL);
	mlx_loop(mlx(0));
	return (0);
}
