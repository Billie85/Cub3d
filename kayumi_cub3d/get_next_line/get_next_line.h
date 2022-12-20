/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:33:42 by root              #+#    #+#             */
/*   Updated: 2022/11/09 23:53:36 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stddef.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <string.h>
# include <stdint.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

char	*gnl_strchr(char *s, int c);
size_t	gnl_strlen(char *s);
char	*save_buf_join(char *s1, char *s2);
char	*join_together(char	*save, char *buf);
char	*read_assign(int fd, char *save);
char	*find_newline_in_save(char *save);
char	*after_new_line(char *save);
char	*get_next_line(int fd);
#endif
