#include "mlx.h"
#include "wolf3d.h"
#include <stdlib.h>
#include <libft.h>

void	quit_window(t_env *env)
{
	t_win *win;

	win = &env->win;
	clear_window(win);
	mlx_destroy_window(MLX_PTR, WIN_PTR);
	ft_tabdel_char(&env->map);
	exit(1);
}

void	clear_window(t_win *win)
{
	if (IMG_PTR)
		mlx_destroy_image(MLX_PTR, IMG_PTR);
	mlx_clear_window(MLX_PTR, WIN_PTR);
}

void	new_image(t_win *win)
{
	IMG_PTR = mlx_new_image(MLX_PTR, WIDTH, HEIGHT);
	IMG_STR = mlx_get_data_addr(IMG_PTR, &(BPP), &(S_L), &(ENDIAN));
}

void	put_image(t_win *win)
{
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
}
