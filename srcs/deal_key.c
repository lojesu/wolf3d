#include "wolf3d.h"
#include <stdlib.h>
#include "mlx.h"
#include "libmath.h"
#include <math.h>
#include <libft.h>

#define SPEED 8
#define ROTATION 8

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

void		event_tab(t_env *env)
{
	t_cam *cam;

	cam = &env->cam;
	cam->mini_map = cam->mini_map + 1;
	cam->mini_map = cam->mini_map == 3 ? 0 : cam->mini_map;
	raycasting(env);
	put_image(&env->win);
}

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

void		event_reset(t_env *env)
{
	t_cam	*cam;
	int		tmp;

	cam = &env->cam;
	tmp = cam->mini_map;
	*cam = init_cam(env->map);
	cam->mini_map = tmp;
	raycasting(env);
	put_image(&env->win);
}

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

void		event_esc(t_env *env)
{
	quit_window(&env->win, env->map);
}

#define EVENT_NB 16

void	found_event_function(int *key_tab, t_env *env, int key, int i)
{
	void (*f_tab[EVENT_NB])(t_env *env);

	f_tab[0] = event_left;
	f_tab[1] = event_backward;
	f_tab[2] = event_right;
	f_tab[3] = event_forward;
	f_tab[4] = event_reset;
	f_tab[5] = event_map;
	f_tab[6] = event_tab;
	f_tab[7] = event_esc;
	f_tab[8] = event_left_map;
	f_tab[9] = event_down_map;
	f_tab[10] = event_right_map;
	f_tab[11] = event_up_map;
	f_tab[12] = event_l_rotation;
	f_tab[13] = event_r_rotation;
	f_tab[14] = event_down;
	f_tab[15] = event_up;
	while (i < EVENT_NB)
	{
		if (key == key_tab[i])
			f_tab[i](env);
		++i;
	}
}

void	init_key_hash_map(t_env *env, int key)
{
	int key_tab[EVENT_NB];

	key_tab[0] = LEFT;
	key_tab[1] = BACKWARD;
	key_tab[2] = RIGHT;
	key_tab[3] = FORWARD;
	key_tab[4] = RESET;
	key_tab[5] = MAP;
	key_tab[6] = TAB;
	key_tab[7] = ESC;
	key_tab[8] = LEFT_MAP;
	key_tab[9] = DOWN_MAP;
	key_tab[10] = RIGHT_MAP;
	key_tab[11] = UP_MAP;
	key_tab[12] = L_ROTATION;
	key_tab[13] = R_ROTATION;
	key_tab[14] = DOWN;
	key_tab[15] = UP;
	found_event_function(key_tab, env, key, 0);
}

void		quit_window(t_win *win, char **map)
{
	clear_window(win);
	mlx_destroy_window(MLX_PTR, WIN_PTR);
	ft_tabdel_char(&map);
	exit(1);
}

int			deal_key(int key, t_env *env)
{
	init_key_hash_map(env, key);
	return (0);
}
