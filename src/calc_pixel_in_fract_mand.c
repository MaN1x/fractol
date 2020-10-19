/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_iter_mand.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 20:10:41 by maxim             #+#    #+#             */
/*   Updated: 2020/09/28 00:10:39 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <stdio.h>

int calc_iter_mand(t_mlx mlx, int x, int y)
{
	t_comp_nbr	point;
	t_comp_nbr	z;
	int			i;

	i = 0;
	point = init_comp_nbr(mlx.min_re + mlx.factor_x * x, mlx.min_im + mlx.factor_y * y);
	z = init_comp_nbr(0, 0);

	while (i < MAX_ITERATIONS)
	{
		z = comp_nbr_sum(comp_nbr_pow(z), point);
		if (pow(z.real, 2.0) + pow(z.imaginary, 2.0) > 4.0)
			break;
		i++;
	}
	return (i);
}
