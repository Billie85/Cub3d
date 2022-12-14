/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 05:40:51 by blyu              #+#    #+#             */
/*   Updated: 2022/12/25 05:40:52 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_MAP_H
# define SET_MAP_H
# include "../cub3d.h"
# include "../../libft/libft.h"
# include "../../get_next_line/get_next_line.h"
# include <stdbool.h>
# include <math.h>
# include <stdio.h>
# include <string.h>

typedef struct s_map_info
{
	char	*new_malloc;
	char	**array_2d;
	char	**direction_part;
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
	char	*file_name;
}t_map_info;

int		map(size_t	x, size_t y, t_map_info *ch);
void	array_2d(t_map_info *map);
void	make_square(t_map_info *map);
void	remove_new_line(t_map_info *map);
char	**check_direction_map(t_map_info *map);
bool	check_map_top(t_map_info *map);
bool	check_map_under(t_map_info *map);
bool	check_map_left(t_map_info *map);
bool	check_map_right(t_map_info *map);
bool	check_error_inside_map(t_map_info *map);
bool	map_inside_left(t_map_info *map);
bool	map_inside_right(t_map_info *map);
bool	map_inside_down(t_map_info *map);
bool	map_inside_up(t_map_info *map);
bool	check_error_around_map(t_map_info *map);
int		set_map(char *file_name);
#endif
