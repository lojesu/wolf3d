#include "wolf3d.h"
#include <stdlib.h>
#include "mlx.h"

int		deal_key(int key, t_win *win)
{
	if (key == 53)
	{
		clear_window(win);
		mlx_destroy_window(MLX_PTR, WIN_PTR);
		exit(1);
	}
	return (0);
}
