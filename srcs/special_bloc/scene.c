/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:11:03 by glegendr          #+#    #+#             */
/*   Updated: 2019/11/28 18:11:07 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <libft.h>
#include <special_bloc.h>

static bool	check_space2(char **map, int *x, int *y, int *ori)
{
	int xa;
	int ya;

	xa = *x;
	ya = *y - 2;
	if (ya > 0 && map[ya][xa] != '1' && map[ya + 1][xa] != '1'
		&& map[ya][xa] != '2' && map[ya + 1][xa] != '2')
	{
		*x = xa;
		*y = ya;
		*ori = 270;
		return (true);
	}
	xa = *x;
	ya = *y + 2;
	if (ya < (int)ft_strlen_len(map) && map[ya][xa] != '1'
		&& map[ya - 1][xa] != '1' && map[ya][xa] != '2'
		&& map[ya - 1][xa] != '2')
	{
		*x = xa;
		*y = ya;
		*ori = 90;
		return (true);
	}
	return (false);
}

static bool	check_space(char **map, int *x, int *y, int *ori)
{
	int xa;
	int ya;

	xa = *x - 2;
	ya = *y;
	if (xa > 0 && map[ya][xa] != '1' && map[ya][xa + 1] != '1'
		&& map[ya][xa] != '2' && map[ya][xa + 1] != '2')
	{
		*x = xa;
		*y = ya;
		*ori = 0;
		return (true);
	}
	xa = *x + 2;
	ya = *y;
	if (xa < (int)ft_strlen(map[0]) && map[ya][xa] != '1'
		&& map[ya][xa - 1] != '1' && map[ya][xa] != '2'
		&& map[ya][xa - 1] != '2')
	{
		*x = xa;
		*y = ya;
		*ori = 180;
		return (true);
	}
	return (check_space2(map, x, y, ori));
}

void		find_destination(int *x, int *y, t_env *env, int *ori)
{
	int xa;
	int ya;

	ya = 0;
	while (ya < (int)ft_strlen_len(env->map))
	{
		xa = 0;
		while (xa < (int)ft_strlen(env->map[0]))
		{
			if (env->map[ya][xa] == '2' && check_space(env->map, &xa, &ya, ori))
			{
				*x = xa;
				*y = ya;
				return ;
			}
			++xa;
		}
		++ya;
	}
	*x = 0;
	*y = 0;
}

void		launch_cinematique(t_env *env)
{
	int		x;
	int		y;
	int		ori;
	t_cam	tmp;

	find_destination(&x, &y, env, &ori);
	if (x == 0 && y == 0)
	{
		del_me(env->map, '2');
		del_me(env->map, '3');
		return ;
	}
	(&env->cam)->scene = 1;
	tmp = env->cam;
	(&env->cam)->map = 0;
	(&env->cam)->mini_map = 0;
	(&env->cam)->x = x * FRAME + FRAME / 2;
	(&env->cam)->y = y * FRAME + FRAME / 2;
	(&env->cam)->orientation = ori;
	raycasting(env);
	put_image(&env->win);
	env->cam = tmp;
	(&env->cam)->lock = 2;
}
