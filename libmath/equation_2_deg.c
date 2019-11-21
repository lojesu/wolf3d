/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_2_deg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:42:39 by reda-con          #+#    #+#             */
/*   Updated: 2019/11/21 14:38:00 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double		equation_2_deg(double a, double b, double c)
{
	double	delta;
	double	t1;
	double	t2;

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (0);
	t1 = (-b - sqrt(delta)) / (2 * a);
	t2 = (-b + sqrt(delta)) / (2 * a);
	return ((t1 < t2 && t1 > 0.1) ? t1 : t2);
}
