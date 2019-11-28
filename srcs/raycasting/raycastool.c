/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:10:51 by glegendr          #+#    #+#             */
/*   Updated: 2019/11/28 18:10:52 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libmath.h"
#include "libft.h"
#include <math.h>

void	trans_vert(t_cam *cam, double angle, double *x, double *y)
{
	if (angle > 90 && angle < 270)
	{
		*x = cam->x / 64 * 64;
		*y = cam->y + tan(deg_to_rad(angle - 180)) * ABS((cam->x - *x));
	}
	else if (angle < 90)
	{
		*x = cam->x / 64 * 64 + 64;
		*y = cam->y - tan(deg_to_rad(angle)) * ABS((cam->x - *x));
	}
	else
	{
		*x = cam->x / 64 * 64 + 64;
		*y = cam->y + tan(deg_to_rad(ABS((angle - 360)))) * ABS((cam->x - *x));
	}
}

void	trans_hori(t_cam *cam, double angle, double *x, double *y)
{
	if (angle > 180 && angle < 360)
	{
		*y = cam->y / 64 * 64 + 64;
		*x = cam->x + tan(deg_to_rad(angle - 270)) * ABS((cam->y - *y));
	}
	else
	{
		*y = cam->y / 64 * 64;
		*x = cam->x + tan(deg_to_rad(90 - angle)) * ABS((cam->y - *y));
	}
}

bool	check_wall(double x, double y, char **map)
{
	if (x < 0 || x / 64 >= ft_strlen(map[0]) ||
			y < 0 || y / 64 >= ft_strlen_len(map))
		return (false);
	if (fmod(x, 64) == 0 && fmod(y, 64) == 0)
		return (map[((int)y - 1) / 64][((int)x - 1) / 64] == '1' ||
				map[((int)y - 1) / 64][((int)x + 1) / 64] == '1' ||
				map[((int)y + 1) / 64][((int)x + 1) / 64] == '1' ||
				map[((int)y + 1) / 64][((int)x - 1) / 64] == '1' ||
				map[((int)y - 1) / 64][((int)x - 1) / 64] == '2' ||
				map[((int)y - 1) / 64][((int)x + 1) / 64] == '2' ||
				map[((int)y + 1) / 64][((int)x + 1) / 64] == '2' ||
				map[((int)y + 1) / 64][((int)x - 1) / 64] == '2');
	else if (fmod(x, 64) == 0)
		return (map[(int)y / 64][((int)x - 1) / 64] == '1' ||
				map[(int)y / 64][((int)x + 1) / 64] == '1' ||
				map[(int)y / 64][((int)x - 1) / 64] == '2' ||
				map[(int)y / 64][((int)x + 1) / 64] == '2');
	else if (fmod(y, 64) == 0)
		return (map[((int)y - 1) / 64][(int)x / 64] == '1' ||
				map[((int)y + 1) / 64][(int)x / 64] == '1' ||
				map[((int)y - 1) / 64][(int)x / 64] == '2' ||
				map[((int)y + 1) / 64][(int)x / 64] == '2');
	else
		return (map[(int)y / 64][(int)x / 64] == '1' ||
				map[(int)y / 64][(int)x / 64] == '2');
}
