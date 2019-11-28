/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:28:18 by glegendr          #+#    #+#             */
/*   Updated: 2019/11/28 18:55:23 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <unistd.h>

void		v_print(t_vec *vec)
{
	int i;

	i = 0;
	v_putchar('{');
	if (v_get_size(vec) == sizeof(char))
		write(1, v_get(vec, 0), vec->private_elem_nb);
	else if (v_get_size(vec) == sizeof(int))
		while (i < v_size(vec))
		{
			v_putnbr(*(int *)v_get(vec, i));
			++i;
			if (i < v_size(vec))
				v_putchar(' ');
		}
	else if (v_get_size(vec) == sizeof(t_vec))
		while (i < v_size(vec))
		{
			v_print(v_get(vec, i));
			++i;
		}
	v_putchar('}');
}
