#include "wolf3d.h"
#include "libmath.h"
#include "libft.h"
#include <math.h>

#include <stdio.h>

 #define ANGLE(ori, col) ori + VISUAL_FIELD / 2 - col * VISUAL_FIELD / WIDTH

int32_t	base_x(t_cam *cam, double angle)
{
	int32_t adj;

	adj = cam->y / 64 * 64;
	if (angle < 360 && angle > 180)
		adj += 64;
	adj = ABS((adj - cam->y));
	return (adj + cam->x);
}
	
int32_t	base_y(t_cam *cam, double angle)
{
	int32_t opp;

	opp = cam->x / 64 * 64;
	if (angle < 90 || angle > 270)
		opp += 64;
	opp = ABS((opp - cam->x));
	return (opp + cam->y);
}
	

size_t	dist_horizontal(t_cam *cam, char **map, double angle, int8_t y_oriented)
{
	int32_t	xa;
	int32_t	x;
	int32_t	y;
	size_t	i;

	////printf("bite1\n");
	i = 0;
	angle = ((int)angle % 180) == 0 ? angle + 0.1 : angle;
	xa = ABS(FRAME / tan(deg_to_rad(angle)));
	x = (base_x(cam, angle) + i * xa);
	//printf("%i\n", x);
	y = base_y(cam, angle);
	//printf("%i\n", y);
	////printf("bite2\n");
	while (y >= 0 && y / 64 < ft_strlen_len(map)
		&& x / 64 <= (int)ft_strlen(map[y / 64]) && map[y / 64][x / 64] != '1')
	{
		++i;
		x = (base_x(cam, angle) + i * xa);
		y += y_oriented * 64;
	}
	////printf("bite3\n\n");
	return ((size_t)hypot(x - cam->x, y - cam->y));
}

size_t	dist_vertical(t_cam *cam, char **map, double angle, int8_t x_oriented)
{
	int32_t	ya;
	int32_t	y;
	int32_t	x;
	size_t	i;

	i = 0;
	angle = ((int)angle % 180) == 0 ? angle + 0.1 : angle;
	ya = ABS(FRAME * tan(deg_to_rad(angle)));
	y = (base_y(cam, angle) + i * ya);
	x = base_x(cam, angle);
	while (y >= 0 && y / 64 < ft_strlen_len(map)
		&& x / 64 <= (int)ft_strlen(map[y / 64]) && map[y / 64][x / 64] != '1')
	{
		++i;
		y = (base_y(cam, angle) + i * ya);
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
	oriented = angle > 0 && angle < 180 ? -1 : 1;
	dist_h = dist_horizontal(cam, map, angle, oriented) * TRUE_DIST;
	printf("%i -> %zu -- ", column, dist_h);
	oriented = angle > 90 && angle < 270 ? -1 : 1;
	dist_v = dist_vertical(cam, map, angle, oriented) * TRUE_DIST;
	printf("%zu\n", dist_v);
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
