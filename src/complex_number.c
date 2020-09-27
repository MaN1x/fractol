/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxim <maxim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:22:51 by maxim             #+#    #+#             */
/*   Updated: 2020/09/27 21:23:37 by maxim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

t_comp_nbr	init_comp_nbr(double real, double imaginary)
{
	t_comp_nbr	nbr;

	nbr.real = real;
	nbr.imaginary = imaginary;
	return (nbr);
}

t_comp_nbr	comp_nbr_sum(t_comp_nbr nbr1, t_comp_nbr nbr2)
{
	t_comp_nbr	result;

	result.real = nbr1.real + nbr2.real;
	result.imaginary = nbr1.imaginary + nbr2.imaginary;
	return (result);
}

t_comp_nbr	comp_nbr_pow(t_comp_nbr nbr)
{
	t_comp_nbr	result;

	result.real = pow(nbr.real, 2.0) - pow(nbr.imaginary, 2.0);
	result.imaginary = 2 * nbr.real * nbr.imaginary;
	return (result);
}
