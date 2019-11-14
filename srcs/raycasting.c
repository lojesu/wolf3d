#include "wolf3d.h"
#include "libmath.h"
#include "libft.h"
#include <math.h>

#define ANGLE(ori, col) ori + VISUAL_FIELD / 2 - col * VISUAL_FIELD / WIDTH

double	dist_horizontal(t_cam *cam, char **map, double angle, int8_t y_oriented)
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
	return (hypot(x - cam->x, y - cam->y));
}

double	dist_vertical(t_cam *cam, char **map, double angle, int8_t x_oriented)
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
	return (hypot(x - cam->x, y - cam->y));
}

double  find_dist_wall(t_cam *cam, char **map, size_t column)
{
	double	angle;
	int8_t	oriented;
	double	dist_h;
	double	dist_v;

	angle = ANGLE(cam->orientation, (double)column);
	angle = angle < 0 ? angle + 360 : angle;
    angle = angle >= 360 ? angle - 360 : angle;
	angle = ((int)angle % 90) == 0 ? angle + 0.1 : angle;
	oriented = angle > 0 && angle < 180 ? -1 : 1;
	dist_h = dist_horizontal(cam, map, angle, oriented) * TRUE_DIST;
	oriented = angle > 90 && angle < 270 ? -1 : 1;
	dist_v = dist_vertical(cam, map, angle, oriented) * TRUE_DIST;
	return (dist_h < dist_v ? dist_h : dist_v);
}

void	raycasting(t_win *win, t_cam *cam, char **map)
{
	size_t	column;
	int 	size_wall;
    int     pos;

    special_bloc(win, cam, map);
	column = 0;
    if (cam->y < 0 || cam->y / 64 >= ft_strlen_len(map) ||
        cam->x < 0 || cam->x / 64 >= ft_strlen(map[0]) ||
                (map[cam->y / 64][cam->x /64] == '8' && cam->button == true))
        quit_window(win, map);
	while (column < WIDTH)
	{
		size_wall = DIST_SCREEN * FRAME / find_dist_wall(cam, map, column);
		print_column(win, size_wall, column, cam);
		++column;
	}
    if (cam->mini_map)
        print_mini_map(cam, map, win);
}
