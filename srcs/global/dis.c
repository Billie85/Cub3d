/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 05:39:03 by blyu              #+#    #+#             */
/*   Updated: 2022/12/25 05:39:04 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dis(size_t x, size_t y, unsigned int c, int f)
{
	static void	*img_p;
	static char	*p;
	static int	size_line;
	static int	bits_per_pixel;

	if (f == CLOR)
		*(unsigned *)(p + y * size_line + x * (bits_per_pixel / 8)) = c;
	else if (f == SET)
	{
		img_p = mlx_new_image(mlx(0), DIS_W, DIS_H);
		p = mlx_get_data_addr(img_p, &bits_per_pixel, &size_line, &f);
	}
	else if (f == FLUSH)
		mlx_put_image_to_window(mlx(0), win(0), img_p, x, y);
	else if (f == (int) FREE_ALL)
		mlx_destroy_image(mlx(0), img_p);
	return ;
}
