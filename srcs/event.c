/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 05:41:01 by blyu              #+#    #+#             */
/*   Updated: 2022/12/25 05:41:02 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_key(int k, void *p)
{
	(void)p;
	if (k == W_KEY)
		key(GO_F);
	else if (k == S_KEY)
		key(GO_B);
	else if (k == A_KEY)
		key(GO_L);
	else if (k == D_KEY)
		key(GO_R);
	else if (k == TL_KEY)
		key(TRN_L);
	else if (k == TR_KEY)
		key(TRN_R);
	else if (k == ESC_KEY)
		end_cub(NULL);
	return (0);
}

int	rm_key(int k, void *p)
{
	(void)p;
	if (k == W_KEY || k == S_KEY || k == A_KEY || k == D_KEY)
		key(GO_NONE);
	else if (k == TL_KEY || k == TR_KEY)
		key(TRN_NONE);
	return (0);
}

int	end_cub(void *p)
{
	(void)p;
	dis(0, 0, 0, (int) FREE_ALL);
	map(0, 0, (void *)FREE_ALL);
	exit(0);
}
