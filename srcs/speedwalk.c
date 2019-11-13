#include "wolf3d.h"
#include "libft.h"

#define SPEED 2

bool    special_bloc(t_win *win, t_cam *cam, char **map)
{
    if (cam->y < 0 || cam->y / 64 >= ft_strlen_len(map) ||
        cam->x < 0 || cam->x / 64 >= ft_strlen(map[0]))
        quit_window(win, map);
    put_image(win);
    if (map[cam->y / 64][cam->x / 64] == '2')
    {
        cam->x += map[cam->y / 64][(cam->x + SPEED + 1) / 64] == '1' ? 0 : SPEED;
        cam->x += cam->x % 64 < SPEED * 2 ? SPEED * 2 : 0;
        cam->lock = true;
    }
    else if (map[cam->y / 64][cam->x / 64] == '3')
    {
        cam->x -= map[cam->y / 64][(cam->x - SPEED - 1) / 64] == '1' ? 0 : SPEED;
        cam->x -= cam->x % 64 < SPEED * 2 ? SPEED * 2 : 0;
        cam->lock = true;
    }
    else if (map[cam->y / 64][cam->x / 64] == '4')
    {
        cam->y += map[(cam->y + SPEED + 1) / 64][cam->x / 64] == '1' ? 0 : SPEED;
        cam->y += cam->y % 64 < SPEED * 2 ? SPEED * 2 : 0;
        cam->lock = true;
    }
    else if (map[cam->y / 64][cam->x / 64] == '5')
    {
        cam->y -= map[(cam->y - SPEED - 1) / 64][cam->x / 64] == '1' ? 0 : SPEED;
        cam->y -= cam->y % 64 < SPEED * 2 ? SPEED * 2 : 0;
        cam->lock = true;
    }
    else
    {
        cam->lock = false;
        return (false);
    }
    return (true);
}

void    pre_raycasting(t_env *env)
{
    if (special_bloc(&env->win, &env->cam, env->map))
        raycasting(&env->win, &env->cam, env->map);
}

