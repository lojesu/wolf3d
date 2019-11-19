#include "wolf3d.h"
#include <libft.h>
#include <math.h>
#include <libmath.h>

#define CELL_SIZE 32
#define FOV_SIZE (CELL_SIZE / 3.5)

#define BMAP_POS 40
#define BMAP_WIDTH ((WIDTH - BMAP_POS)/(CELL_SIZE+1) - BMAP_POS/(CELL_SIZE+1))
#define BMAP_WPOS1 (int)((BMAP_WIDTH - ft_strlen(map[0]))/2)
#define BMAP_WPOS (BMAP_WPOS1 > 0 ? BMAP_WPOS1 : 0)
#define BMAP_HEIGHT ((HEIGHT - BMAP_POS)/(CELL_SIZE+1) - BMAP_POS/(CELL_SIZE+1))
#define BMAP_HPOS1 (int)((BMAP_HEIGHT - ft_strlen_len(map))/2)
#define BMAP_HPOS (BMAP_HPOS1 > 0 ? BMAP_HPOS1 : 0)
#define BMAP_WPLAYER(a) ((double)((double)a) * CELL_SIZE / FRAME + BMAP_WPOS * CELL_SIZE + BMAP_POS - cam->bmapx * CELL_SIZE)
#define BMAP_HPLAYER(a) ((double)((double)a) * CELL_SIZE / FRAME + BMAP_HPOS * CELL_SIZE + BMAP_POS - cam->bmapy * CELL_SIZE)

int      give_color(char **map, int x, int y)
{
    char    id;

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

void    put_fov(t_win *win, t_cam *cam, int x, int y)
{
    size_t i;
    int angle;
    double p0[2];
    double p1[2];

    i = 0;
    while (i <  100)
    {
        p0[0] = cos(deg_to_rad(cam->orientation)) * FOV_SIZE + x;
        p0[1] = -sin(deg_to_rad(cam->orientation)) * FOV_SIZE + y;
        angle = cam->orientation + i - 50;
        angle = angle > 360 ? angle - 360 : angle;
        angle = angle < 0 ? angle + 360 : angle;
        p1[0] = -cos(deg_to_rad(angle)) * FOV_SIZE + x;
        p1[1] = sin(deg_to_rad(angle)) * FOV_SIZE + y;
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

bool    is_out(t_cam *cam, char **map)
{
    return (cam->x - cam->bmapx * FRAME < 0 ||
                    cam->x - cam->bmapx * FRAME > ft_strlen(map[0]) * FRAME ||
                    cam->y - cam->bmapy * FRAME < 0 ||
                    cam->y - cam->bmapy * FRAME > ft_strlen_len(map) * FRAME);
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
                    give_color(map, (x + cam->bmapx) * FRAME,
                            (y + cam->bmapy) * FRAME));
                ++x;
            }
            ++y;
    }
    if (!is_out(cam, map))
        put_fov(win, cam, BMAP_WPLAYER(cam->x), BMAP_HPLAYER(cam->y));
}
