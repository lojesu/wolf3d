#include "wolf3d.h"
#include <libft.h>
#include <math.h>
#include <libmath.h>

void	wich_bmp
	(t_wall wall, int my_bmp[BMP_SIZE], t_env *env)
{
	int x;
	int y;

	x = wall.side == SIDE_RIGHT ? 32 : 0;
	y = wall.side == SIDE_DOWN ? 32 : 0;
	if (env->map[((int)wall.y - y) / FRAME][((int)wall.x - x) / FRAME] == '2')
	{
		if (wall.side == SIDE_RIGHT)
			my_intcpy(my_bmp, env->bmp[4], BMP_SIZE);
		else if (wall.side == SIDE_LEFT)
			my_intcpy(my_bmp, env->bmp[5], BMP_SIZE);
		else if (wall.side == SIDE_UP)
			my_intcpy(my_bmp, env->bmp[6], BMP_SIZE);
		else
			my_intcpy(my_bmp, env->bmp[7], BMP_SIZE);
		return ;
	}
	if (wall.side == SIDE_RIGHT)
		my_intcpy(my_bmp, env->bmp[0], BMP_SIZE);
	else if (wall.side == SIDE_LEFT)
		my_intcpy(my_bmp, env->bmp[1], BMP_SIZE);
	else if (wall.side == SIDE_UP)
		my_intcpy(my_bmp, env->bmp[2], BMP_SIZE);
	else
		my_intcpy(my_bmp, env->bmp[3], BMP_SIZE);
}

void	draw_sky(int start, size_t column, t_win *win)
{
	int		i;

	i = 0;
	while (i < start && i < HEIGHT)
	{
		put_pixel(win, column, i, 0x0068d1);
		i++;
	}
}
#include <stdio.h>
void	draw_floor(int start, size_t column, int size_wall, t_env *env, t_wall wall)
{
	int		i;
	int		my_bmp[BMP_SIZE];
	t_cam *cam = &env->cam;

	if (wall.side == SIDE_UP || wall.side == SIDE_DOWN)
			my_intcpy(my_bmp, env->bmp[2], BMP_SIZE);
	else
			my_intcpy(my_bmp, env->bmp[7], BMP_SIZE);
	double posx = wall.x;
	double posy = wall.y;
	i = start + size_wall;
	double rx = (cam->x - wall.x) / (HEIGHT - i);
	double ry = (cam->y - wall.y) / (HEIGHT - i);
	while (i < HEIGHT)
	{
//		if (fmod(posy, 64) < 5 || fmod(posx, 64) < 5)
	//		put_pixel(&env->win, column, i, 0xFFa477);
//		else if (env->map[(int)(posy/64)][(int)(posx/64)] == '9')
//			put_pixel(&env->win, column, i, 0x14af77);
//		else
//			put_pixel(&env->win, column, i, 0x77fa41);
//		i++;
//		posx += rx;
//		posy += ry;
	put_pixel(&env->win, column, i, 0x919191);
	++i;
	}
}

/*#define ANGLE(ori, col) ori + VISUAL_FIELD / 2 - col * VISUAL_FIELD / WIDTH

void	draw_floor(int start, int size_wall, t_env *env, int column, t_wall wall)
{
	unsigned int horizon, initdst, ymax, tmp, y;
	double correct;
	long dist, distx, disty, posx, posy;
	double angle = ANGLE((&env->cam)->orientation, column);

	y = (start+size_wall) <= 0 ? 0 : (start+size_wall);
	// number in the end is sliding correction
	posx = (long)(&env->cam)->x * UINT16_MAX * 60 * 0.0008423;
	posy = (long)(&env->cam)->y * UINT16_MAX * 60 * 0.0008423;
	horizon = HEIGHT/2 + (&env->cam)->angle;
	correct = TRUE_DIST;
	initdst = UINT16_MAX * (HEIGHT/2)/ correct * (50 - (start + size_wall));
	while (y < HEIGHT && initdst > 0)
	{
		dist = !(tmp = (2 * (y + horizon) - (HEIGHT/2))) ? UINT16_MAX :
		initdst / tmp;
	uint32_t yfact = sin(deg_to_rad(angle)) * dist;
	uint32_t xfact = cos(deg_to_rad(angle)) * dist;
		distx = dist * xfact + posx;
		distx = ((distx % 64) * 64) >> 17;
		disty = dist * yfact+ posy;
		disty = ((disty % 64) * 64) >> 17;
		tmp = disty * 64 + distx;
		printf("%li %li %li %li %li %u\n", distx, disty, posx, posy, (long)(&env->cam)->x, yfact);
		put_pixel(&env->win, distx, disty, env->bmp[7][disty*64+distx]);
		//al->pix[y * WIN_SIZEX + x] = (tex->pix[tmp] >> 24) ? tex->pix[tmp] :
		//skybox(al, y, tx);
		y++;
	}
}*/

