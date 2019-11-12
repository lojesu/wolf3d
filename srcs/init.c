#include "mlx.h"
#include "wolf3d.h"

#include <stdio.h>
#include "libft.h"
static void	where_is_the_spawn(int32_t *x, int32_t *y, char **map)
{
	*y = 0;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (map[*y][*x] == '9')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

t_cam		init_cam(char **map)
{
	t_cam	ret;
	int32_t	x;
	int32_t	y;

	where_is_the_spawn(&x, &y, map);
	ret.x = x * FRAME + FRAME/2;
	ret.y = y * FRAME + FRAME/2;
	ret.orientation = 157;
	return (ret);
}

void		init_mlx(t_win *win)
{
	MLX_PTR = mlx_init();
    WIN_PTR = mlx_new_window(MLX_PTR, WIDTH, HEIGHT, "wolf3d");
	new_image(win);
}
