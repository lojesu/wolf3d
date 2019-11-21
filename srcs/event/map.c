#include "wolf3d.h"
#include <event.h>

void		event_map(t_env *env)
{
	t_cam *cam;

	cam = &env->cam;
	cam->map = !cam->map;
	cam->bmapx = 0;
	cam->bmapy = 0;
	raycasting(env);
	put_image(&env->win);
}

void		event_up_map(t_env *env)
{
	t_cam *cam;

	cam = &env->cam;
	cam->bmapy -= 1;
	raycasting(env);
	put_image(&env->win);
}

void		event_down_map(t_env *env)
{
	t_cam *cam;

	cam = &env->cam;
	cam->bmapy += 1;
	raycasting(env);
	put_image(&env->win);
}

void		event_right_map(t_env *env)
{
	t_cam *cam;

	cam = &env->cam;
	cam->bmapx += 1;
	raycasting(env);
	put_image(&env->win);
}

void		event_left_map(t_env *env)
{
	t_cam *cam;

	cam = &env->cam;
	cam->bmapx -= 1;
	raycasting(env);
	put_image(&env->win);
}
