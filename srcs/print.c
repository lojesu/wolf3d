#include "wolf3d.h"
#include <libft.h>
#define CELL_SIZE 16
#define PLAYER_SIZE (CELL_SIZE / 4 + 2)
#define CELL_NB 3
#define MAP_POS 15

static void     put_cell(t_win *win, int x, int y, int color)
{
        int a;
        int b;

        a = 0;
        while (a < CELL_SIZE)
        {
            b = 0;
            while (b < CELL_SIZE)
            {
                put_pixel(win, x * (CELL_SIZE + 1) + b + MAP_POS,
                                y * (CELL_SIZE + 1) + a + MAP_POS, color);
                ++b;
            }
            ++a;
        }
}

static int      give_color(char **map, int x, int y, t_cam *cam)
{
    char id;

    if (y < 0 || y >= ft_strlen_len(map) || x < 0 || x >= ft_strlen(map[0]))
        id = 'X';
    else
        id = map[y][x];
    if (id == '1')
        return (0xff0044);
    else if (id == '0')
        return (0xc8c8c8);
    else if (id == '9')
        return (0xffff00);
    else
        return (0x0);
}

static void outline_mini_map(t_win *win)
{
    int x;
    int y;

    y = MAP_POS - 2;
    while (y < MAP_POS + (CELL_SIZE + 1) * (CELL_NB * 2 + 1) + 1)
    {
        x = MAP_POS - 2;
        while (x < MAP_POS + (CELL_SIZE + 1) * (CELL_NB * 2 + 1) + 1)
        {
            if (x < MAP_POS || x >= MAP_POS + (CELL_SIZE + 1) * (CELL_NB * 2 + 1) - 1 ||
                            y < MAP_POS || y >= MAP_POS + (CELL_SIZE + 1) * (CELL_NB * 2 + 1) - 1)
                put_pixel(win, x, y, 0xffffff);
            ++x;
        }
        ++y;
    }
}

static void put_player(t_win *win)
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
                    CELL_NB * (CELL_SIZE + 1) + CELL_SIZE / 2 + x - PLAYER_SIZE / 2 + MAP_POS,
                    CELL_NB * (CELL_SIZE + 1) + CELL_SIZE / 2 + y - PLAYER_SIZE / 2 + MAP_POS,
                    0x059905);
                ++x;
            }
            ++y;
        }
}

void    print_mini_map(t_cam *cam, char **map, t_win *win)
{
    int x;
    int y;

    y = 0;
    while (y < CELL_NB * 2 + 1)
    {
        x = 0;
        while (x < CELL_NB * 2 + 1)
        {
            put_cell(win, x, y,
                give_color(map, cam->x / 64 + x - CELL_NB,
                    cam->y / 64 + y - CELL_NB, cam));
            ++x;
        }
        ++y;
    }
    put_player(win);
    outline_mini_map(win);
}

void	print_column(t_win *win, int size_wall, size_t column, t_cam *cam)
{
	int 	start;
	int 	i;

	start = HEIGHT / 2 - size_wall / 2 + cam->angle;
	i = 0;
	while (i < start && i < HEIGHT)
	{
		put_pixel(win, column, i, 0x454545);
		i++;
	}
	while (i < start + size_wall && i < HEIGHT)
	{
		put_pixel(win, column, i, 0xff0044);
		i++;
	}
	while (i < HEIGHT)
	{
		put_pixel(win, column, i, 0xc8c8c8);
		i++;
	}
}
