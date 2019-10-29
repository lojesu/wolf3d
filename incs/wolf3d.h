#ifndef WOLF3D_H
# define WOLF3D_H

# define WIDTH 640
# define HEIGHT 480

# define DIST_SCREEN (int)((WIDTH / 2) / tan(deg_to_rad(30)))
# define FRAME 64
# define CAM_HIGH WALL_SIZE / 2
# define VISUAL_FIELD 60

# define MLX_PTR win->mlx_ptr
# define WIN_PTR win->win_ptr
# define IMG_PTR win->img_ptr
# define IMG_STR win->img_str
# define BPP win->bpp
# define S_L win->s_l
# define ENDIAN win->endian

# include <stddef.h>
# include <stdint.h>

typedef	struct	s_cam
{
	int32_t		x;
	int32_t		y;
	int32_t		orientation;

}				t_cam;

typedef	struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_str;
	int		bpp;
	int		s_l;
	int		endian;
}				t_win;

/*
** initialisation functions
*/
void		init_mlx(t_win *win);
t_cam		init_cam(char **map);

/*
** image management functions
*/
void		new_image(t_win *win);
void		put_image(t_win *win);
void		clear_window(t_win *win);

/*
** functions that manage keys on the keyboard
*/
int			deal_key(int key, t_win *win);

/*
** parsing functions
*/
char	*read_file(int argc, char**argv);
char	**parsing(char *map_read);

/*
** raycasting functions
*/
void	raycasting(t_win *win, t_cam cam, char **map);

/*
** print functions
*/
void	print_column(t_win *win, size_t	size_wall, size_t column);
void	put_pixel(t_win *win, size_t x, size_t y, int color);

#endif
