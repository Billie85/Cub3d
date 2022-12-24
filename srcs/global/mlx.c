/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 05:39:26 by blyu              #+#    #+#             */
/*   Updated: 2022/12/25 05:39:29 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*mlx(void *set)
{
	static void	*mlx_ptr;

	if (set)
		mlx_ptr = set;
	return (mlx_ptr);
}

void	*win(void *set)
{
	static void	*win_ptr;

	if (set)
		win_ptr = set;
	return (win_ptr);
}
