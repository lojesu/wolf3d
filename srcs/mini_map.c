#include "wolf3d.h"
#include <libft.h>
#define CELL_SIZE 16
#define CELL_NB 3
#define PLAYER_SIZE (CELL_SIZE / 4 + 2)
#define MAP_POS 15
#define MAP_SIZE ((CELL_SIZE + 1) * (CELL_NB * 2 + 1) - CELL_NB * 2)
#define CALC(a, b) (a + b * 4 - CELL_NB* 64 - 32)

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
