/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cf.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 05:38:58 by blyu              #+#    #+#             */
/*   Updated: 2022/12/25 05:38:59 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned int	flooring(unsigned int set)
{
	static unsigned int	c;

	if (set)
		c = set;
	return (c);
}

unsigned int	ceiling(unsigned int set)
{
	static unsigned int	c;

	if (set)
		c = set;
	return (c);
}
