/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:10:17 by glegendr          #+#    #+#             */
/*   Updated: 2019/11/28 18:10:19 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <libft.h>
#include <math.h>
#include <libmath.h>
#include <map.h>

#define CELL_SIZE 32
#define FOV_SIZE (CELL_SIZE / 3.5)

#define BMAP_POS 40
#define BMAP_WIDTH ((WIDTH - BMAP_POS)/(CELL_SIZE+1) - BMAP_POS/(CELL_SIZE+1))
#define BMAP_WPOS1 (int)((BMAP_WIDTH - ft_strlen(map[0]))/2)
#define BMAP_WPOS (BMAP_WPOS1 > 0 ? BMAP_WPOS1 : 0)
#define BMAP_HEIGHT ((HEIGHT - BMAP_POS)/(CELL_SIZE+1) - BMAP_POS/(CELL_SIZE+1))
#define BMAP_HPOS1 (int)((BMAP_HEIGHT - ft_strlen_len(map))/2)
#define BMAP_HPOS (BMAP_HPOS1 > 0 ? BMAP_HPOS1 : 0)

static double	bmap_player(double a, char **map, t_cam *cam, bool height)
{
	if (height)
	{
		return ((double)((double)a) * CELL_SIZE / FRAME +
			BMAP_HPOS * CELL_SIZE + BMAP_POS - cam->bmapy * CELL_SIZE);
	}
	return ((double)((double)a) * CELL_SIZE / FRAME +
		BMAP_WPOS * CELL_SIZE + BMAP_POS - cam->bmapx * CELL_SIZE);
}

void			put_fov(t_win *win, t_cam *cam, int x, int y)
{
	size_t	i;
	int		angle;
	double	p0[2];
	double	p1[2];

	i = 0;
	while (i < 100)
	{
		p0[0] = cos(deg_to_rad(cam->orientation)) * FOV_SIZE + x;
		p0[1] = -sin(deg_to_rad(cam->orientation)) * FOV_SIZE + y;
		angle = cam->orientation + i - 50;
		angle = angle > 360 ? angle - 360 : angle;
		angle = angle < 0 ? angle + 360 : angle;
		p1[0] = -cos(deg_to_rad(angle)) * FOV_SIZE + x;
		p1[1] = sin(deg_to_rad(angle)) * FOV_SIZE + y;
		bresenham(win, p0, p1);
		++i;
	}
}

static void		put_cell(t_win *win, int x, int y, int color)
{
	int xi;
	int yi;

	yi = y;
	while (yi < y + CELL_SIZE)
	{
		xi = x;
		while (xi < x + CELL_SIZE)
		{
			put_pixel(win, xi, yi, color);
			++xi;
		}
		++yi;
	}
	xi = x;
	yi = y;
}

static bool		is_out(t_cam *cam, char **map)
{
	return (cam->x - cam->bmapx * FRAME < 0 ||
			cam->x - cam->bmapx * FRAME > (int)ft_strlen(map[0]) * FRAME ||
			cam->y - cam->bmapy * FRAME < 0 ||
			cam->y - cam->bmapy * FRAME > (int)ft_strlen_len(map) * FRAME);
}

void			big_map(t_win *win, t_cam *cam, char **map)
{
	int x;
	int y;

	y = 0;
	while (y < BMAP_HEIGHT - BMAP_HPOS * 2)
	{
		x = 0;
		while (x < BMAP_WIDTH - BMAP_WPOS * 2)
		{
			put_cell(win,
				x * (CELL_SIZE + 1) + BMAP_WPOS * CELL_SIZE + BMAP_POS,
				y * (CELL_SIZE + 1) + BMAP_HPOS * CELL_SIZE + BMAP_POS,
				give_color(map, (x + cam->bmapx) * FRAME,
						(y + cam->bmapy) * FRAME, cam));
			++x;
		}
		++y;
	}
	if (!is_out(cam, map))
		put_fov(win, cam, bmap_player(cam->x, map, cam, false),
				bmap_player(cam->y, map, cam, true));
}
