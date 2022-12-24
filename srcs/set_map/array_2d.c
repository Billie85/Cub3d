/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 05:40:11 by blyu              #+#    #+#             */
/*   Updated: 2022/12/25 05:40:12 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_map.h"

void	array_2d(t_map_info *map)
{
	char	**buff;
	size_t	len;
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	map->line = get_next_line(map->fd);
	while (map->line != NULL)
	{
		buff = map->array_2d;
		map->array_2d = (char **)malloc(sizeof(char *) * (map->height + 2));
		ft_memcpy(map->array_2d, buff, sizeof(char **) * map->height);
		free(buff);
		map->array_2d[map->height] = map->line;
		map->height++;
		map->max_height++;
		len = ft_strlen(map->line);
		if (len > map->max_width)
			map->max_width = len;
		map->line = get_next_line(map->fd);
	}
	map->array_2d[map->height] = NULL;
}
