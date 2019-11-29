/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cannons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:39:27 by glegendr          #+#    #+#             */
/*   Updated: 2019/11/29 11:55:26 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <special_bloc.h>

bool	special_canon_right(t_env *env)
{
	t_cam tmp;

	tmp = env->cam;
	(&env->cam)->orientation = 0;
	speed_walk_right(env);
	if (tmp.x == (&env->cam)->x && tmp.y == (&env->cam)->y)
		(&env->cam)->lock = 0;
	else
		(&env->cam)->lock = 3;
	(&env->cam)->orientation = 0;
	return (true);
}

bool	special_canon_left(t_env *env)
{
	t_cam tmp;

	tmp = env->cam;
	(&env->cam)->orientation = 180;
	speed_walk_left(env);
	if (tmp.x == (&env->cam)->x && tmp.y == (&env->cam)->y)
		(&env->cam)->lock = 0;
	else
		(&env->cam)->lock = 3;
	(&env->cam)->orientation = 180;
	return (true);
}

bool	special_canon_down(t_env *env)
{
	t_cam tmp;

	tmp = env->cam;
	(&env->cam)->orientation = 270;
	speed_walk_down(env);
	if (tmp.x == (&env->cam)->x && tmp.y == (&env->cam)->y)
		(&env->cam)->lock = 0;
	else
		(&env->cam)->lock = 3;
	(&env->cam)->orientation = 270;
	return (true);
}

bool	special_canon_up(t_env *env)
{
	t_cam tmp;

	tmp = env->cam;
	(&env->cam)->orientation = 90;
	speed_walk_up(env);
	if (tmp.x == (&env->cam)->x && tmp.y == (&env->cam)->y)
		(&env->cam)->lock = 0;
	else
		(&env->cam)->lock = 3;
	(&env->cam)->orientation = 90;
	return (true);
}

void	special_canon_manager(t_env *env)
{
	t_cam	*cam;
	char	**map;

	cam = &env->cam;
	map = env->map;
	if (map[cam->y / 64][cam->x / 64] == 's')
	{
		cam->lock = 0;
		raycasting(env);
		return ;
	}
	if (cam->orientation == 0)
		special_canon_right(env);
	else if (cam->orientation == 180)
		special_canon_left(env);
	else if (cam->orientation == 270)
		special_canon_down(env);
	else
		special_canon_up(env);
	raycasting(env);
}
