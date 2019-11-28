/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:09:23 by glegendr          #+#    #+#             */
/*   Updated: 2019/11/28 18:09:25 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <math.h>
#include <libmath.h>
#include <event.h>
#define SPEED 8

static void	move_direction(t_cam *cam, char **map, int dir)
{
	int x_move;
	int y_move;
	int new_angle;

	if (cam->lock)
		return ;
	new_angle = cam->orientation + dir;
	new_angle = new_angle > 360 ? new_angle - 360 : new_angle;
	new_angle = new_angle < 0 ? new_angle + 360 : new_angle;
	x_move = cos(deg_to_rad(new_angle)) * SPEED * 2;
	y_move = sin(deg_to_rad(new_angle)) * SPEED * 2;
	cam->x = check_wall(cam->x + x_move, cam->y, map) ?
		cam->x : cam->x + x_move / 2;
	cam->y = check_wall(cam->x, cam->y - y_move, map) ?
		cam->y : cam->y - y_move / 2;
}

void		event_forward(t_env *env)
{
	move_direction(&env->cam, env->map, 0);
	raycasting(env);
	put_image(&env->win);
}

void		event_backward(t_env *env)
{
	move_direction(&env->cam, env->map, 180);
	raycasting(env);
	put_image(&env->win);
}

void		event_left(t_env *env)
{
	move_direction(&env->cam, env->map, 90);
	raycasting(env);
	put_image(&env->win);
}

void		event_right(t_env *env)
{
	move_direction(&env->cam, env->map, -90);
	raycasting(env);
	put_image(&env->win);
}
