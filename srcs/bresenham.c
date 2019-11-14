#include <wolf3d.h>

void    plotLineLow(t_win *win, int p0[2], int p1[2])
{
  int dx = p1[0] - p0[0];
  int dy = p1[1] - p0[1];
  int yi = 1;
  if (dy < 0)
  {
    yi = -1;
    dy = -dy;
    }
  int D = 2 * dy - dx;

  while (p0[0] <= p1[0])
  {
    put_pixel(win, p0[0],p0[1], 0x059905);
    if (D > 0)
    {
       p0[1] = p0[1] + yi;
       D = D - 2*dx;
    }
    D = D + 2*dy;
    p0[0] = p0[0] + 1;
  }
}

void    plotLineHigh(t_win *win, int p0[2], int p1[2])
{
  int dx = p1[0] - p0[0];
  int dy = p1[1] - p0[1];
  int xi = 1;
  if (dx < 0)
  {
    xi = -1;
    dx = -dx;
  }
  int D = 2 * dx - dy;

  while (p0[1] <= p1[1])
  {
    put_pixel(win, p0[0],p0[1], 0x059905);
    if (D > 0)
    {
       p0[0] = p0[0] + xi;
       D = D - 2* dy;
    }
    D = D + 2 * dx;
            p0[1] = p0[1] + 1;
  }
}

void    bresenham(t_win *win, int p0[2], int p1[2])
{
      if (ABS((p1[1] - p0[1])) < ABS((p1[0] - p0[0])))
    {
        if (p0[0] > p1[0])
            plotLineLow(win, p1, p0);
        else
            plotLineLow(win, p0, p1);
    }
    else
    {
        if (p0[1] > p1[1])
            plotLineHigh(win, p1, p0);
        else
            plotLineHigh(win, p0, p1);
    }
}
