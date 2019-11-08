#include "wolf3d.h"
#include <stdlib.h>
#include "mlx.h"
#include "wolf3d.h"
#include "libmath.h"
#include <math.h>

#define SPEED 64
#define ROTATION 90

static void	move(int key, t_env *env, t_win *win, t_cam *cam)
{
    int x_move;
    int y_move;

	if (key == FORWARD)
	{
		x_move = cam->x + cos(deg_to_rad(cam->orientation)) * SPEED;
		y_move = cam->y - sin(deg_to_rad(cam->orientation)) * SPEED;
        cam->x = check_wall(x_move, cam->y, env->map) ? cam->x : x_move;
        cam->y = check_wall(cam->x, y_move, env->map) ? cam->y : y_move;
		raycasting(win, cam, env->map);
		put_image(win);
	}
	else if (key == BACKWARD)
	{
		x_move = cam->x - cos(deg_to_rad(cam->orientation)) * SPEED;
		y_move = cam->y + sin(deg_to_rad(cam->orientation)) * SPEED;
        cam->x = check_wall(x_move, cam->y, env->map) ? cam->x : x_move;
        cam->y = check_wall(cam->x, y_move, env->map) ? cam->y : y_move;
		raycasting(win, cam, env->map);
		put_image(win);
	}
    else if (key == LEFT)
    {
		x_move = cam->x - cos(deg_to_rad(cam->orientation - 90)) * SPEED;
		y_move = cam->y + sin(deg_to_rad(cam->orientation - 90)) * SPEED;
        cam->x = check_wall(x_move, cam->y, env->map) ? cam->x : x_move;
        cam->y = check_wall(cam->x, y_move, env->map) ? cam->y : y_move;
		raycasting(win, cam, env->map);
		put_image(win);
    }
    else if (key == RIGHT)
    {
		x_move = cam->x - cos(deg_to_rad(cam->orientation + 90)) * SPEED;
		y_move = cam->y + sin(deg_to_rad(cam->orientation + 90)) * SPEED;
        cam->x = check_wall(x_move, cam->y, env->map) ? cam->x : x_move;
        cam->y = check_wall(cam->x, y_move, env->map) ? cam->y : y_move;
		raycasting(win, cam, env->map);
		put_image(win);
    }
}

static void	rotation(int key, t_env *env, t_win *win, t_cam *cam)
{
	if (key == L_ROTATION)
	{
		cam->orientation += ROTATION;
		cam->orientation = cam->orientation > 360 ? - 360 : cam->orientation;
		raycasting(win, cam, env->map);
		put_image(win);
	}
	else if (key == R_ROTATION)
	{
		cam->orientation -= ROTATION;
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
