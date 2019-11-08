#include "wolf3d.h"
#include "libmath.h"
#include "libft.h"
#include <math.h>
#include <stdbool.h>

#include <stdio.h>

#define ANGLE(ori, col) ori + VISUAL_FIELD / 2 - col * VISUAL_FIELD / WIDTH

void    trans_vert(t_cam *cam, double angle, int *x, int *y)
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

void    trans_hori(t_cam *cam, double angle, int *x, int *y)
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


bool    check_wall(int x, int y, char **map)
{
        if (x < 0 || x / 64 >= ft_strlen(map[0]) || y < 0 || y / 64 >= ft_strlen_len(map))
                return (false);
        if (x % 64 == 0 && y % 64 == 0)
        {
                return (
                            map[(y - 1) / 64][(x - 1) / 64] == '1' ||
                            map[(y - 1) / 64][(x + 1) / 64] == '1' ||
                            map[(y + 1) / 64][(x + 1) / 64] == '1' ||
                            map[(y + 1) / 64][(x - 1) / 64] == '1'
                        );
        }
        else if (x % 64 == 0)
        {
                return (
                            map[y / 64][(x - 1)/64] == '1' ||
                            map[y / 64][(x + 1)/64] == '1'
                       );
        }
        else if (y % 64 == 0)
        {
                return (
                            map[(y - 1) / 64][x / 64] == '1' ||
                            map[(y + 1) / 64][x / 64] == '1'
                       );
        }
        else
                return (false);
}

size_t	dist_horizontal(t_cam *cam, char **map, double angle, int8_t y_oriented)
{
	int32_t	xa;
	int32_t	x;
	int32_t	y;
	size_t	i;
    int     x_oriented = angle > 90 && angle < 270 ? -1 : 1;

	i = 0;
    //printf("\t- angle:%f\n", angle);
	xa = ABS(FRAME / tan(deg_to_rad(angle)));
    printf("\t- xa:%i\n", xa);
    trans_hori(cam, angle, &x, &y);
    printf("\t- camX:%i -> %f\n", cam->x, (double)cam->x/64+1);
    printf("\t- camY:%i -> %f\n", cam->y, (double)cam->y/64+1);
	while (y >= 0 && y / 64 < ft_strlen_len(map) && x >= 0
		&& x / 64 < (int)ft_strlen(map[0]) && !check_wall(x, y, map))
	{
        printf("\t%zu:\n\t\t- x:%3i\n\t\t- y:%3i\n\t\t- map:%c\n", i, x, y, map[y/64][x/64]);
		++i;
		x += x_oriented * xa;
		y += y_oriented * 64;
	}
	if (y >= 0 && y / 64 < ft_strlen_len(map)
		&& x / 64 < (int)ft_strlen(map[0]) && check_wall(x, y, map))
        printf("\t%zu:\n\t\t- x:%3i\n\t\t- y:%3i\n\t\t- map:%c\n", i, x, y, map[y/64][x/64]);
    else
        printf("\t%zu:\n\t\t- x:%3i\n\t\t- y:%3i\n\t\t- map:%c\n", i, x, y, 'N');
    printf("\t- x1:%i\n", x/64 + 1);
    printf("\t- y1:%i\n", y/64 + 1);
    //printf("\t- distX:%i\n", cam->x - x);
    //printf("\t- distY:%i\n", cam->y - y);
    //printf("\t- iter:%i\n", i);
	return ((size_t)hypot(x - cam->x, y - cam->y));
}

size_t	dist_vertical(t_cam *cam, char **map, double angle, int8_t x_oriented)
{
	int32_t	ya;
	int32_t	y;
	int32_t	x;
	size_t	i;
    int     y_oriented = angle > 0 && angle < 180 ? -1 : 1;

	i = 0;
    //printf("\t- angle:%f\n", angle);
	ya = ABS(FRAME * tan(deg_to_rad(angle)));
    trans_vert(cam, angle, &x, &y);
    printf("\t- ya:%i\n", ya);
    printf("\t- camX:%i -> %f\n", cam->x, (double)cam->x/64+1);
    printf("\t- xamY:%i -> %f\n", cam->y, (double)cam->y/64+1);
	while (y >= 0 && y / 64 < ft_strlen_len(map) && x >= 0
		&& x / 64 < (int)ft_strlen(map[0]) && !check_wall(x, y, map))
	{
        printf("\t%zu:\n\t\t- x:%3i\n\t\t- y:%3i\n\t\t- map:%c\n", i, x, y, map[y/64][x/64]);
		++i;
		y += y_oriented * ya;
		x += x_oriented * 64;
	}
	if (y >= 0 && y / 64 < ft_strlen_len(map)
		&& x / 64 < (int)ft_strlen(map[0]) && check_wall(x, y, map))
        printf("\t%zu:\n\t\t- x:%3i\n\t\t- y:%3i\n\t\t- map:%c\n", i, x, y, map[y/64][x/64]);
    else
        printf("\t%zu:\n\t\t- x:%3i\n\t\t- y:%3i\n\t\t- map:%c\n", i, x, y, 'N');
    printf("\t- x1:%i\n", x/64 + 1);
    printf("\t- y1:%i\n", y/64 + 1);
    //printf("\t- distX:%i\n", cam->x - x);
    //printf("\t- distY:%i\n", cam->y - y);
    //printf("\t- iter:%i\n", i);
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
    printf("angle: %f\n", angle);
    printf("distH:\n");
	dist_h = dist_horizontal(cam, map, angle, oriented) * TRUE_DIST;
    printf("\t- end:%zu\n", dist_h);
	oriented = angle > 90 && angle < 270 ? -1 : 1;
    printf("distV:\n");
	dist_v = dist_vertical(cam, map, angle, oriented) * TRUE_DIST;
    printf("\t- end:%zu\n", dist_v);
	return (dist_h < dist_v ? dist_h : dist_v);
}

void	raycasting(t_win *win, t_cam *cam, char **map)
{
	size_t	column;
	size_t	size_wall;

	column = 0;
    printf("----------%f----------\n", ANGLE(cam->orientation, (double)column));
    printf("camX:%i\ncamY:%i\n", cam->x, cam->y);
	while (column < WIDTH)
	{
		size_wall = DIST_SCREEN * FRAME / find_dist_wall(cam, map, column);
        printf("%zu -- %zu\n", size_wall, column);
		print_column(win, size_wall, column);
		++column;
	}
}
