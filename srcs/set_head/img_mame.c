#include "../cub3d.h"

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
