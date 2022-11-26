/* # include "mlx_linux/mlx.h"
# include "mlx_linux/mlx.h" */
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <math.h>
# include <stdio.h>
# include <string.h>

#define ZERO '0'
#define MAX_MAP_HEIGHT 500
#define DOWN y + 1
#define UP y - 1
#define LEFT x - 1
#define RIGHT x + 1

typedef struct s_map_info
{
	char	**array_2d;
	char	*line;
	char	**file;
	int		fd;
}t_map_info;

typedef struct s_node
{
	struct s_node	*next;
	char			*str;
}t_node;
