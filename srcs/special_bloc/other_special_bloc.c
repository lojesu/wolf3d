/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_special_bloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:10:56 by glegendr          #+#    #+#             */
/*   Updated: 2019/11/28 18:10:58 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <special_bloc.h>
#include <libft.h>

#include <stdio.h>

#define BRAVO_SIZE (1000 * 750)

void	del_me(char **map, char c)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			map[y][x] = map[y][x] == c ? '0' : map[y][x];
			++x;
		}
		++y;
	}
}

bool	special_wall_press(t_env *env)
{
	char	**map;
	t_win	*win;

	win = &env->win;
	map = env->map;
	launch_cinematique(env);
	put_image(win);
	return (true);
}

bool	special_reset(t_env *env)
{
	t_win	*win;

	win = &env->win;
	event_reset(env);
	put_image(win);
	return (true);
}

bool	special_end_press(t_env *env)
{
	t_cam	*cam;
	char	**map;
	t_win	*win;

	win = &env->win;
	cam = &env->cam;
	map = env->map;
	cam->button = true;
	del_me(map, '7');
	put_image(win);
	return (true);
}

bool	special_end(t_env *env)
{
	int		bmp[BRAVO_SIZE];
	char	buff[BRAVO_SIZE * 3];
	int		i;

	i = 0;
	if ((&env->cam)->button == true)
	{
		read_bmp(bmp, "./textures/bravo.bmp", buff, BRAVO_SIZE * 3);
		while (i < BRAVO_SIZE)
		{
			if (bmp[i] != 0x0)
			{
				put_pixel(&env->win, (WIDTH - 1000) / 2 + i % 1000,
							1000 - i / 1000 - (HEIGHT - 750) / 2, bmp[i]);
			}
			++i;
		}
	}
	else
		return (true);
	put_image(&env->win);
	(&env->cam)->lock = 2;
	return (true);
}
