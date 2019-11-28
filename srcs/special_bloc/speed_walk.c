/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed_walk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:11:12 by glegendr          #+#    #+#             */
/*   Updated: 2019/11/28 18:51:19 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <special_bloc.h>

#define SPD 3

bool	speed_walk_right(t_env *env)
{
	t_cam	*cam;
	char	**map;
	t_win	*win;

	win = &env->win;
	cam = &env->cam;
	map = env->map;
	cam->x += map[cam->y / 64][(cam->x + SPD * 2) / 64] == '1'
			|| map[cam->y / 64][(cam->x + SPD * 2) / 64] == '2'
			? 0 : SPD;
	cam->x += cam->x % 64 < SPD * 2
			&& map[cam->y / 64][(cam->x + SPD * 2) / 64] != '1'
			&& map[cam->y / 64][(cam->x + SPD * 2) / 64] != '2'
			? SPD * 2 : 0;
	cam->lock = 1;
	put_image(win);
	return (true);
}

bool	speed_walk_left(t_env *env)
{
	t_cam	*cam;
	char	**map;
	t_win	*win;

	win = &env->win;
	cam = &env->cam;
	map = env->map;
	cam->x -= map[cam->y / 64][(cam->x - SPD * 2) / 64] == '1'
			|| map[cam->y / 64][(cam->x - SPD * 2) / 64] == '2'
			? 0 : SPD;
	cam->x -= cam->x % 64 < SPD * 2
			&& map[cam->y / 64][(cam->x - SPD * 2) / 64] != '1'
			&& map[cam->y / 64][(cam->x - SPD * 2) / 64] != '2'
			? SPD * 2 : 0;
	cam->lock = 1;
	put_image(win);
	return (true);
}

bool	speed_walk_down(t_env *env)
{
	t_cam	*cam;
	char	**map;
	t_win	*win;

	win = &env->win;
	cam = &env->cam;
	map = env->map;
	cam->y += map[(cam->y + SPD * 2) / 64][cam->x / 64] == '1'
			|| map[(cam->y + SPD * 2) / 64][cam->x / 64] == '2'
			? 0 : SPD;
	cam->y += cam->y % 64 < SPD * 2
			&& map[(cam->y + SPD * 2) / 64][cam->x / 64] != '1'
			&& map[(cam->y + SPD * 2) / 64][cam->x / 64] != '2'
			? SPD * 2 : 0;
	cam->lock = 1;
	put_image(win);
	return (true);
}

bool	speed_walk_up(t_env *env)
{
	t_cam	*cam;
	char	**map;
	t_win	*win;

	win = &env->win;
	cam = &env->cam;
	map = env->map;
	cam->y -= map[(cam->y - SPD * 2) / 64][cam->x / 64] == '1'
			|| map[(cam->y - SPD * 2) / 64][cam->x / 64] == '2'
			? 0 : SPD;
	cam->y -= cam->y % 64 < SPD * 2
			&& map[(cam->y - SPD * 2) / 64][cam->x / 64] != '1'
			&& map[(cam->y - SPD * 2) / 64][cam->x / 64] != '2'
			? SPD * 2 : 0;
	cam->lock = 1;
	put_image(win);
	return (true);
}
