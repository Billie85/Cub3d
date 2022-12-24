/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_head.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 05:39:53 by blyu              #+#    #+#             */
/*   Updated: 2022/12/25 05:39:54 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*read_file(int fd, size_t B);
int		img_mame(char **dst, char *file);
int		set_img(char **name, unsigned int *imgs);
int		set_cf(char **str);

int	set_head(char *file)
{
	int				fd;
	char			*name[7];
	unsigned int	imgs[BL * BL * 4];

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

char	*read_file(int fd, size_t B)
{
	ssize_t	l;
	char	s[BUFER_SIZE];
	char	*r;

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
