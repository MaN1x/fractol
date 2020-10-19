/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:51:47 by maxim             #+#    #+#             */
/*   Updated: 2020/10/19 21:43:48 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "libft.h"
#include <stdio.h>

int main(void)
{
	t_mlx	mlx;

	mlx.width = WIDTH;
	mlx.height = HEIGHT;

	mlx.max_re = MAX_RE;
	mlx.min_re = MIN_RE;
	mlx.max_im = MAX_IM;
	mlx.min_im = MIN_IM;

	mlx.factor_x = (mlx.max_re - mlx.min_re) / mlx.width;
	mlx.factor_y = (mlx.max_im - mlx.min_im) / mlx.height;

	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "Fractol");
	mlx.pimage = mlx_new_image(mlx.mlx, mlx.width, mlx.height);
	mlx.image = mlx_get_data_addr(mlx.pimage, &mlx.bpp, &mlx.size_line, &mlx.endian);

	draw_fractal(&mlx);


	mlx_mouse_hook(mlx.window, mouse_hook, &mlx);
	mlx_loop(mlx.mlx);


	return (0);
}
