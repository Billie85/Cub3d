
/* # include "mlx_linux/mlx.h"
# include "mlx_linux/mlx.h" */
# include "get_next_line/get_next_line.h"
# include <math.h>
# include <stdio.h>
# include <string.h>

typedef struct s_map_info
{
	char	*line;
	int		fd;
	size_t	map_height;//高さ
	size_t	map_width; //幅
}t_map_info;
