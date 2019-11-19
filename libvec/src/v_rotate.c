/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 00:04:44 by glegendr          #+#    #+#             */
/*   Updated: 2019/09/25 21:25:14 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.h"

void		v_rotate(t_vec *vec)
{
	void *tmp;
	void *tmp2;

	tmp2 = v_raw(vec) + vec->private_elem_size;
	tmp = malloc(vec->private_elem_size);
	v_memcpy(tmp, v_get(vec, 0), vec->private_elem_size);
	v_memcpy(v_raw(vec), tmp2, (vec->private_elem_nb - 1)
			* vec->private_elem_size);
	v_memcpy(v_get(vec, v_size(vec) - 1), tmp, vec->private_elem_size);
	free(tmp);
}
