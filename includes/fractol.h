/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:51:35 by maxim             #+#    #+#             */
/*   Updated: 2020/09/27 23:54:52 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MAX_ITERATIONS 1000
# define MAX_RE 2.0
# define MIN_RE -2.0
# define MAX_IM 2.0
# define MIN_IM -2.0

typedef struct	s_mlx
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	void	*pimage;
	char	*image;
	int		bpp;
	int		size_line;
	int		endian;
}				t_mlx;

typedef struct	s_comp_nbr
{
	double	real;
	double	imaginary;
}				t_comp_nbr;

void			put_pixel_to_image(t_mlx mlx, int x, int y, unsigned int color);
t_comp_nbr		init_comp_nbr(double real, double imaginary);
t_comp_nbr		comp_nbr_sum(t_comp_nbr nbr1, t_comp_nbr nbr2);
t_comp_nbr		comp_nbr_pow(t_comp_nbr nbr);
void			calc_pixel_in_fract_mand(t_mlx mlx, int x, int y);

#endif
