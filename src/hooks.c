/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:44:56 by maxim             #+#    #+#             */
/*   Updated: 2020/10/23 13:15:38 by maxim            ###   ########.fr       */
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
	printf("mouse_re: %f\n", x * mlx->fractal.factor_x + mlx->fractal.min_re);
	printf("mouse_im: %f\n", y * mlx->fractal.factor_y + mlx->fractal.min_im);
	if (button == 1)
	{
		mlx->fractal.max_re = interpolate(x * mlx->fractal.factor_x + mlx->fractal.min_re, mlx->fractal.max_re, 0.6);
		mlx->fractal.min_re = interpolate(x * mlx->fractal.factor_x + mlx->fractal.min_re, mlx->fractal.min_re, 0.6);
		mlx->fractal.max_im = interpolate(y * mlx->fractal.factor_y + mlx->fractal.min_im, mlx->fractal.max_im, 0.6);
		mlx->fractal.min_im = interpolate(y * mlx->fractal.factor_y + mlx->fractal.min_im, mlx->fractal.min_im, 0.6);

		mlx->fractal.factor_x = (mlx->fractal.max_re - mlx->fractal.min_re) / mlx->width;
		mlx->fractal.factor_y = (mlx->fractal.max_im - mlx->fractal.min_im) / mlx->height;
		draw_fractal(mlx);
	}
	return (0);
}
