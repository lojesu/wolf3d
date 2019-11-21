#include <wolf3d.h>

static void	plot_line_low(t_win *win, double p0[2], double p1[2])
{
	double dx;
	double dy;
	double yi;
	double d;

	dx = p1[0] - p0[0];
	dy = p1[1] - p0[1];
	yi = 1;
	d = 2 * dy - dx;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	while (p0[0] <= p1[0])
	{
		put_pixel(win, p0[0], p0[1], 0x059905);
		if (d > 0)
		{
			p0[1] = p0[1] + yi;
			d = d - 2 * dx;
		}
		d = d + 2 * dy;
		p0[0] = p0[0] + 1;
	}
}

static void	plot_line_high(t_win *win, double p0[2], double p1[2])
{
	double dx;
	double dy;
	double xi;
	double d;

	dx = p1[0] - p0[0];
	dy = p1[1] - p0[1];
	xi = 1;
	d = 2 * dx - dy;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	while (p0[1] <= p1[1])
	{
		put_pixel(win, p0[0], p0[1], 0x059905);
		if (d > 0)
		{
			p0[0] = p0[0] + xi;
			d = d - 2 * dy;
		}
		d = d + 2 * dx;
		p0[1] = p0[1] + 1;
	}
}

void		bresenham(t_win *win, double p0[2], double p1[2])
{
	if (ABS((p1[1] - p0[1])) < ABS((p1[0] - p0[0])))
	{
		if (p0[0] > p1[0])
			plot_line_low(win, p1, p0);
		else
			plot_line_low(win, p0, p1);
	}
	else
	{
		if (p0[1] > p1[1])
			plot_line_high(win, p1, p0);
		else
			plot_line_high(win, p0, p1);
	}
}
