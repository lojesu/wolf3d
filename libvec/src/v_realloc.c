/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 21:37:20 by glegendr          #+#    #+#             */
/*   Updated: 2019/11/19 16:21:57 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void		*v_realloc(void *mem, int mem_size, int new_size)
{
	void *tmp;

	if ((tmp = malloc(new_size)) == NULL)
		return (NULL);
	if (mem == NULL)
		return (tmp);
	v_memcpy(tmp, mem, mem_size);
	free(mem);
	return (tmp);
}
