/* # include "mlx_linux/mlx.h"
# include "mlx_linux/mlx.h" */
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
#include <stdbool.h>
# include <math.h>
# include <stdio.h>
# include <string.h>


# define FREE_ALL ~0LU
# define BACK       	"\x1b[0m"
# define RED			"\033[0;31m"
# define YELLOW		"\033[1;33m]" 
# define ORANGE		"\033[0;33m"
# define GREEN		"\033[0;32m"
# define CLAN		"\033[0;36m"
# define PURPLE		"\033[1;35m"
#define ZERO '0'
#define MAX_MAP_HEIGHT 500
#define DOWN y + 1
#define UP y - 1
#define LEFT x - 1
#define RIGHT x + 1

typedef enum e_return_info
{
	MAP_ERROR,
	BLOCK,
	SPACE,
	NONE,
}	t_return_info;

typedef struct s_map_info
{
	char	*new_malloc;
	char	**array_2d;
	char 	**direction_part;
	unsigned char	**new_map_square;
	char	*line;
	int		fd;
	size_t	height;
	size_t	width;
	size_t	square_width;
	size_t	square_height;
	size_t	max_width;
	size_t	max_height;
	size_t	x1;
	size_t	y1;
	char	*R;
	char	*F;
	char	*file_name;
}t_map_info;

int	map(size_t	x, size_t y, t_map_info *ch);
void	Array_2D(t_map_info *map);
void	make_square(t_map_info * map);
void	remove_new_line(t_map_info *map);
unsigned char 	**check_direction_map(t_map_info *map);
bool 	check_map_top(t_map_info * map);
bool	check_map_under(t_map_info *map);
bool	check_map_left(t_map_info *map);
bool	check_map_right(t_map_info *map);
bool	check_error_inside_map(t_map_info * map);
bool	map_inside_left(t_map_info *map);
bool	map_inside_right(t_map_info *map);
bool	map_inside_down(t_map_info *map);
bool	map_inside_up(t_map_info *map);
bool	check_error_around_map(t_map_info *map);
int		set_map(char *file_name);