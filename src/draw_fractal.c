/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:16:30 by maxim             #+#    #+#             */
/*   Updated: 2020/10/23 13:14:16 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include <stdio.h>
#include <pthread.h>

static void	calc_fractal_part(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = mlx->fractal.start_line;
	while (j < mlx->fractal.finish_line)
	{
		while (i < WIDTH)
		{
			if (calc_iter_mand(mlx->fractal, i, j) < MAX_ITERATIONS)
				put_pixel_to_image(*mlx, i, j, 0x00FFFFFF);
			else
				put_pixel_to_image(*mlx, i, j, 0);
			i++;
		}
		i = 0;
		j++;
	}
}

void	draw_fractal(t_mlx *mlx)
{
	int	i;
	pthread_t	threads[THREADS];
	t_mlx	fractal_parts[THREADS];

	i = 0;
	while (i < THREADS)
	{
		fractal_parts[i] = *mlx;
		fractal_parts[i].fractal.start_line = i * (HEIGHT / THREADS);
		fractal_parts[i].fractal.finish_line = (i + 1) * (HEIGHT / THREADS);
		pthread_create(&threads[i], NULL, (void*)&calc_fractal_part, &fractal_parts[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
	printf("max_re: %f\n", mlx->fractal.max_re);
	printf("min_re: %f\n", mlx->fractal.min_re);
	printf("max_im: %f\n", mlx->fractal.max_im);
	printf("min_im: %f\n", mlx->fractal.min_im);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->pimage, 0, 0);
	printf("image put\n");
}
