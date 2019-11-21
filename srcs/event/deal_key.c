#include "wolf3d.h"
#include <stdlib.h>
#include "mlx.h"
#include <libft.h>
#include <event.h>
#define EVENT_NB 16

static void	found_event_function(int *key_tab, t_env *env, int key, int i)
{
	void (*f_tab[EVENT_NB])(t_env *env);

	f_tab[0] = event_left;
	f_tab[1] = event_backward;
	f_tab[2] = event_right;
	f_tab[3] = event_forward;
	f_tab[4] = event_reset;
	f_tab[5] = event_map;
	f_tab[6] = event_tab;
	f_tab[7] = quit_window;
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

int			deal_key(int key, t_env *env)
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
	return (0);
}
