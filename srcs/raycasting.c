#include "wolf3d.h"
#include "libmath.h"
#include "libft.h"
#include <math.h>


#include <stdio.h>

size_t strLenLen (char ** tab)
{
        size_t x = 0;
        while (tab[x])
            ++x;
        return (x);
}
                
size_t	dist_horizontal(t_cam cam, char **map, double angle, int8_t y_oriented)
{
	int32_t	xa;
	int32_t	x;
	int32_t	y; 
	size_t	i;

	i = 0;
    angle = angle < 0 ? (angle + 360) : (angle == 0 ? 0.00001 : angle);
	xa = FRAME / tan(deg_to_rad(angle));
    xa = fabs(xa);
	x = (cam.x + i * xa);
	y = cam.y;
	while (y >= 0 && y / 64 < strLenLen(map) && x / 64 <= (int)ft_strlen(map[y / 64]) && map[y / 64][x / 64] != '1' )
	{
		++i;
		x = (cam.x + i * xa);
		y += y_oriented * 64;
	}
	return ((size_t)(hypot(x - cam.x, y - cam.y)));
}

size_t	dist_vertical(t_cam cam, char **map, double angle, int8_t x_oriented)
{
	int32_t	ya;
	int32_t	y;
	int32_t	x;
	size_t	i;

	i = 0;
    angle = angle < 0 ? (angle + 360) : (angle == 0 ? 0.00001 : angle);
	ya = FRAME * tan(deg_to_rad(angle));
    ya = fabs(ya);
	y = (cam.y + i * ya);
	x = cam.x;
    printf("%f -- %i\n", angle, ya);
	while (y >= 0 && y / 64 < strLenLen(map) && x / 64 <= (int)ft_strlen(map[y / 64]) && map[y / 64][x / 64] != '1' )
	{
		++i;
		y = (cam.y + i * ya);
		x += x_oriented * 64;
        printf("%i %i %i\n", x, y, i);
	}
	return ((size_t)(hypot(x - cam.x, y - cam.y)));
}

size_t	find_dist_wall(t_cam cam, char **map, size_t column)
{
	double	angle;
	int8_t	y_oriented;
	int8_t	x_oriented;
	size_t	dist_h;
	size_t	dist_v;

	angle = cam.orientation + VISUAL_FIELD / 2 - ((double)column) * VISUAL_FIELD / WIDTH;
	y_oriented = angle > 0 && angle < 180 ? -1 : 1;
	dist_h = dist_horizontal(cam, map, angle, y_oriented) * cos(deg_to_rad(((double)column) * VISUAL_FIELD / WIDTH -30));
	x_oriented = angle > 90 && angle < 270 ? -1 : 1;
	dist_v = dist_vertical(cam, map, angle, x_oriented) * cos(deg_to_rad(((double)column) * VISUAL_FIELD / WIDTH -30));
    printf("%zu\n", dist_v);
	return (dist_h < dist_v ? dist_h : dist_v);
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
		++column;
	}
}
