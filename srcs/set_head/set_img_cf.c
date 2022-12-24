#include "../cub3d.h"

void	set_img_bit(char *p, int bits_per_pixel, \
int size_line, unsigned int *dst);
void	set_cf1(size_t	*i, unsigned int n);

int	set_img(char **name, unsigned int *imgs)
{
	size_t	i;
	int		bp;
	int		sl;
	int		buf;
	void	*img_data;

	i = 0;
	while (i < 4)
	{
		img_data = mlx_xpm_file_to_image(mlx(0), name[i], &bp, &sl);
		if (!img_data || bp < BL || sl < BL)
			return (1);
		bp = 0;
		sl = 0;
		buf = 0;
		set_img_bit(mlx_get_data_addr(img_data, &bp, &sl, &buf), \
		bp, sl, imgs + (BL * BL * i));
		mlx_destroy_image(mlx(0), img_data);
		i++;
	}
	img(SET, 0, imgs);
	return (0);
}

void	set_img_bit(char *p, int bits_per_pixel, \
int size_line, unsigned int *dst)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < BL)
	{
		x = 0;
		while (x < BL)
		{
			dst[x * BL + y] = \
			*(unsigned *)(p + y * size_line + x * (bits_per_pixel / 8));
			x++;
		}
		y++;
	}
	return ;
}

int	set_cf(char **str)
{
	size_t			i;
	size_t			ii;
	size_t			l;
	unsigned int	n;

	i = 4;
	while (i < 6)
	{
		ii = 0;
		n = 0;
		while (ii < 3)
		{
			l = 0;
			while (ft_isdigit(str[i][l]))
				l++;
			if (l == 0 || l > 3 || ft_atoi(str[i]) > 0xff || \
			(ii < 2 && str[i][l] != ',') || (ii == 2 && str[i][l] != '\0'))
				return (1);
			n |= ft_atoi(str[i]) << (2 - ii) * 8;
			str[i] += l + 1;
			ii++;
		}
		set_cf1(&i, n);
	}
	return (0);
}

void	set_cf1(size_t	*i, unsigned int n)
{
	if (*i == 4)
		ceiling(n);
	else
		flooring(n);
	(*i)++;
}
