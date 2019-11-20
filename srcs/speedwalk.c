#include "wolf3d.h"
#include "libft.h"

#define SPD 2

void	del_me(char **map, char c)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			map[y][x] = map[y][x] == c ? '0' : map[y][x];
			++x;
		}
		++y;
	}
}

#define SPE_NB 7

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
	cam->lock = true;
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
	cam->lock = true;
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
	cam->lock = true;
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
	cam->lock = true;
	put_image(win);
	return (true);
}

bool	special_wall_press(t_env *env)
{
	char	**map;
	t_win	*win;

	win = &env->win;
	map = env->map;
	del_me(map, '2');
	del_me(map, '3');
	put_image(win);
	return (true);
}

bool	special_reset(t_env *env)
{
	t_win	*win;

	win = &env->win;
	event_reset(env);
	put_image(win);
	return (true);
}

bool	special_end_press(t_env *env)
{
	t_cam	*cam;
	char	**map;
	t_win	*win;

	win = &env->win;
	cam = &env->cam;
	map = env->map;
	cam->button = true;
	del_me(map, '7');
	put_image(win);
	return (true);
}

bool	init_special_tab(t_env *env, int id, int i)
{
	char	special_tab[SPE_NB];
	bool	(*special_fct[SPE_NB])(t_env *env);

	special_tab[0] = 'R';
	special_tab[1] = 'L';
	special_tab[2] = 'D';
	special_tab[3] = 'U';
	special_tab[4] = '3';
	special_tab[5] = '6';
	special_tab[6] = '7';
	special_fct[0] = speed_walk_right;
	special_fct[1] = speed_walk_left;
	special_fct[2] = speed_walk_down;
	special_fct[3] = speed_walk_up;
	special_fct[4] = special_wall_press;
	special_fct[5] = special_reset;
	special_fct[6] = special_end_press;
	while (i < SPE_NB)
	{
		if (id == special_tab[i])
			return (special_fct[i](env));
		++i;
	}
	(&env->cam)->lock = false;
	return (false);
}

bool	special_bloc(t_env *env)
{
	t_cam	*cam;
	char	**map;
	t_win	*win;

	cam = &env->cam;
	map = env->map;
	win = &env->win;
	if (cam->y < 0 || cam->y / 64 >= ft_strlen_len(map) ||
			cam->x < 0 || cam->x / 64 >= ft_strlen(map[0]))
		quit_window(win, map);
	return (init_special_tab(env, map[cam->y / 64][cam->x / 64], 0));
}

void	pre_raycasting(t_env *env)
{
	if (special_bloc(env))
		raycasting(env);
}
