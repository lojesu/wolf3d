#include <wolf3d.h>
#include <special_bloc.h>

#define SPD 2

bool	speed_walk_right(t_env *env)
{
	t_cam	*cam;
	char	**map;
	t_win	*win;

	win = &env->win;
	cam = &env->cam;
	map = env->map;
	cam->x += map[cam->y / 64][(cam->x + SPD + 1) / 64] == '1' ? 0 : SPD;
	cam->x += cam->x % 64 < SPD * 2 ? SPD * 2 : 0;
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
	cam->x -= map[cam->y / 64][(cam->x - SPD - 1) / 64] == '1' ? 0 : SPD;
	cam->x -= cam->x % 64 < SPD * 2 ? SPD * 2 : 0;
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
	cam->y += map[(cam->y + SPD + 1) / 64][cam->x / 64] == '1' ? 0 : SPD;
	cam->y += cam->y % 64 < SPD * 2 ? SPD * 2 : 0;
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
	cam->y -= map[(cam->y - SPD - 1) / 64][cam->x / 64] == '1' ? 0 : SPD;
	cam->y -= cam->y % 64 < SPD * 2 ? SPD * 2 : 0;
	cam->lock = 1;
	put_image(win);
	return (true);
}
