/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:37:29 by lojesu            #+#    #+#             */
/*   Updated: 2019/09/27 16:40:10 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnumber(char *num)
{
	size_t	i;

	if (!num)
		return (0);
	i = 0;
	if (num[i] == '-')
		i++;
	while (ft_isdigit(num[i]))
		i++;
	if (i != ft_strlen(num))
		return (0);
	return (1);
}
