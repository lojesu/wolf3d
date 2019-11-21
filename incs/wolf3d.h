#ifndef WOLF3D_H
# define WOLF3D_H

# define WIDTH 1333
# define HEIGHT 1000

# define DIST_SCREEN (int)((WIDTH / 2) / tan(deg_to_rad(30)))
# define TRUE_DIST (cos(deg_to_rad(((double)column) * VISUAL_FIELD / WIDTH - 30)))
# define ABS(x) (x < 0 ? -x : x)

# define VISUAL_FIELD 60
# define FRAME 64
# define CAM_HIGH WALL_SIZE / 2

# define MLX_PTR win->mlx_ptr
# define WIN_PTR win->win_ptr
# define IMG_PTR win->img_ptr
# define IMG_STR win->img_str
# define BPP win->bpp
# define S_L win->s_l
# define ENDIAN win->endian

# define BMP_SIDE 64
# define BMP_SIZE (BMP_SIDE * BMP_SIDE)
# define BMP_NB 8

# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>

enum            e_side
{
        SIDE_RIGHT = 1,
        SIDE_LEFT = 2,
        SIDE_UP = 3,
        SIDE_DOWN = 4,
};

typedef	struct	s_cam
{
	int32_t		x;
	int32_t		y;
	int32_t		orientation;
        int32_t         angle;
        int32_t         bmapx;
        int32_t         bmapy;
        uint8_t         mini_map:2;
        uint8_t         map:1;
        bool            lock;
        bool            button;

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

typedef	struct	s_env
{
	t_win	win;
	t_cam	cam;
	char	**map;
        int     bmp[BMP_NB][BMP_SIZE];
}				t_env;

typedef struct  s_wall
{
        double x;
        double y;
        double dist;
        enum e_side side;
}               t_wall;

/*
** initialisation functions
*/
void		init_mlx(t_win *win);
t_cam		init_cam(char **map);

/*
** image/window management functions
*/
void		new_image(t_win *win);
void		put_image(t_win *win);
void		clear_window(t_win *win);
void		quit_window(t_env *env);

/*
** parsing functions
*/
char	*read_file(int argc, char**argv);
char	**parsing(char *map_read);
void    launch_texture(t_env *env);

/*
** raycasting functions
*/
bool    check_wall(double x, double y, char **map);
void	raycasting(t_env *env);
void    trans_hori(t_cam *cam, double angle, double *x, double *y);
void    trans_vert(t_cam *cam, double angle, double *x, double *y);

/*
** special bloc functions
*/
bool	special_bloc(t_env *env);
int	is_special_bloc(t_env *env);

/*
** print functions
*/
void	print_column(t_win *win, int size_wall, size_t column, t_cam *cam);
void	put_pixel(t_win *win, size_t x, size_t y, int color);
void    print_mini_map(t_env *env);
void    print(t_env *env, t_wall wall, size_t column);

/*
** event functions
*/
int			deal_key(int key, t_env *env);
void			event_reset(t_env *env);

/*
** tool funtion
*/
void            my_intcpy(int *dst, int *src, int size);

#endif
