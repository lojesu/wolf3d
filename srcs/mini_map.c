#include "wolf3d.h"
#include <libft.h>
#include <math.h>

#define CELL_SIZE 32
#define CELL_NB 3
#define PLAYER_SIZE (CELL_SIZE / 4 + 2)
#define MAP_POS 15
#define MAP_SIZE ((CELL_SIZE + 1) * (CELL_NB * 2 + 1) - CELL_NB * 2)
#define CALC(a, b) (a + b * FRAME/CELL_SIZE - CELL_NB* 64 - 32)

int      give_color(char **map, int x, int y, t_cam *cam)
{
    char id;

    if (y < 0 || y / 64 >= ft_strlen_len(map) ||
                    x < 0 || x / 64 >= ft_strlen(map[0]))
        id = 'X';
    else
        id = map[y / 64][x / 64];
    if (id == '1')
        return (0xff0044);
    else if (id == '0')
        return (0xc8c8c8);
    else if (id == '9')
        return (0xffff00);
    else if (id == '8')
        return (0x66ff33);
    else if (id == '2')
        return (0x800000);
    else if (id == '3')
        return (0x993333);
    else if (id == '4')
        return (0x996633);
    else if (id == '5')
        return (0x663300);
    else
        return (0x0);
}

void     outline_mini_map(t_win *win, int x_center, int y_center)
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
/*
void outline_mini_map(t_win *win)
{
    int x;
    int y;

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
*/
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

void    print_mini_map(t_cam *cam, char **map, t_win *win)
{
    int x;
    int xi;
    int y;
    int yi;

    y = 0;
    yi = 0;
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
            if (in_circle(x + MAP_POS, y + MAP_POS))
                put_pixel(win, x + MAP_POS, y + MAP_POS,
                    give_color(map, CALC(cam->x, x),
                        CALC(cam->y, y), cam));
            xi = CALC(cam->x, x);
            ++x;
        }
        yi = CALC(cam->y, y);
        ++y;
    }
    put_player(win);
    outline_mini_map(win, MAP_POS + (MAP_SIZE) / 2, MAP_POS + (MAP_SIZE) / 2);
}