/*void	draw_floor(int start, int size_wall, t_env *env, int column, t_wall wall)
{
  //FLOOR CASTING
      double floorXWall, floorYWall; //x, y position of the floor texel at the bottom of the wall

      //4 different wall directions possible

      double distWall, distPlayer, currentDist;

      distWall = HEIGHT/2;
      distPlayer = 0.0;

	  int drawEnd = start+size_wall;

      //draw the floor from drawEnd to the bottom of the screen
      for(int y = drawEnd + 1; y < HEIGHT; ++y)
      {
        currentDist = HEIGHT / (2.0 * y - HEIGHT); //you could make a small lookup table for this instead

        double weight = (currentDist - distPlayer) / (distWall - distPlayer);

        double currentFloorX = weight * wall.x + (1.0 - weight) * (&env->cam)->x;
        double currentFloorY = weight * wall.y + (1.0 - weight) * (&env->cam)->y;

        int floorTexX, floorTexY;
        floorTexX = (int)(currentFloorX * 64) % 64;
        floorTexY = (int)(currentFloorY * 64) % 64;

        //floor
		if (env->map[(int)currentFloorY/64][(int)currentFloorX/64] == '9')
        put_pixel(&env->win, column, y, ((env->bmp[2][64 * floorTexY + floorTexX]) >> 1) & 8355711);
		else
        put_pixel(&env->win, column, y, ((env->bmp[7][64 * floorTexY + floorTexX]) >> 1) & 8355711);
        //ceiling (symmetrical!)
        //buffer[HEIGHT - y][x] = texture[6][texWidth * floorTexY + floorTexX];
      }
}*/

/*void	get_first_left(t_env *env, int *x, int *y)
{
	int xa;
	int ya;

	xa = 0;
	while (xa < WIDTH)
	{
		ya = 0;
		while (ya < HEIGHT)
		{
			if (get_color(&env->win, xa, ya) == 0x77fa41)
			{
				*x = xa;
				*y = ya;
				return ;
			}
			++ya;
		}
		++xa;
	}
}

void	get_first_up(t_env *env, int *x, int *y)
{
	int xa;
	int ya;

		ya = 0;
	while (ya < HEIGHT)
	{
	xa = 0;
		while (xa < WIDTH)
		{
			if (get_color(&env->win, xa, ya) == 0x77fa41)
			{
				*x = xa;
				*y = ya;
				return ;
			}
		++xa;
		}
			++ya;
	}
}

void	get_first_right(t_env *env, int *x, int *y)
{
	int xa;
	int ya;

	xa = WIDTH;
	while (xa > 0)
	{
		ya = 0;
		while (ya < HEIGHT)
		{
			if (get_color(&env->win, xa, ya) == 0x77fa41)
			{
				*x = xa;
				*y = ya;
				return ;
			}
			++ya;
		}
		--xa;
	}
}

#include <map.h>

void	print_floor(t_env *env)
{
	int xl;
	int yl;
	int xu;
	int yu;
	int xr;
	int yr;
	get_first_left(env, &xl, &yl);
		printf("-------------\n");
		printf("%i %i\n", xl, yl);
	get_first_up(env, &xu, &yu);
		printf("%i %i\n", xu, yu);
	get_first_right(env, &xr, &yr);
		printf("%i %i\n", xr, yr);
	printf("%i %i %i %i\n", xu -xl, yu-yl, xr - xu, yr - yu);
	int dirx = xu -xl;
	int diry = yu -yl;
	xl +=64;
	double p1[2] = {xl, yl};
	double p2[2] = {xl +dirx, yl + diry};
	bresenham(&env->win, p1, p2);
	//double p3[2] = {xr, yr};
	//bresenham(&env->win, p3, p2);
}*/

void	draw_texture(t_wall wall, t_env *env, size_t column, int start)
{
	int		pos;
	int		i;
	double	z;
	double	ratio;
	int		my_bmp[BMP_SIZE];

	z = 1;
	i = start > 0 ? start : 0;
	wich_bmp(wall, my_bmp, env);
	pos = wall.side == SIDE_UP || wall.side == SIDE_DOWN ?
		fmod(wall.x, 64) : fmod(wall.y, 64);
	ratio = (double)BMP_SIDE / (double)(DIST_SCREEN * FRAME / wall.dist);
	if (start < 0)
		z = ratio * -start + 1;
	while (i < start + (DIST_SCREEN * FRAME / wall.dist) && i < HEIGHT)
	{
		put_pixel(&env->win, column, i,
				my_bmp[pos + BMP_SIZE - (int)z * BMP_SIDE]);
		++i;
		z += ratio;
	}
}

void	print(t_env *env, t_wall wall, size_t column)
{
	int		size_wall;
	int		start;

	size_wall = DIST_SCREEN * FRAME / wall.dist;
	start = HEIGHT / 2 - size_wall / 2 + (&env->cam)->angle;
	draw_sky(start, column, &env->win);
	draw_texture(wall, env, column, start);
	draw_floor(start, column, size_wall, env, wall);
}
