#include "wolf3d.h"
#include "libmath.h"
#include "libft.h"
#include <math.h>
#include <stdbool.h>

#define ANGLE(ori, col) ori + VISUAL_FIELD / 2 - col * VISUAL_FIELD / WIDTH

void    trans_vert(t_cam *cam, double angle, double *x, double *y)
{
    if (angle > 90 && angle < 270)
    {
        *x = cam->x / 64 * 64;
        *y = cam->y + tan(deg_to_rad(angle - 180)) * ABS((cam->x - *x));
    }
    else if (angle < 90)
    {
        *x = cam->x / 64 * 64 + 64;
        *y = cam->y - tan(deg_to_rad(angle)) * ABS((cam->x - *x));
    }
    else
    {
        *x = cam->x / 64 * 64 + 64;
        *y = cam->y + tan(deg_to_rad(ABS((angle - 360)))) * ABS((cam->x - *x));
    }
}

void    trans_hori(t_cam *cam, double angle, double *x, double *y)
{
    if (angle > 180  && angle < 360)
    {
        *y = cam->y / 64 * 64 + 64;
        *x = cam->x + tan(deg_to_rad(angle - 270)) * ABS((cam->y - *y));
    }
    else
    {
        *y = cam->y / 64 * 64;
        *x = cam->x + tan(deg_to_rad(90 - angle)) * ABS((cam->y - *y));
    }
}


bool    check_wall(double x, double y, char **map)
{
        if (x < 0 || x / 64 >= ft_strlen(map[0]) ||
                        y < 0 || y / 64 >= ft_strlen_len(map))
               return (false);
        if (fmod(x, 64) == 0 && fmod(y, 64) == 0)
                return ( 
                            map[((int)y - 1) / 64][((int)x - 1) / 64] == '1' ||
                            map[((int)y - 1) / 64][((int)x + 1) / 64] == '1' ||
                            map[((int)y + 1) / 64][((int)x + 1) / 64] == '1' ||
                            map[((int)y + 1) / 64][((int)x - 1) / 64] == '1'
                        );
        else if (fmod(x, 64) == 0)
                return (
                            map[(int)y / 64][((int)x - 1)/64] == '1' ||
                            map[(int)y / 64][((int)x + 1)/64] == '1'
                       );
        else if (fmod(y, 64) == 0)
                return (
                            map[((int)y - 1) / 64][(int)x / 64] == '1' ||
                            map[((int)y + 1) / 64][(int)x / 64] == '1'
                       );
        else
                return (map[(int)y / 64][(int)x / 64] == '1');
}

size_t	dist_horizontal(t_cam *cam, char **map, double angle, int8_t y_oriented)
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
	return ((size_t)hypot(x - cam->x, y - cam->y));
}

size_t	dist_vertical(t_cam *cam, char **map, double angle, int8_t x_oriented)
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
	return ((size_t)hypot(x - cam->x, y - cam->y));
}

size_t	find_dist_wall(t_cam *cam, char **map, size_t column)
{
	double	angle;
	int8_t	oriented;
	size_t	dist_h;
	size_t	dist_v;

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
	size_t	size_wall;

	column = 0;
	while (column < WIDTH)
	{
		size_wall = DIST_SCREEN * FRAME / find_dist_wall(cam, map, column);
		print_column(win, size_wall, column);
		++column;
	}
}
