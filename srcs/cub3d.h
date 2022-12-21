#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <float.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../minilibx_mms_20200219/mlx.h"

# define BL 30
# define DIS_W 1200
# define DIS_H 800

# define SEE 0.4

# define ESC_KEY 53
# define TL_KEY 123
# define TR_KEY 124
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

# define GO_LEN   0.01
# define TRN_LEN  0.01

# define GO_      0x0f
# define TRN_     0xf0

# define GO_F     0x01
# define GO_B     0x02
# define GO_L     0x03
# define GO_R     0x04
# define GO_NONE  0x05

# define TRN_L    0x10
# define TRN_R    0x20
# define TRN_NONE 0x30

# define NORTH 0
# define EAST 1
# define SOUTH 2
# define WEST 3

#define BLOCK 1
#define SPACE 2
#define NONE 3
#define MAP_ERROR 4

# define CLOR 2
# define FLUSH 3
# define GET 3
# define SET 0xf
# define FREE_ALL ~0LU

#define MINI_NUM 0.000000000000001

#define BUFER_SIZE 1024

typedef struct s_now
{
    double  x;
    double  y;
    double  r;
}t_now;

typedef struct s_line
{
    unsigned data[BL];
    double far;
}t_line;

typedef struct s_f
{
    double a;
    double b;
}t_f;


int setting(char *file);
char **split_line(const char *str, size_t header);


//global

typedef struct s_map_info t_map_info;

void	*mlx(void *set);
void	*win(void *set);
unsigned 	key(unsigned set);
t_now 	now(t_now *set);
void 	img(int flag, size_t len, unsigned *io);
int	map(size_t	x, size_t y, t_map_info *Map);
void    dis(size_t x, size_t y, unsigned c, int f);
unsigned int	flooring(unsigned int set);
unsigned int	ceiling(unsigned int set);


int set_head(char *file);



int		set_key(int	key, void	*p);
int		rm_key(int	key, void	*p);

int		cub3d(void	*p);
void move();
void cast();
void cast_line(t_now *n, t_line *l);


int		end_cub(void	*p);

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
#define TESTp(i) printf("[(%s/%d) %s ]%s:%p\n", __FILE__, __LINE__, __func__, #i, (i)); fflush(stdin);
#define TESTs(i) printf("[(%s/%d) %s ]%s:%s\n", __FILE__, __LINE__, __func__, #i, (char *)(i)); fflush(stdin);
#define TESTc(i) printf("[(%s/%d) %s ]%s:%c\n", __FILE__, __LINE__, __func__, #i, (char)(i)); fflush(stdin);
#define TIME printf("[(%s/%d) %s ]%lf[s]\n", __FILE__, __LINE__, __func__, time_diff()); fflush(stdin);
#define STOP {char c; read(STDIN_FILENO, &c, sizeof(char));}

#endif

