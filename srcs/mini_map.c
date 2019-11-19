#include "wolf3d.h"
#include <libft.h>
#include <math.h>
#include <libmath.h>

#define CELL_SIZE 32
#define CELL_NB 3
#define PLAYER_SIZE (CELL_SIZE / 4 + 2)
#define PLAYER (MAP_SIZE / 2 - PLAYER_SIZE / 2 + MAP_POS + 1 + PLAYER_SIZE / 2)
#define MAP_POS 15
#define MAP_SIZE ((CELL_SIZE + 1) * (CELL_NB * 2 + 1) - CELL_NB * 2)
#define CALC(a, b) (a + b * FRAME/CELL_SIZE - CELL_NB* 64 - 32)

void     outline_mini_map_circle(t_win *win, int x_center, int y_center)
{
    size_t x;
    size_t y;
    int m;

	x = 0;
	y = (CELL_SIZE + 1) * CELL_NB + CELL_NB;
	m = 5 - 4 * y;
	while (x <= y)
    {
		put_pixel(win,  x + x_center, y + y_center, 0xffffff);
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

void outline_mini_map(t_win *win, int type)
{
    int x;
    int y;

    if (type == 1)
        return (outline_mini_map_circle(win, MAP_POS + (MAP_SIZE) / 2,
                        MAP_POS + (MAP_SIZE) / 2));
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

bool    in_circle(int x, int y)
{
        int rayon;
        int center;

        rayon = (CELL_SIZE + 1) * CELL_NB + CELL_NB;
        center = MAP_POS + (MAP_SIZE) / 2;
        return (hypot(ABS((x - center)), ABS((y - center))) < rayon);
}

void    print_mini_map(t_cam *cam, char **map, t_win *win)
{
    int x;
    int xi;
    int y;
    int yi;

    y = 0;
    yi = 0;
    if (cam->map == 1)
            return (big_map(win, cam, map));
    else if (cam->mini_map == 0)
            return ;
    while (y < MAP_SIZE)
    {
        if (CALC(cam->y, y) / 64 > yi / 64)
        {
                yi = CALC(cam->y, y);
                ++y;
                continue ;
        }
        x = 0;
        xi = 0;
        while (x < MAP_SIZE)
        {
            if (CALC(cam->x, x) / 64 > xi / 64)
            {
                xi = CALC(cam->x, x);
                ++x;
                continue ;
            }
            if (in_circle(x + MAP_POS, y + MAP_POS) || cam->mini_map == 2)
                put_pixel(win, x + MAP_POS, y + MAP_POS,
                    give_color(map, CALC(cam->x, x),
                        CALC(cam->y, y)));
            xi = CALC(cam->x, x);
            ++x;
        }
        yi = CALC(cam->y, y);
        ++y;
    }
    outline_mini_map(win, cam->mini_map);
    put_fov(win, cam, PLAYER, PLAYER);
}
