/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:49:10 by maxim             #+#    #+#             */
/*   Updated: 2020/10/23 13:10:20 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

void	mlx_start(t_mlx *mlx)
{
	mlx->width = WIDTH;
	mlx->height = HEIGHT;

	mlx->fractal.max_re = MAX_RE;
	mlx->fractal.min_re = MIN_RE;
	mlx->fractal.max_im = MAX_IM;
	mlx->fractal.min_im = MIN_IM;

	mlx->fractal.factor_x = (mlx->fractal.max_re - mlx->fractal.min_re) / mlx->width;
	mlx->fractal.factor_y = (mlx->fractal.max_im - mlx->fractal.min_im) / mlx->height;

	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "Fractol");
	mlx->pimage = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	mlx->image = mlx_get_data_addr(mlx->pimage, &mlx->bpp, &mlx->size_line, &mlx->endian);
}
