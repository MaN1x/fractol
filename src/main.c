/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:51:47 by maxim             #+#    #+#             */
/*   Updated: 2020/10/19 21:52:03 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "libft.h"
#include <stdio.h>

int main(void)
{
	t_mlx	mlx;

	mlx_start(&mlx);

	draw_fractal(&mlx);

	mlx_mouse_hook(mlx.window, mouse_hook, &mlx);
	mlx_loop(mlx.mlx);

	return (0);
}
