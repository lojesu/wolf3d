#include "wolf3d.h"

void	print_column(t_win *win, size_t size_wall, size_t column)
{
	size_t	start;
	size_t	i;

	start = HEIGHT / 2 - size_wall / 2;
	i = 0;
	while (i < size_wall)
	{
		put_pixel(win, column, start + i, 0xff0000);
		i++;
	}
}
