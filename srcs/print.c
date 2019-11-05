#include "wolf3d.h"

void	print_column(t_win *win, size_t size_wall, size_t column)
{
	size_t	start;
	size_t	i;

	start = HEIGHT / 2 - size_wall / 2;
	i = 0;
	while (i < start)
	{
		put_pixel(win, column, i, 0x000069);
		i++;
	}
	while (i < start + size_wall)
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
