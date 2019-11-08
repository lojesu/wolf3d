#include "wolf3d.h"
#include <stdlib.h>
#include "mlx.h"
#include "wolf3d.h"
#include "libmath.h"
#include <math.h>

#define SPEED 8
#define ROTATION 8

static void	move(int key, t_env *env, t_win *win, t_cam *cam)
{
    int x_move;
    int y_move;

    printf("%i %i %i\n", cam->orientation, cam->x, cam->y);
	if (key == FORWARD)
	{
		x_move = cos(deg_to_rad(cam->orientation)) * SPEED * 2;
		y_move = sin(deg_to_rad(cam->orientation)) * SPEED * 2;
        cam->x = check_wall(cam->x + x_move, cam->y, env->map) ? cam->x : cam->x + x_move / 2;
        cam->y = check_wall(cam->x, cam->y - y_move, env->map) ? cam->y : cam->y - y_move / 2;
		raycasting(win, cam, env->map);
		put_image(win);
	}
	else if (key == BACKWARD)
	{
		x_move = cos(deg_to_rad(cam->orientation)) * SPEED * 2;
		y_move = sin(deg_to_rad(cam->orientation)) * SPEED * 2;
        cam->x = check_wall(cam->x - x_move, cam->y, env->map) ? cam->x : cam->x - x_move / 2;
        cam->y = check_wall(cam->x, cam->y + y_move, env->map) ? cam->y : cam->y + y_move / 2;
		raycasting(win, cam, env->map);
		put_image(win);
	}
    else if (key == LEFT)
    {
		x_move = cos(deg_to_rad(cam->orientation - 90)) * SPEED * 2;
		y_move = sin(deg_to_rad(cam->orientation - 90)) * SPEED * 2;
        cam->x = check_wall(cam->x - x_move, cam->y, env->map) ? cam->x : cam->x - x_move / 2;
        cam->y = check_wall(cam->x, cam->y + y_move, env->map) ? cam->y : cam->y + y_move / 2;
		raycasting(win, cam, env->map);
		put_image(win);
    }
    else if (key == RIGHT)
    {
		x_move = cos(deg_to_rad(cam->orientation + 90)) * SPEED * 2;
		y_move = sin(deg_to_rad(cam->orientation + 90)) * SPEED * 2;
        cam->x = check_wall(cam->x - x_move, cam->y, env->map) ? cam->x : cam->x - x_move / 2;
        cam->y = check_wall(cam->x, cam->y + y_move, env->map) ? cam->y : cam->y + y_move / 2;
		raycasting(win, cam, env->map);
		put_image(win);
    }
}

static void	rotation(int key, t_env *env, t_win *win, t_cam *cam)
{
    printf("ORIENTATION: %i\n", cam->orientation);
	if (key == L_ROTATION)
	{
		cam->orientation += ROTATION;
		cam->orientation = cam->orientation >= 360 ? cam->orientation - 360 : cam->orientation;
		raycasting(win, cam, env->map);
		put_image(win);
	}
	else if (key == R_ROTATION)
	{
		cam->orientation -= ROTATION;
		cam->orientation = cam->orientation < 0 ? cam->orientation + 360 : cam->orientation;
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
