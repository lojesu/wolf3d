#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "wolf3d.h"

static void	error(char *s, char **map)
{
	ft_putendl(s);
	ft_tabdel_char(&map);
	exit(1);
}

static void	first_and_last_line(char *line, char **map)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			error("Error: the map must be surrounded by '1'", map);
		i++;
	}
}

static void	verif_character(char *line, char **map)
{
	size_t	i;
	size_t	line_size;

	line_size = ft_strlen(line);
	i = 0;
	while (i < line_size)
	{
		if (!ft_isdigit(line[i]))
			error("Error: non digit character founded", map);
		i++;
	}
}

static void	verif_line(char *line, size_t pattern, size_t nb_line, char **map)
{
	size_t	i;
	size_t	line_size;

	line_size = ft_strlen(line);
	i = 0;
	if (nb_line == 0)
		first_and_last_line(line, map);
	else
	{
		if (line_size != pattern)
			error("Error: the size of the line must be the same", map);
		if (line[0] != '1' || line[line_size - 1] != '1')
			error("Error: the map must be surrounded by '1'", map);
		verif_character(line, map);
	}

}

char		**parsing(char *map_read)
{
	char	**map;
	size_t	nb_line;
	size_t	pattern;

	nb_line = 0;
	if (!ft_strchr(map_read, '9') || ft_count_char(map_read, '9') != 1)
	{
		free(map_read);
		error("Error: put a '9' to let the player spawn", NULL);
	}
	map = ft_strsplit(map_read, '/');
	free(map_read);
	pattern = ft_strlen(map[nb_line]);
	while (map[nb_line])
	{
		verif_line(map[nb_line], pattern, nb_line, map);
		nb_line++;
	}
	first_and_last_line(map[nb_line - 1], map);
	return (map);
}
