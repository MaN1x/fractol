/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:16:30 by maxim             #+#    #+#             */
/*   Updated: 2020/10/19 21:19:24 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include <stdio.h>

void	draw_fractal(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < mlx->height)
	{
		while (i < mlx->width)
		{
			if (calc_iter_mand(*mlx, i, j) < MAX_ITERATIONS)
				put_pixel_to_image(*mlx, i, j, 0x00FFFFFF);
			else
				put_pixel_to_image(*mlx, i, j, 0);
			i++;
		}
		i = 0;
		j++;
	}
	printf("max_re: %f\n", mlx->max_re);
	printf("min_re: %f\n", mlx->min_re);
	printf("max_im: %f\n", mlx->max_im);
	printf("min_im: %f\n", mlx->min_im);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->pimage, 0, 0);
}
