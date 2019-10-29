#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static void	error(char *s, char *map)
{
	ft_putendl(s);
	free(map);
	exit(1);
}

static char	*realloc_str(char *s, size_t size)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = ft_strnew(size);
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	free(s);
	return (ret);
}

static void	fill_map(char *line, char **map, size_t *size_map)
{
	while (ft_strlen(line) + ft_strlen(*map) + 1 > *size_map)
	{
		*size_map *= 2;
		*map = realloc_str(*map, *size_map);
	}
	*map = ft_strcat(*map, line);
	(*map)[ft_strlen(*map)] = '/';
}

char		*read_file(int argc, char **argv)
{
	int		fd;
	char	*line;
	char	*map;
	size_t	size_map;

	size_map = 32;
	map = ft_strnew(size_map);
	if (argc != 2)
		error("Error: wrong numbers of arguments", map);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		error("Error: an unexpected error occured", map);
	while (get_next_line(fd, &line) > 0)
	{
		fill_map(line, &map, &size_map);
		free(line);
	}
	if (close(fd) < 0)
		error("Error: an unexpected error occured", map);
	if (!ft_strlen(map) || ft_strstr(map, "//") || !ft_strcmp(map, "/"))
		error("Error: we do not accept empty line(s)", map);
	return (map);
}
