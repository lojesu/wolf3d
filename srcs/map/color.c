/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:10:13 by glegendr          #+#    #+#             */
/*   Updated: 2019/11/29 14:03:21 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <wolf3d.h>
#include <math.h>
#include <map.h>
#define COLOR_NB 20

static void	init_color_id(char *ci)
{
	ci[0] = '0';
	ci[1] = '1';
	ci[2] = '2';
	ci[3] = '3';
	ci[4] = '6';
	ci[5] = '7';
	ci[6] = '8';
	ci[7] = '9';
	ci[8] = 'R';
	ci[9] = 'L';
	ci[10] = 'D';
	ci[11] = 'U';
	ci[12] = '8';
	ci[13] = 'r';
	ci[14] = 'l';
	ci[15] = 'd';
	ci[16] = 'u';
	ci[17] = 's';
	ci[18] = '4';
	ci[19] = '5';
}

static void	init_color(int *color)
{
	color[0] = 0xc8c8c8;
	color[1] = 0xff0044;
	color[2] = 0xff5050;
	color[3] = 0x6600ff;
	color[4] = 0x00ccff;
	color[5] = 0x9933ff;
	color[6] = 0x398220;
	color[7] = 0xffff00;
	color[8] = 0x800000;
	color[9] = 0x993333;
	color[10] = 0x996633;
	color[11] = 0x663300;
	color[12] = 0x66ff33;
	color[13] = 0xe55555;
	color[14] = 0xee8888;
	color[15] = 0xeebb88;
	color[16] = 0xbb8855;
	color[17] = 0xf9c8a7;
	color[18] = 0xc8c8c8;
	color[19] = 0xff0066;
}

static int	search_color(char id, t_cam *cam)
{
	char	color_id[COLOR_NB];
	int		color[COLOR_NB];
	int		i;

	init_color_id(color_id);
	init_color(color);
	i = 0;
	while (i < COLOR_NB)
	{
		if (color_id[i] == id && !(i == 6 && cam->button == true))
			return (color[i]);
		++i;
	}
	return (0x0);
}

int			give_color(char **map, int x, int y, t_cam *cam)
{
	char	id;

	if (y < 0 || y / 64 >= (int)ft_strlen_len(map) ||
					x < 0 || x / 64 >= (int)ft_strlen(map[0]))
		return (0x0);
	else
		id = map[y / 64][x / 64];
	return (search_color(id, cam));
}

bool		in_circle(int x, int y)
{
	int rayon;
	int center;

	rayon = (CELL_SIZE + 1) * CELL_NB + CELL_NB;
	center = MAP_POS + (MAP_SIZE) / 2;
	return (hypot(ABS((x - center)), ABS((y - center))) < rayon);
}
