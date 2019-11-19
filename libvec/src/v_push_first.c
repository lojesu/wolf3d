/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_push_first.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:52:51 by glegendr          #+#    #+#             */
/*   Updated: 2019/11/19 16:15:09 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void		v_push_first(t_vec *vec, void *elem)
{
	int i;

	i = vec->private_elem_nb;
	if (vec->private_elem_cap <= vec->private_elem_nb)
	{
		if ((vec->private_content = v_realloc(vec->private_content,
						vec->private_elem_cap * vec->private_elem_size,
						2 * vec->private_elem_cap
						* vec->private_elem_size)) == NULL)
			return ;
		vec->private_elem_cap += NB_ELEM_INI;
	}
	while (i > 0)
	{
		v_memcpy(v_get(vec, i), v_get(vec, i - 1), vec->private_elem_size);
		--i;
	}
	v_memcpy(v_get(vec, i), elem, vec->private_elem_size);
	++vec->private_elem_nb;
}
