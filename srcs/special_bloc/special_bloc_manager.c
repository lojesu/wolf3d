#include "wolf3d.h"
#include "libft.h"
#include <special_bloc.h>

#define SPE_NB 7

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
		quit_window(env);
	return (init_special_tab(env, map[cam->y / 64][cam->x / 64], 0));
}

int		is_special_bloc(t_env *env)
{
	if (special_bloc(env))
		raycasting(env);
	return (0);
}
