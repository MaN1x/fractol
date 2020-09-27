/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_to_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:52:51 by maxim             #+#    #+#             */
/*   Updated: 2020/09/27 21:48:53 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_image(t_mlx mlx, int x, int y, unsigned int color)
{
	if (x < mlx.width && x > 0 || y < mlx.height && y > 0)
		*((unsigned int*)(mlx.image + x * sizeof(int) + y * mlx.size_line)) = color;
}
