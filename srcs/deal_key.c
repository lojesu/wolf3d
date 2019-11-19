#include "wolf3d.h"
#include <stdlib.h>
#include "mlx.h"
#include "libmath.h"
#include <math.h>
#include <libft.h>


#define SPEED 8
#define ROTATION 8

static void move_direction(t_cam *cam, char **map, int dir)
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

void	    move(int key, t_env *env)
{
    t_cam *cam = &env->cam;
	if (key == FORWARD)
	{
        move_direction(&env->cam, env->map, 0);
		raycasting(env);
		put_image(&env->win);
	}
	else if (key == BACKWARD)
	{
        move_direction(&env->cam, env->map, 180);
		raycasting(env);
		put_image(&env->win);
	}
    else if (key == LEFT)
    {
        move_direction(&env->cam, env->map, 90);
		raycasting(env);
		put_image(&env->win);
    }
    else if (key == RIGHT)
    {
        move_direction(&env->cam, env->map, -90);
		raycasting(env);
		put_image(&env->win);
    }
    else if (key == TAB)
    {
        cam->mini_map = cam->mini_map + 1;
        cam->mini_map = cam->mini_map == 3 ? 0 : cam->mini_map;
		raycasting(env);
		put_image(&env->win);
    }
    else if (key == MAP)
    {
        cam->map = !cam->map;
        cam->bmapx = 0;
        cam->bmapy = 0;
		raycasting(env);
		put_image(&env->win);
    }
    else if (key == UP_MAP)
    {
        cam->bmapy -= 1;
		raycasting(env);
		put_image(&env->win);
    }
    else if (key == DOWN_MAP)
    {
        cam->bmapy += 1;
		raycasting(env);
		put_image(&env->win);
    }
    else if (key == RIGHT_MAP)
    {
        cam->bmapx += 1;
		raycasting(env);
		put_image(&env->win);
    }
    else if (key == LEFT_MAP)
    {
        cam->bmapx -= 1;
		raycasting(env);
		put_image(&env->win);
    }
    else if (key == RESET)
    {
        key = cam->mini_map;
        *cam = init_cam(env->map);
        cam->mini_map = key;
		raycasting(env);
		put_image(&env->win);
    }
}

static void	rotation(int key, t_env *env, t_win *win, t_cam *cam)
{
	if (key == L_ROTATION)
	{
		cam->orientation += ROTATION;
		cam->orientation = cam->orientation >= 360 ?
                cam->orientation - 360 : cam->orientation;
		raycasting(env);
		put_image(&env->win);
	}
	else if (key == R_ROTATION)
	{
		cam->orientation -= ROTATION;
		cam->orientation = cam->orientation < 0 ?
                cam->orientation + 360 : cam->orientation;
		raycasting(env);
		put_image(&env->win);
	}
	else if (key == UP)
	{
        if (cam->angle > 96)
                return ;
        cam->angle += ROTATION * 2;
		raycasting(env);
		put_image(&env->win);
	}
	else if (key == DOWN)
	{
        if (cam->angle < -96)
                return ;
		cam->angle -= ROTATION * 2;
		raycasting(env);
		put_image(&env->win);
	}
}

void    quit_window(t_win *win, char **map)
{
	clear_window(win);
	mlx_destroy_window(MLX_PTR, WIN_PTR);
    ft_tabdel_char(&map);
	exit(1);
}

int		deal_key(int key, t_env *env)
{
	rotation(key, env, &env->win, &env->cam);
	move(key, env);
	if (key == ESC)
        quit_window(&env->win, env->map);
	return (0);
}
