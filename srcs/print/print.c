/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:10:42 by glegendr          #+#    #+#             */
/*   Updated: 2019/11/29 14:12:27 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <libft.h>
#include <math.h>
#include <libmath.h>

void	wich_bmp
	(t_wall wall, int my_bmp[BMP_SIZE], t_env *env)
{
	int x;
	int y;

	x = wall.side == SIDE_RIGHT ? 32 : 0;
	y = wall.side == SIDE_DOWN ? 32 : 0;
	if (env->map[((int)wall.y - y) / FRAME][((int)wall.x - x) / FRAME] == '2')
	{
		my_intcpy(my_bmp, env->bmp[4], BMP_SIZE);
		return ;
	}
	if (wall.side == SIDE_RIGHT)
		my_intcpy(my_bmp, env->bmp[0], BMP_SIZE);
	else if (wall.side == SIDE_LEFT)
		my_intcpy(my_bmp, env->bmp[1], BMP_SIZE);
	else if (wall.side == SIDE_UP)
		my_intcpy(my_bmp, env->bmp[2], BMP_SIZE);
	else
		my_intcpy(my_bmp, env->bmp[3], BMP_SIZE);
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
	int		my_bmp[BMP_SIZE];

	z = 1;
	i = start > 0 ? start : 0;
	wich_bmp(wall, my_bmp, env);
	pos = wall.side == SIDE_UP || wall.side == SIDE_DOWN ?
		fmod(wall.x, 64) : fmod(wall.y, 64);
	ratio = (double)BMP_SIDE / (double)(DIST_SCREEN * FRAME / wall.dist);
	if (start < 0)
		z = ratio * -start + 1;
	while (i < start + (DIST_SCREEN * FRAME / wall.dist) && i < HEIGHT)
	{
		put_pixel(&env->win, column, i,
				my_bmp[pos + BMP_SIZE - (int)z * BMP_SIDE]);
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
