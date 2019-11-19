#include "wolf3d.h"
#include "libmath.h"
#include "libft.h"
#include <math.h>

#define ANGLE(ori, col) ori + VISUAL_FIELD / 2 - col * VISUAL_FIELD / WIDTH

t_wall  wall_create(double x, double y, t_cam *cam, enum e_side side)
{
    t_wall ret;

    ret.x = x;
    ret.y = y;
    ret.dist = hypot(x - cam->x, y - cam->y);
    ret.side = side;
    return (ret);
}

t_wall  dist_horizontal(t_cam *cam, char **map, double angle, int8_t y_oriented)
{
	double	xa;
	double	x;
	double	y;
	size_t	i;
    int     x_oriented = angle > 90 && angle < 270 ? -1 : 1;

	i = 0;
	xa = ABS(FRAME / tan(deg_to_rad(angle)));
    trans_hori(cam, angle, &x, &y);
	while (y >= 0 && y / 64 < ft_strlen_len(map) && x >= 0
		&& x / 64 < (int)ft_strlen(map[0]) && !check_wall(x, y, map))
	{
		++i;
		x += x_oriented * xa;
		y += y_oriented * 64;
	}
    return (wall_create(x, y, cam, cam->y - y > 0 ? SIDE_DOWN : SIDE_UP));
}

t_wall	dist_vertical(t_cam *cam, char **map, double angle, int8_t x_oriented)
{
	double	ya;
	double	y;
	double	x;
	size_t	i;
    int     y_oriented = angle > 0 && angle < 180 ? -1 : 1;

	i = 0;
	ya = ABS(FRAME * tan(deg_to_rad(angle)));
    trans_vert(cam, angle, &x, &y);
	while (y >= 0 && y / 64 < ft_strlen_len(map) && x >= 0
		&& x / 64 < (int)ft_strlen(map[0]) && !check_wall(x, y, map))
	{
		++i;
		y += y_oriented * ya;
		x += x_oriented * 64;
	}
    return (wall_create(x, y, cam, cam->x - x > 0 ? SIDE_RIGHT : SIDE_LEFT));
}

t_wall    find_dist_wall(t_cam *cam, char **map, size_t column)
{
	double	angle;
	int8_t	oriented;
	t_wall	wall_h;
    t_wall	wall_v;

	angle = ANGLE(cam->orientation, (double)column);
	angle = angle < 0 ? angle + 360 : angle;
    angle = angle >= 360 ? angle - 360 : angle;
	angle = ((int)angle % 90) == 0 ? angle + 0.1 : angle;
	oriented = angle > 0 && angle < 180 ? -1 : 1;
	wall_h = dist_horizontal(cam, map, angle, oriented);
    wall_h.dist *= TRUE_DIST;
	oriented = angle > 90 && angle < 270 ? -1 : 1;
	wall_v = dist_vertical(cam, map, angle, oriented);
    wall_v.dist *= TRUE_DIST;
    return ( wall_h.dist < wall_v.dist ? wall_h : wall_v);
//    print(win, bmp, wall_h.dist < wall_v.dist ? wall_h : wall_v, column);
}

void	raycasting(t_env *env)
{
	size_t	column;
	int 	size_wall;
    int     pos;
    t_cam   *cam;

    cam = &env->cam;
    special_bloc(env);
	column = 0;
    if (cam->y < 0 || cam->y / 64 >= ft_strlen_len(env->map) ||
        cam->x < 0 || cam->x / 64 >= ft_strlen(env->map[0]) ||
                (env->map[cam->y / 64][cam->x /64] == '8' && cam->button == true))
        quit_window(&env->win, env->map);
	while (column < WIDTH)
	{
		//size_wall = DIST_SCREEN * FRAME / find_dist_wall(cam, map, column);
        print(env, find_dist_wall(cam, env->map, column), column);
		++column;
	}
    print_mini_map(cam, env->map, &env->win);
}
