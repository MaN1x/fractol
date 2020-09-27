/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:51:47 by maxim             #+#    #+#             */
/*   Updated: 2020/09/28 00:00:21 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "libft.h"

#include <stdio.h>

int main(void)
{
	t_mlx	mlx;

	mlx.width = 1000;
	mlx.height = 1000;

	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "Fractol");
	mlx.pimage = mlx_new_image(mlx.mlx, mlx.width, mlx.height);
	mlx.image = mlx_get_data_addr(mlx.pimage, &mlx.bpp, &mlx.size_line, &mlx.endian);

	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < mlx.height)
	{
		while (i < mlx.width)
		{
			calc_pixel_in_fract_mand(mlx, i, j);
			i++;
		}
		i = 0;
		j++;
	}

	mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.pimage, 0, 0);



	mlx_loop(mlx.mlx);


	return (0);
}
