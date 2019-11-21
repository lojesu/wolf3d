#include "wolf3d.h"
#include <libft.h>
#include <math.h>
#include <libmath.h>
#include <map.h>

#define CELL_SIZE 32
#define CELL_NB 3
#define MAP_POS 15
#define MAP_SIZE ((CELL_SIZE + 1) * (CELL_NB * 2 + 1) - CELL_NB * 2)
#define PLAYER_SIZE (CELL_SIZE / 4 + 2)
#define PLAYER (MAP_SIZE / 2 - PLAYER_SIZE / 2 + MAP_POS + 1 + PLAYER_SIZE / 2)
#define CALC(a, b) (a + b * FRAME / CELL_SIZE - CELL_NB * 64 - 32)

static void	outline_mini_map_circle(t_win *win, int x_center, int y_center)
{
	size_t	x;
	size_t	y;
	int		m;

	x = 0;
	y = (CELL_SIZE + 1) * CELL_NB + CELL_NB;
	m = 5 - 4 * y;
	while (x <= y)
	{
		put_pixel(win, x + x_center, y + y_center, 0xffffff);
		put_pixel(win, y + x_center, x + y_center, 0xffffff);
		put_pixel(win, -x + x_center, y + y_center, 0xffffff);
		put_pixel(win, -y + x_center, x + y_center, 0xffffff);
		put_pixel(win, x + x_center, -y + y_center, 0xffffff);
		put_pixel(win, y + x_center, -x + y_center, 0xffffff);
		put_pixel(win, -x + x_center, -y + y_center, 0xffffff);
		put_pixel(win, -y + x_center, -x + y_center, 0xffffff);
		if (m > 0)
		{
			y = y - 1;
			m = m - 8 * y;
		}
		x = x + 1;
		m = m + 8 * x + 4;
	}
}

static void	outline_mini_map(t_win *win, int type)
{
	int x;
	int y;

	if (type == 1)
	{
		return (outline_mini_map_circle(win, MAP_POS + (MAP_SIZE) / 2,
				MAP_POS + (MAP_SIZE) / 2));
	}
	y = MAP_POS - 2;
	while (y < MAP_POS + MAP_SIZE + 2)
	{
		x = MAP_POS - 2;
		while (x < MAP_POS + MAP_SIZE + 2)
		{
			if (x < MAP_POS || x >= MAP_POS + MAP_SIZE ||
				y < MAP_POS || y >= MAP_POS + MAP_SIZE)
				put_pixel(win, x, y, 0xffffff);
			++x;
		}
		++y;
	}
}

static void	mini_map_print_line(int x, int y, t_env *env)
{
	int		xi;
	t_cam	*cam;

	xi = 0;
	cam = &env->cam;
	while (x < MAP_SIZE)
	{
		if (CALC(cam->x, x) / FRAME > xi / FRAME)
		{
			xi = CALC(cam->x, x++);
			continue ;
		}
		if (in_circle(x + MAP_POS, y + MAP_POS) || cam->mini_map == 2)
			put_pixel(&env->win, x + MAP_POS, y + MAP_POS,
				give_color(env->map, CALC(cam->x, x), CALC(cam->y, y)));
		xi = CALC(cam->x, x++);
	}
}

static void	print_mini_map_cells(t_env *env, t_cam *cam, int y, int yi)
{
	int x;

	while (y < MAP_SIZE)
	{
		if (CALC(cam->y, y) / FRAME > yi / FRAME)
		{
			yi = CALC(cam->y, y++);
			continue ;
		}
		x = 0;
		mini_map_print_line(x, y, env);
		yi = CALC(cam->y, y++);
	}
}

void		print_mini_map(t_env *env)
{
	if ((&env->cam)->map == 1)
		return (big_map(&env->win, &env->cam, env->map));
	else if ((&env->cam)->mini_map == 0)
		return ;
	print_mini_map_cells(env, &env->cam, 0, 0);
	outline_mini_map(&env->win, (&env->cam)->mini_map);
	put_fov(&env->win, &env->cam, PLAYER, PLAYER);
}
