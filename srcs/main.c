#include "wolf3d.h"
#include "mlx.h"
#include "libft.h"


#include <stdio.h>

static void	waiting_instruction(t_win *win)
{
	mlx_hook(WIN_PTR, 2, 0, deal_key, win);
	mlx_loop(MLX_PTR);
}

int			main(int argc, char **argv)
{
	t_win	win;
	char	**map;
	t_cam	cam;

	map = parsing(read_file(argc, argv));
	/*ft_print_tab(map);//print temporaire
	ft_tabdel_char(&map);//free temporaire*/
	init_mlx(&win);
	cam = init_cam(map);
	raycasting(&win, cam, map);
	put_image(&win);
	waiting_instruction(&win);
	return (0);
}
