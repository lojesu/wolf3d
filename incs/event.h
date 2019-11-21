#ifndef EVENT_H
# define EVENT_H

# define ESC 53
# define FORWARD 13
# define BACKWARD 1
# define LEFT 0
# define RIGHT 2
# define L_ROTATION 123
# define R_ROTATION 124
# define UP 126
# define DOWN 125
# define TAB 48
# define RESET 15
# define MAP 46
# define UP_MAP 91
# define DOWN_MAP 87
# define LEFT_MAP 86
# define RIGHT_MAP 88

/*
** event functions
*/
void	event_reset(t_env *env);
void	event_left(t_env *env);
void	event_backward(t_env *env);
void	event_right(t_env *env);
void	event_forward(t_env *env);
void	event_map(t_env *env);
void	event_tab(t_env *env);
void	event_left_map(t_env *env);
void	event_down_map(t_env *env);
void	event_right_map(t_env *env);
void	event_up_map(t_env *env);
void	event_l_rotation(t_env *env);
void	event_r_rotation(t_env *env);
void	event_down(t_env *env);
void	event_up(t_env *env);
int		deal_key(int key, t_env *env);

#endif
