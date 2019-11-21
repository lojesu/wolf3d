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

#endif
