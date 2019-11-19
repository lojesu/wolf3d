#include "wolf3d.h"
#include <libft.h>
#include <math.h>
#include <libmath.h>

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

void    wich_bmp(enum e_side side, int my_bmp[BMP_SIZE], int bmp[BMP_NB][BMP_SIZE])
{
    if (side == SIDE_RIGHT)
    my_intcpy(my_bmp, bmp[0], 4096);
    else if (side == SIDE_LEFT)
    my_intcpy(my_bmp, bmp[1], 4096);
    else if (side == SIDE_UP)
    my_intcpy(my_bmp, bmp[2], 4096);
    else
    my_intcpy(my_bmp, bmp[3], 4096);
}

void    print(t_env *env, t_wall wall, size_t column)
{
    int size_wall;
    int pos;
    int my_bmp[BMP_SIZE];
    double z;
    double ratio;
    int i;
    t_win *win = &env->win;

	int start = HEIGHT / 2 - size_wall / 2 + (&env->cam)->angle;
    wich_bmp(wall.side, my_bmp, env->bmp);
    size_wall = DIST_SCREEN * FRAME / wall.dist;
    pos = wall.side == SIDE_UP || wall.side == SIDE_DOWN ?
            fmod(wall.x, 64) : fmod(wall.y, 64);
    ratio = (double)FRAME / (double)size_wall;
    z = 0;
    i = 0;
    if (start < 0)
        z = ratio * -start;
	while (i < start && i < HEIGHT)
	{
		put_pixel(win, column, i, 0x454545);
		i++;
	}
	while (i < start + size_wall && i < HEIGHT)
    {
        put_pixel(win, column, i, my_bmp[pos + 4096 - (int)(z + 1) * 64]);
        ++i;
        z += ratio;
    }
	while (i < HEIGHT)
	{
		put_pixel(win, column, i, 0xc8c8c8);
		i++;
	}
}
