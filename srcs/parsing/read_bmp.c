/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:10:27 by glegendr          #+#    #+#             */
/*   Updated: 2019/11/28 19:04:30 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <wolf3d.h>
#include <unistd.h>
#include <fcntl.h>
#include <vector.h>

#define BUFF_SIZE (BMP_SIZE * 3)

static int	rgb_to_hex(uint8_t r, uint8_t g, uint8_t b)
{
	return (b << 16 ^ g << 8 ^ r);
}

void		read_bmp(int *ret, char *path, char *buff, int buff_size)
{
	t_vec	bmp;
	int		fd;
	size_t	start;
	int		tmp;

	tmp = 0;
	if ((fd = open(path, O_RDONLY)) == -1)
		return ;
	bmp = v_new(sizeof(uint8_t));
	while ((tmp = read(fd, buff, buff_size)) > 0)
		v_append_raw(&bmp, buff, tmp);
	start = v_size(&bmp) - buff_size;
	tmp = 0;
	while (start + tmp < (size_t)v_size(&bmp))
	{
		ret[tmp / 3] = rgb_to_hex(*(char *)v_get(&bmp, tmp + start),
				*(char *)v_get(&bmp, tmp + 1 + start),
				*(char *)v_get(&bmp, tmp + 2 + start));
		tmp += 3;
	}
	v_del(&bmp);
	close(fd);
}

void		my_intcpy(int *dst, int *src, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		++i;
	}
}

void		launch_texture(t_env *env)
{
	char	buff[BUFF_SIZE];
	char	*path[BMP_NB];
	int		i;

	path[0] = "textures/wall.bmp";
	path[1] = "textures/wall1.bmp";
	path[2] = "textures/wall2.bmp";
	path[3] = "textures/wall3.bmp";
	path[4] = "textures/library.bmp";
	i = 0;
	while (i < BMP_NB)
	{
		ft_bzero(env->bmp[i], BMP_SIZE * sizeof(int));
		read_bmp(env->bmp[i], path[i], buff, BUFF_SIZE);
		++i;
	}
}
