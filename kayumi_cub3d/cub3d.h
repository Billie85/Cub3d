/* # include "mlx_linux/mlx.h"
# include "mlx_linux/mlx.h" */
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <math.h>
# include <stdio.h>
# include <string.h>

#define ZERO '0'

typedef struct s_map_info
{
	char	*line;
	int		fd;
	size_t	height;
	size_t	width;
}t_map_info;

typedef struct s_node
{
	struct s_node	*next;
	char			*str;
}t_node;
