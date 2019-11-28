/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:09:27 by glegendr          #+#    #+#             */
/*   Updated: 2019/11/28 18:09:29 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <event.h>

void		event_tab(t_env *env)
{
	t_cam *cam;

	cam = &env->cam;
	cam->mini_map = cam->mini_map + 1;
	cam->mini_map = cam->mini_map == 3 ? 0 : cam->mini_map;
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
