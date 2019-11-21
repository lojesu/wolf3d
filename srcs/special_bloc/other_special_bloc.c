#include <wolf3d.h>
#include <special_bloc.h>

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
