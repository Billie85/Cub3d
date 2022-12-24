/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:28:47 by root              #+#    #+#             */
/*   Updated: 2022/11/09 23:54:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while ((s[i] != '\0') && (s[i] != (unsigned char)c))
		i++;
	if (s[i] == (unsigned char)c)
	{
		return ((char *)s + i);
	}
	return (NULL);
}

char	*new_string(char *s1, char *s2)
{
	char	*new_s;
	size_t	i_s1;
	size_t	i_s2;
	size_t	i_new;

	new_s = (char *)malloc(sizeof(char) * \
	(gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (new_s == NULL)
		return (NULL);
	i_s1 = 0;
	i_s2 = 0;
	i_new = 0;
	while (s1[i_s1] != '\0')
		new_s[i_new++] = s1[i_s1++];
	while (s2[i_s2] != '\0')
		new_s[i_new++] = s2[i_s2++];
	new_s[gnl_strlen(s1) + gnl_strlen(s2)] = '\0';
	return (new_s);
}

char	*save_buf_join(char *s1, char *s2)
{
	char	*ss;
	char	*new;

	if (s1 == 0)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	ss = s1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new = new_string(s1, s2);
	free(ss);
	return (new);
}
