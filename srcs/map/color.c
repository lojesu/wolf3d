#include <libft.h>
#include <wolf3d.h>
#include <math.h>
#include <map.h>
#define COLOR_NB 12

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
}

static int	search_color(char id)
{
	char	color_id[COLOR_NB];
	int		color[COLOR_NB];
	int		i;

	init_color_id(color_id);
	color[0] = 0xc8c8c8;
	color[1] = 0xff0044;
	color[2] = 0xff5050;
	color[3] = 0x6600ff;
	color[4] = 0x00ccff;
	color[5] = 0x9933ff;
	color[6] = 0x66ff33;
	color[7] = 0xffff00;
	color[8] = 0x800000;
	color[9] = 0x993333;
	color[10] = 0x996633;
	color[11] = 0x663300;
	i = 0;
	while (i < 12)
	{
		if (color_id[i] == id)
			return (color[i]);
		++i;
	}
	return (0x0);
}

int			give_color(char **map, int x, int y)
{
	char	id;

	if (y < 0 || y / 64 >= ft_strlen_len(map) ||
					x < 0 || x / 64 >= ft_strlen(map[0]))
		return (0x0);
	else
		id = map[y / 64][x / 64];
	return (search_color(id));
}

bool		in_circle(int x, int y)
{
	int rayon;
	int center;

	rayon = (CELL_SIZE + 1) * CELL_NB + CELL_NB;
	center = MAP_POS + (MAP_SIZE) / 2;
	return (hypot(ABS((x - center)), ABS((y - center))) < rayon);
}
