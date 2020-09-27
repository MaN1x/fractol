/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_pixel_in_fract_mand.c                         :+:      :+:    :+:   */
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

void calc_pixel_in_fract_mand(t_mlx mlx, int x, int y)
{
	t_comp_nbr	point;
	t_comp_nbr	z;
	unsigned int			i;
	double		factor_x;
	double		factor_y;

	i = 0;
	factor_x = (MAX_RE - MIN_RE) / mlx.width;
	factor_y = (MAX_IM - MIN_IM) / mlx.height;
	point = init_comp_nbr(MIN_RE + factor_x * x, MAX_IM - factor_y * y);
	z = init_comp_nbr(0, 0);


	while (i++ < MAX_ITERATIONS)
	{
		z = comp_nbr_sum(comp_nbr_pow(z), point);
		if (pow(z.real, 2.0) + pow(z.imaginary, 2.0) > 4.0)
		{
			put_pixel_to_image(mlx, x, y, (int)(((double)i / MAX_ITERATIONS) * 0x00FFFFFF));
			if ((int)((double)y / (mlx.height - 1) * 100.0) && (x == mlx.width - 1))
				printf("%d\n", (int)((double)y / (mlx.height - 1) * 100));
			return;
		}
	}
	put_pixel_to_image(mlx, x, y, 0x00000000);
}
