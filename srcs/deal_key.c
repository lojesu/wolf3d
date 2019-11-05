#include "wolf3d.h"
#include <stdlib.h>
#include "mlx.h"
#include "wolf3d.h"
#include "libmath.h"
#include <math.h>

static void	move(int key, t_env *env, t_win *win, t_cam *cam)
{
	if (key == FORWARD)
	{
		cam->x += cos(deg_to_rad(cam->orientation)) * 8;
		cam->y -= sin(deg_to_rad(cam->orientation)) * 8;
		raycasting(win, cam, env->map);
		put_image(win);
	}
	else if (key == BACKWARD)
	{
		cam->x -= cos(deg_to_rad(cam->orientation)) * 8;
		cam->y += sin(deg_to_rad(cam->orientation)) * 8;
		raycasting(win, cam, env->map);
		put_image(win);
	}
}

static void	rotation(int key, t_env *env, t_win *win, t_cam *cam)
{
	if (key == L_ROTATION)
	{
		cam->orientation += 8;
		cam->orientation = cam->orientation > 360 ? - 360 : cam->orientation;
		raycasting(win, cam, env->map);
		put_image(win);
	}
	else if (key == R_ROTATION)
	{
		cam->orientation -= 8;
		cam->orientation = cam->orientation < -360 ? + 360 : cam->orientation;
		raycasting(win, cam, env->map);
		put_image(win);
	}
}

int		deal_key(int key, t_env *env)
{
	t_win	*win;
	t_cam	*cam;

	win = &(env->win);
	cam = &(env->cam);
	rotation(key, env, win, cam);
	move(key, env, win, cam);
	if (key == ESC)
	{
		clear_window(win);
		mlx_destroy_window(MLX_PTR, WIN_PTR);
		exit(1);
	}
	return (0);
}
