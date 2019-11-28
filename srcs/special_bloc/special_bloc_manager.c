/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_bloc_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:11:09 by glegendr          #+#    #+#             */
/*   Updated: 2019/11/28 18:11:11 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft.h"
#include <special_bloc.h>
#include <unistd.h>

#define SPE_NB 8

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
	special_tab[7] = '8';
	special_fct[0] = speed_walk_right;
	special_fct[1] = speed_walk_left;
	special_fct[2] = speed_walk_down;
	special_fct[3] = speed_walk_up;
	special_fct[4] = special_wall_press;
	special_fct[5] = special_reset;
	special_fct[6] = special_end_press;
	special_fct[7] = special_end;
	while (i < SPE_NB)
		if (id == special_tab[i++])
			return (special_fct[i - 1](env));
	(&env->cam)->lock = 0;
	return (false);
}

bool	special_bloc(t_env *env)
{
	t_cam	*cam;
	char	**map;
	t_win	*win;

	if ((&env->cam)->scene != 0)
		return (false);
	cam = &env->cam;
	map = env->map;
	win = &env->win;
	if (cam->y < 0 || cam->y / FRAME >= (int)ft_strlen_len(map) ||
			cam->x < 0 || cam->x / FRAME >= (int)ft_strlen(map[0]))
		quit_window(env);
	return (init_special_tab(env, map[cam->y / FRAME][cam->x / FRAME], 0));
}

void	scene(t_env *env)
{
	int		x;
	int		y;
	int		ori;
	t_cam	tmp;

	if ((&env->cam)->scene == 2)
		sleep(1);
	find_destination(&x, &y, env, &ori);
	if ((&env->cam)->scene == 2)
	{
		del_me(env->map, '2');
		del_me(env->map, '3');
	}
	tmp = env->cam;
	(&env->cam)->map = 0;
	(&env->cam)->mini_map = 0;
	(&env->cam)->x = x * FRAME + FRAME / 2;
	(&env->cam)->y = y * FRAME + FRAME / 2;
	(&env->cam)->orientation = ori;
	raycasting(env);
	put_image(&env->win);
	env->cam = tmp;
	(&env->cam)->scene += 1;
}

int		is_special_bloc(t_env *env)
{
	if ((&env->cam)->scene == 1 || (&env->cam)->scene == 2)
		scene(env);
	else if ((&env->cam)->scene == 3)
	{
		sleep(1);
		raycasting(env);
		put_image(&env->win);
		(&env->cam)->scene = 0;
		(&env->cam)->lock = 0;
	}
	else if (special_bloc(env))
		raycasting(env);
	return (0);
}
