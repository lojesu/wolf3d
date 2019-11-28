/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:10:46 by glegendr          #+#    #+#             */
/*   Updated: 2019/11/28 18:24:56 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	hex_to_rgb(int *r, int *g, int *b, int color)
{
	*r = (color >> 16 & 0xFF);
	*g = (color >> 8 & 0xFF);
	*b = (color & 0xFF);
}

void		put_pixel(t_win *win, size_t x, size_t y, int color)
{
	size_t	pix_colors;
	int		r;
	int		g;
	int		b;

	pix_colors = 4 * x + 4 * WIDTH * y;
	hex_to_rgb(&r, &g, &b, color);
	IMG_STR[pix_colors] = b;
	IMG_STR[pix_colors + 1] = g;
	IMG_STR[pix_colors + 2] = r;
}
