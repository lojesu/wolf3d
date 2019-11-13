#include "wolf3d.h"
#include <libft.h>
#define CELL_SIZE 16
#define CELL_NB 3
#define PLAYER_SIZE (CELL_SIZE / 4 + 2)
#define MAP_POS 15
#define MAP_SIZE ((CELL_SIZE + 1) * (CELL_NB * 2 + 1) - CELL_NB * 2)
#define CALC(a, b) (a + b * 4 - CELL_NB* 64 - 32)

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
