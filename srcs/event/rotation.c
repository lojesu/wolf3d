#include "wolf3d.h"
#include "libmath.h"
#include <event.h>

#define ROTATION 8

void		event_l_rotation(t_env *env)
{
	t_cam *cam;

	cam = &env->cam;
	cam->orientation += ROTATION;
	cam->orientation = cam->orientation >= 360 ?
			cam->orientation - 360 : cam->orientation;
	raycasting(env);
	put_image(&env->win);
}

void		event_r_rotation(t_env *env)
{
	t_cam *cam;

	cam = &env->cam;
	cam->orientation -= ROTATION;
	cam->orientation = cam->orientation < 0 ?
			cam->orientation + 360 : cam->orientation;
	raycasting(env);
	put_image(&env->win);
}

void		event_up(t_env *env)
{
	t_cam *cam;

	cam = &env->cam;
	if (cam->angle > HEIGHT / 2 - ROTATION)
		return ;
	cam->angle += ROTATION * 2;
	raycasting(env);
	put_image(&env->win);
}

void		event_down(t_env *env)
{
	t_cam *cam;

	cam = &env->cam;
	if (cam->angle < -(HEIGHT / 2 - ROTATION))
		return ;
	cam->angle -= ROTATION * 2;
	raycasting(env);
	put_image(&env->win);
}
