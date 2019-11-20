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

# define ESC 53
# define FORWARD 13
# define BACKWARD 1
# define LEFT 0
# define RIGHT 2
# define L_ROTATION 123
# define R_ROTATION 124
# define UP 126
# define DOWN 125
# define TAB 48
# define RESET 15
# define MAP 46
# define UP_MAP 91
# define DOWN_MAP 87
# define LEFT_MAP 86
# define RIGHT_MAP 88

# define BMP_SIDE 64
# define BMP_SIZE (BMP_SIDE * BMP_SIDE)
# define BMP_NB 4

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
void            quit_window(t_win *win, char **map);

/*
** functions that manage keys on the keyboard
*/
int			deal_key(int key, t_env *env);
void                    move(int key, t_env *env);

/*
** parsing functions
*/
char	*read_file(int argc, char**argv);
char	**parsing(char *map_read);
void    launch_texture(t_env *env);

/*
** raycasting functions
*/
void	raycasting(t_env *env);
void    pre_raycasting(t_env *env);
bool    check_wall(double x, double y, char **map);
void    trans_hori(t_cam *cam, double angle, double *x, double *y);
void    trans_vert(t_cam *cam, double angle, double *x, double *y);

/*
** SpeedWalk functions
*/
bool    special_bloc(t_env *env);

/*
** Mini Map functions
*/
int     give_color(char **map, int x, int y);
void    outline_mini_map(t_win *win, int type);
void    put_player(t_win *win);
void    bresenham(t_win *win, double p1[2], double p2[2]);
void    big_map(t_win *win, t_cam *cam, char **map);
void    put_fov(t_win *win, t_cam *cam, int x, int y);

/*
** print functions
*/
void	print_column(t_win *win, int size_wall, size_t column, t_cam *cam);
void	put_pixel(t_win *win, size_t x, size_t y, int color);
void    print_mini_map(t_cam *cam, char **map, t_win *win);
void    print(t_env *env, t_wall wall, size_t column);


void            my_intcpy(int *dst, int *src, int size); // del

#endif
