#include "cub3d.h"

char *read_file(int fd, size_t B);
int img_mame(char **dst , char *file);
int set_img(char **name, unsigned *imgs);
int set_cf(char **str);

int set_head(char *file)
{
	int fd;
	char *name[7];
	unsigned imgs[BL * BL * 4];

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	file = read_file(fd, 0);
	close(fd);
	if (!file)
		return (1);
	ft_bzero(name, sizeof(name));
	if (img_mame(name, file) || set_img(name, imgs) || set_cf(name))
	{
		free(file);
		return (1);
	}
	free(file);
	return (0);
}


char *read_file(int fd, size_t B)
{
	ssize_t l;
	char s[BUFER_SIZE];
	char *r;

	l = read(fd, s, BUFER_SIZE);
	if (l < 0)
		return (NULL);
	else if (l == 0)
	{
		r = malloc(B + 1);
		if (r)
			r[B] = '\0';
		return (r);
	}
	r = read_file(fd, B + l);
	if (r)
		ft_memcpy(r + B, s, l);
	return (r);	
}

int switch_name(char **dst, char *file, unsigned *f);

int img_mame(char **dst , char *file)
{	
	unsigned f;
	
	f = 0;
	while (*file)
	{
		while (*file && *file == ' ')
			file++;
		if (switch_name(dst, file, &f))
			break;
		while (*file && *file != '\n')
			file++;
		if (*file == '\n')
		{
			*file = '\0';
			file++;
		}
	}
	if (f != 0b111111)
		return (1);
	while (*dst)
	{
		while (**dst == ' ')
			(*dst)++;
		dst++;
	}
	return (0);
}

int switch_name1(char **dst, char *file, unsigned *f);
int switch_name2(char **dst, char *file, unsigned *f);

int switch_name(char **dst, char *file, unsigned *f)
{
	if (!ft_memcmp(file, "NO", 2))
	{
		if (*f & 1U << NORTH)
		{
			*f ^= 1U << NORTH;
			return (1);
		}
		*f |= 1U << NORTH;
		dst[NORTH] = file + 2;
	}
	else if (!ft_memcmp(file, "EA", 2))
	{
		if (*f & 1U << EAST)
		{
			*f ^= 1U << EAST;
			return (1);
		}
		*f |= 1U << EAST;
		dst[EAST] = file + 2;
	}
	else
		return (switch_name1(dst, file, f));
	return (0);
}


int switch_name1(char **dst, char *file, unsigned *f)
{
	if (!ft_memcmp(file, "SO", 2))
	{
		if (*f & 1U << SOUTH)
		{
			*f ^= 1U << SOUTH;
			return (1);
		}
		*f |= 1U << SOUTH;
		dst[SOUTH] = file + 2;
	}
	else if (!ft_memcmp(file, "WE", 2))
	{
		if (*f & 1U << WEST)
		{
			*f ^= 1U << WEST;
			return (1);
		}
		*f |= 1U << WEST;
		dst[WEST] = file + 2;
	}
	else
		return (switch_name2(dst, file, f));
	return (0);
}

int switch_name2(char **dst, char *file, unsigned *f)
{
	if (*file == 'C')
	{
		if (*f & 1U << 4)
		{
			*f ^= 1U << 4;
			return (1);
		}
		*f |= 1U << 4;
		dst[4] = file + 1;
		return (0);
	}
	else if (*file == 'F')
	{
		if (*f & 1U << 5)
		{
			*f ^= 1U << 5;
			return (1);
		}
		*f |= 1U << 5;
		dst[5] = file + 1;
		return (0);
	}
	else if (*file == '\n' || !(*file))
		return (0);
	return (1);
}

void set_img_bit(char *p, int bits_per_pixel, int size_line, unsigned *dst);
int set_img(char **name, unsigned *imgs)
{
	size_t	i;
	int	bp;
	int	sl;
	int buf;
	void *img_data;

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
		bp, sl,  imgs + (BL * BL * i));
		mlx_destroy_image(mlx(0), img_data);
		i++;
	}

	img(SET, 0, imgs);
	return (0);
}

void set_img_bit(char *p, int bits_per_pixel, int size_line, unsigned *dst)
{
	size_t x;
	size_t y;

	y = 0;
	while (y < BL)
	{
		x = 0;
		while(x < BL)
		{
			dst[x * BL + y] = *(unsigned *)(p + y * size_line + x * (bits_per_pixel / 8));
			x++;
		}
		y++;
	}
	return ;
}


void	set_cf1(size_t	i, unsigned n);

int set_cf(char **str)
{
	size_t i;
	size_t ii;
	size_t l;
	unsigned n;
	
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
		set_cf1(i, n);
		i++;
	}
	return (0);
}

void	set_cf1(size_t	i, unsigned n)
{
	if (i == 4)
		ceiling(n);
	else
		flooring(n);
}
