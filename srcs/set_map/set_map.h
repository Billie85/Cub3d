/* # include "mlx_linux/mlx.h"
# include "mlx_linux/mlx.h" */
# include "../../libft/libft.h"
# include "../../get_next_line/get_next_line.h"
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
	char	**new_map_square;
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
char 	**check_direction_map(t_map_info *map);
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

#ifndef CUB3D_H
# define CUB3D_H

# define BLOCK 1
# define SPACE 2
# define NONE 3
# define MAP_ERROR 4

# define FREE_ALL ~0LU

typedef struct s_now
{
    double  x;
    double  y;
    double  r;
}t_now;

t_now 	now(t_now *set);
#endif

#ifndef DEBUG_H
#define DEBUG_H
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#define TEST printf("[(%s/%d) %s ]\n", __FILE__, __LINE__, __func__); fflush(stdin);
#define TEST_ printf("---------------------------------------------[(%s/%d) %s ]\n", __FILE__, __LINE__, __func__); fflush(stdin);
#define TESTn(i) printf("[(%s/%d) %s ]%s:%ld\n", __FILE__, __LINE__, __func__, #i, (long)(i)); fflush(stdin);
#define TESTu(i) printf("[(%s/%d) %s ]%s:%lu\n", __FILE__, __LINE__, __func__, #i, (unsigned long)(i)); fflush(stdin);
#define TESTx(i) printf("[(%s/%d) %s ]%s:%lx\n", __FILE__, __LINE__, __func__, #i, (unsigned long)(i)); fflush(stdin);
#define TESTd(i) printf("[(%s/%d) %s ]%s:%lf\n", __FILE__, __LINE__, __func__, #i, (double)(i)); fflush(stdin);
#define TESTp(i) printf("[(%s/%d) %s ]%s:%p\n", __FILE__, __LINE__, __func__, #i, (void *)(i)); fflush(stdin);
#define TESTs(i) printf("[(%s/%d) %s ]%s:%s\n", __FILE__, __LINE__, __func__, #i, (char *)(i)); fflush(stdin);
#define TESTc(i) printf("[(%s/%d) %s ]%s:%c\n", __FILE__, __LINE__, __func__, #i, (char)(i)); fflush(stdin);
#define FORn(i,j) {printf("[(%s/%d) %s ]%s:", __FILE__, __LINE__, __func__, #i);for(size_t test_arg = 0; test_arg j; test_arg++){printf("%ld, ", (long)((i)[test_arg]));} printf("\n"); fflush(stdin);}
#define FORu(i,j) {printf("[(%s/%d) %s ]%s:", __FILE__, __LINE__, __func__, #i);for(size_t test_arg = 0; test_arg j; test_arg++){printf("%lu, ", (unsigned long)((i)[test_arg]));} printf("\n"); fflush(stdin);}
#define FORx(i,j) {printf("[(%s/%d) %s ]%s:", __FILE__, __LINE__, __func__, #i);for(size_t test_arg = 0; test_arg j; test_arg++){printf("%lx, ", (unsigned long)((i)[test_arg]));} printf("\n"); fflush(stdin);}
#define FORd(i,j) {printf("[(%s/%d) %s ]%s:", __FILE__, __LINE__, __func__, #i);for(size_t test_arg = 0; test_arg j; test_arg++){printf("%lf, ", (double)((i)[test_arg]));} printf("\n"); fflush(stdin);}
#define FORp(i,j) {printf("[(%s/%d) %s ]%s:", __FILE__, __LINE__, __func__, #i);for(size_t test_arg = 0; test_arg j; test_arg++){printf("%p, ", (void *)((i)[test_arg]));} printf("\n"); fflush(stdin);}
#define FORs(i,j) {printf("[(%s/%d) %s ]%s:", __FILE__, __LINE__, __func__, #i);for(size_t test_arg = 0; test_arg j; test_arg++){printf("%s, ", (char *)((i)[test_arg]));} printf("\n"); fflush(stdin);}
#define FORc(i,j) {printf("[(%s/%d) %s ]%s:", __FILE__, __LINE__, __func__, #i);for(size_t test_arg = 0; test_arg j; test_arg++){printf("%c, ", (char)((i)[test_arg]));} printf("\n"); fflush(stdin);}
#define TAKE(i,j) {static size_t test_arg = 0; if(!(test_arg % j)){i} test_arg++;}
#define STOP {char c; read(STDIN_FILENO, &c, sizeof(char));}

#endif
