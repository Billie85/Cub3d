/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:28:37 by root              #+#    #+#             */
/*   Updated: 2022/11/09 23:54:17 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_newline_in_save(char *save)
{
	size_t	i;
	char	*save_new_line;

	i = 0;
	if (save[i] == '\0')
		return (NULL);
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	save_new_line = (char *)malloc(sizeof(char) * (i + 2));
	if (save_new_line == NULL)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
	{
		save_new_line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		save_new_line[i] = save[i];
		i++;
	}
	save_new_line[i] = '\0';
	return (save_new_line);
}

char	*after_new_line(char *save)
{
	size_t	i_save;
	size_t	i_line;
	char	*after_line;

	i_save = 0;
	i_line = 0;
	while (save[i_save] != '\n' && save[i_save] != '\0')
		i_save++;
	if (save[i_save] == '\0')
	{
		free (save);
		return (NULL);
	}
	after_line = (char *)malloc(sizeof(char) * (gnl_strlen(save) - i_save + 1));
	if (after_line == NULL)
		return (NULL);
	i_save++;
	while (save[i_save] != '\0')
	{
		after_line[i_line++] = save[i_save++];
	}
	after_line[i_line] = '\0';
	free(save);
	return (after_line);
}

char	*join_together(char	*save, char *buf)
{
	char	*after_join;

	after_join = save_buf_join(save, buf);
	return (after_join);
}

char	*read_assign(int fd, char *save)
{
	char	*buf;
	ssize_t	read_put;

	buf = (char *)malloc(sizeof(char) *(BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	read_put = 100;
	while (!gnl_strchr(save, '\n') && read_put != 0)
	{
		read_put = read(fd, buf, BUFFER_SIZE);
		if (read_put == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_put] = '\0';
		save = join_together(save, buf);
	}	
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 256 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	save = read_assign(fd, save);
	if (save == NULL)
		return (NULL);
	line = find_newline_in_save(save);
	save = after_new_line(save);
	return (line);
}
