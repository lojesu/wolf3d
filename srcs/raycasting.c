#include "wolf3d.h"
#include "libmath.h"
#include "libft.h"
#include <math.h>


#include <stdio.h>
size_t	dist_horizontal(t_cam cam, char **map, double angle, int8_t y_oriented)
{
	int32_t	xa;
	int32_t	x;
	int32_t	y; 
	size_t	i;

	i = 0;
	xa = FRAME / tan(deg_to_rad(angle));
	x = (cam.x + i * xa);
	y = cam.y;
	while (map[y / 64][x / 64] != '1' && y >= 0 && x / 64 <= (int)ft_strlen(map[y]))
	{
		i++;
		x = (cam.x + i * xa);
		y += y_oriented * 64;
	}
	return ((size_t)(hypot(fabs((double)(x - cam.x)), fabs((double)(y - cam.y)))));
}
/*
size_t	dist_vertical(t_cam cam, char **map, double angle, int8_t y_oriented)
{
	int32_t	ya;
	int32_t	x;
	int32_t	y;
	size_t	i;

	i = 0;
	ya = FRAME * tan(deg_to_rad(angle));
	x = cam.x;
	y = (cam.y + i * ya);
	while(map[y / 64][x / 64] != '1')
	{
		i++;
		x += 1 * 64;
		if (y_oriented == -1)
			y -= (cam.y + i * ya);
		if (y_oriented == 1)
			y += (cam.y + i * ya);
	}
	return ((size_t)(hypot(fabs((double)(x - cam.x)), fabs((double)(y - cam.y)))));
}
*/
size_t	find_dist_wall(t_cam cam, char **map, size_t column)
{
	double	angle;
	int8_t	y_oriented;
	size_t	dist_h;
	//size_t	dist_v;

	angle = cam.orientation + VISUAL_FIELD / 2 - column * VISUAL_FIELD / WIDTH;
	y_oriented = function();//
	dist_h = dist_horizontal(cam, map, angle, y_oriented);
//	dist_v = dist_vertical(cam, map, angle, y_oriented);
//	return (dist_h < dist_v ? dist_h : dist_v);
	return (dist_h);
}

void	raycasting(t_win *win, t_cam cam, char **map)
{
	size_t	column;
	size_t	size_wall;

	column = 0;
	while (column < WIDTH)
	{
		size_wall = DIST_SCREEN * FRAME / find_dist_wall(cam, map, column);
		print_column(win, size_wall, column);
		column++;
	}
}
