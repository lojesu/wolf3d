#include "wolf3d.h"

int	rgb_to_hex(uint8_t r, uint8_t g, uint8_t b)
{
	return (b << 16 ^ g << 8 ^ r);
}

void	hex_to_rgb(int *r, int *g, int *b, int color)
{
	*r = (color >> 16 & 0xFF);
	*g = (color >> 8 & 0xFF);
	*b = (color & 0xFF);
}

void		put_pixel(t_win *win, size_t x, size_t y, int color)
{
	size_t	pix_colors;
	int		r;
	int		g;
	int		b;

	pix_colors = 4 * x + 4 * WIDTH * y;
	hex_to_rgb(&r, &g, &b, color);
	IMG_STR[pix_colors] = b;
	IMG_STR[pix_colors + 1] = g;
	IMG_STR[pix_colors + 2] = r;
}

int		get_color(t_win *win, size_t x, size_t y)
{
	size_t	pix_colors;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;

	pix_colors = 4 * x + 4 * WIDTH * y;
	b = IMG_STR[pix_colors];
	g = IMG_STR[pix_colors + 1];
	r = IMG_STR[pix_colors + 2];
	return (rgb_to_hex((uint8_t)b, (uint8_t)g, (uint8_t)r));
}
