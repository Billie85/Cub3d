/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 05:39:07 by blyu              #+#    #+#             */
/*   Updated: 2022/12/25 05:39:08 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	img(int flag, size_t len, unsigned int *io)
{
	static unsigned int	img_data[BL * BL * 4];

	if (flag == SET)
		ft_memcpy(img_data, io, BL * BL * 4 * sizeof(unsigned));
	else if (flag < 4 && flag >= 0)
		ft_memcpy(io, img_data + (BL * BL * flag) + \
		(BL * len), BL * sizeof(unsigned int));
	return ;
}
