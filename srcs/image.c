#include "mlx.h"
#include "wolf3d.h"

void	clear_window(t_win *win)
{
	if (IMG_PTR)
		mlx_destroy_image(MLX_PTR, IMG_PTR);
	mlx_clear_window(MLX_PTR, WIN_PTR);
}

void	new_image(t_win *win)
{
	clear_window(win);
	IMG_PTR = mlx_new_image(MLX_PTR, WIDTH, HEIGHT);
	IMG_STR = mlx_get_data_addr(IMG_PTR, &(BPP), &(S_L), &(ENDIAN));
}

void	put_image(t_win *win)
{
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
}
