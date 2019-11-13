#include "wolf3d.h"
#include <libft.h>
#define CELL_SIZE 16
#define CELL_NB 3
#define PLAYER_SIZE (CELL_SIZE / 4 + 2)
#define MAP_POS 15
#define MAP_SIZE ((CELL_SIZE + 1) * (CELL_NB * 2 + 1) - CELL_NB * 2)
#define CALC(a, b) (a + b * 4 - CELL_NB* 64 - 32)

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
