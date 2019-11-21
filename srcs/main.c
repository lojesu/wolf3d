#include "wolf3d.h"
#include "mlx.h"
#include "libft.h"

static int	exit_mouse(t_env *env)
{
	quit_window(env);
	return (0);
}

static void	waiting_instruction(t_env *env)
{
	t_win	*win;

	win = &(env->win);
	mlx_hook(WIN_PTR, 2, 0, deal_key, env);
	mlx_hook(WIN_PTR, 17, 0, exit_mouse, env);
	mlx_loop_hook(MLX_PTR, is_special_bloc, env);
	mlx_loop(MLX_PTR);
}

int			main(int argc, char **argv)
{
	t_env	env;

	env.map = parsing(read_file(argc, argv));
	launch_texture(&env);
	init_mlx(&(env.win));
	env.cam = init_cam(env.map);
	raycasting(&env);
	put_image(&(env.win));
	waiting_instruction(&env);
	return (0);
}
