/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:51:35 by maxim             #+#    #+#             */
/*   Updated: 2020/10/19 21:18:13 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MAX_ITERATIONS 100
# define MAX_RE 2.0
# define MIN_RE -2.0
# define MAX_IM 2.0
# define MIN_IM -2.0
# define WIDTH 1000
# define HEIGHT 1000

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
	double		factor_x;
	double		factor_y;
	double		max_re;
	double		min_re;
	double		max_im;
	double		min_im;
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
int				calc_iter_mand(t_mlx mlx, int x, int y);
int				mouse_hook(int button, int x, int y, t_mlx *mlx);
void			draw_fractal(t_mlx *mlx);

#endif
