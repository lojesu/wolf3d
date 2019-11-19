/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:13:27 by glegendr          #+#    #+#             */
/*   Updated: 2019/06/08 13:44:55 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		v_putchar(char c)
{
	write(1, &c, 1);
}

void		v_putnbr(int n)
{
	unsigned int nb;

	nb = n;
	if (nb > 2147483648 || n < 0)
	{
		v_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		v_putnbr(nb / 10);
		v_putnbr(nb % 10);
	}
	else
		v_putchar(nb + '0');
}
