/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:44:56 by maxim             #+#    #+#             */
/*   Updated: 2020/10/19 21:44:56 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "stdio.h"

static double      interpolate(double start, double end, double interp)
{
	return (start + ((end - start) * interp));
}

int	mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	printf("Button: %d\n", button);
	printf("mouse_re: %f\n", x * mlx->factor_x + mlx->min_re);
	printf("mouse_im: %f\n", y * mlx->factor_y + mlx->min_im);
	if (button == 1)
	{
		mlx->max_re = interpolate(x * mlx->factor_x + mlx->min_re, mlx->max_re, 0.6);
		mlx->min_re = interpolate(x * mlx->factor_x + mlx->min_re, mlx->min_re, 0.6);
		mlx->max_im = interpolate(y * mlx->factor_y + mlx->min_im, mlx->max_im, 0.6);
		mlx->min_im = interpolate(y * mlx->factor_y + mlx->min_im, mlx->min_im, 0.6);

		mlx->factor_x = (mlx->max_re - mlx->min_re) / mlx->width;
		mlx->factor_y = (mlx->max_im - mlx->min_im) / mlx->height;
		draw_fractal(mlx);
	}
	return (0);
}
