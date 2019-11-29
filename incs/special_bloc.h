/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_bloc.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:11:35 by glegendr          #+#    #+#             */
/*   Updated: 2019/11/29 14:08:37 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIAL_BLOC_H
# define SPECIAL_BLOC_H

int		is_special_bloc(t_env *env);
bool	special_bloc(t_env *env);
bool	speed_walk_right(t_env *env);
bool	speed_walk_left(t_env *env);
bool	speed_walk_down(t_env *env);
bool	speed_walk_up(t_env *env);
bool	special_wall_press(t_env *env);
bool	special_reset(t_env *env);
bool	special_end_press(t_env *env);
bool	special_end(t_env *env);
bool	special_canon_right(t_env *env);
bool	special_canon_left(t_env *env);
bool	special_canon_down(t_env *env);
bool	special_canon_up(t_env *env);
bool	special_floor_press(t_env *env);
void	special_canon_manager(t_env *env);
void	launch_cinematique(t_env *env);
void	find_destination(int *x, int *y, t_env *env, int *ori);
void	replace_me(char **map, char c, char r);

#endif
