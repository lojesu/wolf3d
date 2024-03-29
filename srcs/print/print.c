/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:10:42 by glegendr          #+#    #+#             */
/*   Updated: 2019/11/29 16:28:55 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <libft.h>
#include <math.h>
#include <libmath.h>

int		wich_bmp(t_wall wall, t_env *env)
{
	int x;
	int y;

	x = wall.side == SIDE_RIGHT ? 32 : 0;
	y = wall.side == SIDE_DOWN ? 32 : 0;
	if (env->map[((int)wall.y - y) / FRAME][((int)wall.x - x) / FRAME] == '2')
		return (4);
	if (wall.side == SIDE_RIGHT)
		return (0);
	else if (wall.side == SIDE_LEFT)
		return (1);
	else if (wall.side == SIDE_UP)
		return (2);
	else
		return (3);
}

void	draw_sky(int start, size_t column, t_win *win)
{
	int		i;

	i = 0;
	while (i < start && i < HEIGHT)
	{
		put_pixel(win, column, i, 0x0068d1);
		++i;
	}
}

void	draw_floor(int start, size_t column, int size_wall, t_win *win)
{
	uint32_t	i;

	i = start + size_wall;
	while (i < HEIGHT)
	{
		put_pixel(win, column, i, 0x797171);
		++i;
	}
}

void	draw_texture(t_wall wall, t_env *env, size_t column, int start)
{
	int		pos;
	int		i;
	double	z;
	double	ratio;
	int		id;

	z = 1;
	i = start > 0 ? start : 0;
	id = wich_bmp(wall, env);
	pos = wall.side == SIDE_UP || wall.side == SIDE_DOWN ?
		fmod(wall.x, 64) : fmod(wall.y, 64);
	ratio = (double)BMP_SIDE / (double)(DIST_SCREEN * FRAME / wall.dist);
	if (start < 0)
		z = ratio * -start + 1;
	while (i < start + (DIST_SCREEN * FRAME / wall.dist) && i < HEIGHT)
	{
		put_pixel(&env->win, column, i,
				env->bmp[id][pos + BMP_SIZE - (int)z * BMP_SIDE]);
		++i;
		z += ratio;
	}
}

void	print(t_env *env, t_wall wall, size_t column)
{
	int		size_wall;
	int		start;

	size_wall = DIST_SCREEN * FRAME / wall.dist;
	start = HEIGHT / 2 - size_wall / 2 + (&env->cam)->angle;
	draw_sky(start, column, &env->win);
	draw_texture(wall, env, column, start);
	draw_floor(start, column, size_wall, &env->win);
}
