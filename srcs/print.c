#include "wolf3d.h"
#include <libft.h>
#include <math.h>
#include <libmath.h>

void    wich_bmp(enum e_side side, int my_bmp[BMP_SIZE], int bmp[BMP_NB][BMP_SIZE])
{
    if (side == SIDE_RIGHT)
    my_intcpy(my_bmp, bmp[0], BMP_SIZE);
    else if (side == SIDE_LEFT)
    my_intcpy(my_bmp, bmp[1], BMP_SIZE);
    else if (side == SIDE_UP)
    my_intcpy(my_bmp, bmp[2], BMP_SIZE);
    else
    my_intcpy(my_bmp, bmp[3], BMP_SIZE);
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

    size_wall = DIST_SCREEN * FRAME / wall.dist;
	int start = HEIGHT / 2 - size_wall / 2 + (&env->cam)->angle;
    wich_bmp(wall.side, my_bmp, env->bmp);
    pos = wall.side == SIDE_UP || wall.side == SIDE_DOWN ?
            fmod(wall.x, 64) : fmod(wall.y, 64);
    ratio = (double)BMP_SIDE / (double)size_wall;
    printf("%i %i %i\n", start, size_wall, ratio);
    z = 0;
    i = 0;
    if (start < 0)
        z = ratio * -start;
	while (i < start && i < HEIGHT)
	{
		put_pixel(win, column, i, 0x0068d1);
		i++;
	}
	while (i < start + size_wall && i < HEIGHT)
    {
        put_pixel(win, column, i, my_bmp[pos + BMP_SIZE - (int)(z + 1) * BMP_SIDE]);
        ++i;
        z += ratio;
    }
	while (i < HEIGHT)
	{
		put_pixel(win, column, i, 0x797171);
		i++;
	}
}
