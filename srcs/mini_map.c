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
#define FOV_SIZE (CELL_SIZE / 3.5)

#define BMAP_POS 40
#define BMAP_WIDTH ((WIDTH - BMAP_POS)/(CELL_SIZE+1) - BMAP_POS/(CELL_SIZE+1))
#define BMAP_WPOS1 (int)((BMAP_WIDTH - ft_strlen(map[0]))/2)
#define BMAP_WPOS (BMAP_WPOS1 > 0 ? BMAP_WPOS1 : 0)
#define BMAP_HEIGHT ((HEIGHT - BMAP_POS)/(CELL_SIZE+1) - BMAP_POS/(CELL_SIZE+1))
#define BMAP_HPOS1 (int)((BMAP_HEIGHT - ft_strlen_len(map))/2)
#define BMAP_HPOS (BMAP_HPOS1 > 0 ? BMAP_HPOS1 : 0)
#define BMAP_PLAYER(a) ((double)a / FRAME * CELL_SIZE + BMAP_POS)

int      give_color(char **map, int x, int y)
{
    char id;

    if (y < 0 || y / 64 >= ft_strlen_len(map) ||
                    x < 0 || x / 64 >= ft_strlen(map[0]))
        return (0x0);
    else
        id = map[y / 64][x / 64];
    if (id == '0')
        return (0xc8c8c8);
    else if (id == '1')
        return (0xff0044);
    else if (id == '2')
        return (0xff5050);
    else if (id == '3')
        return (0x6600ff);
    else if (id == '6')
        return (0x00ccff);
    else if (id == '7')
        return (0x9933ff);
    else if (id == '8')
        return (0x66ff33);
    else if (id == '9')
        return (0xffff00);
    else if (id == 'R')
        return (0x800000);
    else if (id == 'L')
        return (0x993333);
    else if (id == 'D')
        return (0x996633);
    else if (id == 'U')
        return (0x663300);
    else
        return (0x0);
}

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

void put_player(t_win *win)
{
        int y;
        int x;

        y = 0;
        while (y < PLAYER_SIZE)
        {
            x = 0;
            while (x < PLAYER_SIZE)
            {
                put_pixel(win,
                    MAP_SIZE / 2 - PLAYER_SIZE / 2 + MAP_POS + x + 1,
                    MAP_SIZE / 2 - PLAYER_SIZE / 2 + MAP_POS + y + 1,
                    0x059905);
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

void    put_fov(t_win *win, int orientation, t_cam *cam)
{
    size_t i;
    int angle;
    double p0[2];
    double p1[2];

    i = 0;
    while (i <  100)
    {
        p0[0] = cos(deg_to_rad(orientation)) * FOV_SIZE + (cam->map == 1 ? BMAP_PLAYER(cam->x) : PLAYER);
        p0[1] = -sin(deg_to_rad(orientation)) * FOV_SIZE + (cam->map == 1 ? BMAP_PLAYER(cam->y) : PLAYER);
        angle = orientation + i - 50;
        angle = angle > 360 ? angle - 360 : angle;
        angle = angle < 0 ? angle + 360 : angle;
        p1[0] = -cos(deg_to_rad(angle)) * FOV_SIZE + (cam->map == 1 ? BMAP_PLAYER(cam->x): PLAYER);
        p1[1] = sin(deg_to_rad(angle)) * FOV_SIZE + (cam->map == 1 ? BMAP_PLAYER(cam->y): PLAYER);
        bresenham(win, p0, p1);
        ++i;
    }
}

void    put_cell(t_win *win, int x, int y, int color)
{
    int xi;
    int yi;

    yi = y;
    while (yi < y + CELL_SIZE)
    {
        xi = x;
        while (xi < x + CELL_SIZE)
        {
            put_pixel(win, xi, yi, color);
            ++xi;
        }
        ++yi;
    }
    xi = x;
    yi = y;
}

void    big_map(t_win *win, t_cam *cam, char **map)
{
    int x;
    int y;

    y = 0;
    while (y < BMAP_HEIGHT - BMAP_HPOS * 2)
    {
            x = 0;
            while (x < BMAP_WIDTH - BMAP_WPOS * 2)
            {
                put_cell(win,
                        x * (CELL_SIZE + 1) + BMAP_WPOS * CELL_SIZE + BMAP_POS,
                        y * (CELL_SIZE + 1) + BMAP_HPOS * CELL_SIZE + BMAP_POS,
                    give_color(map, (x + cam->bmapx) * 64, (y + cam->bmapy) * 64));
                ++x;
            }
            ++y;
    }
    put_fov(win, cam->orientation, cam);
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
    put_fov(win, cam->orientation, cam);
}
