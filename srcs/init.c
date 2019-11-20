#include "mlx.h"
#include "wolf3d.h"

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

static bool is_there_seven(char **map)
{
        int x;
        int y;

        y = 0;
        while (map[y])
        {
            x = 0;
            while (map[y][x])
            {
                if (map[y][x] == '7')
                    return (false);
                ++x;
            }
            ++y;
        }
        return (true);
}

t_cam		init_cam(char **map)
{
	t_cam	ret;
	int32_t	x;
	int32_t	y;

	where_is_the_spawn(&x, &y, map);
	ret.x = x * FRAME + FRAME / 2;
	ret.y = y * FRAME + FRAME / 2;
	ret.orientation = 0;
    ret.angle = 0;
    ret.lock = false;
    ret.mini_map = 1;
    ret.map = 0;
    ret.bmapx = 0;
    ret.bmapy = 0;
    ret.button = is_there_seven(map);
	return (ret);
}

void		init_mlx(t_win *win)
{
	MLX_PTR = mlx_init();
    WIN_PTR = mlx_new_window(MLX_PTR, WIDTH, HEIGHT, "wolf3d");
	new_image(win);
}
