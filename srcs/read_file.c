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

static void get_help(char *map)
{
    free(map);
    ft_putstr("Usage: ./wolf3d map [-h,--help]\n===================\nIn Game:\n"
                    "  - [W,A,S,D] ... move forward/left/down/right\n"
                    "  - arrows ...... turn the camera\n"
                    "  - R ........... reset\n"
                    "  - TAB ......... open/close mini-map\n"
                    "  - ESC ......... quit the game\n");
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
		error("Error: wrong numbers of arguments\n"
                "Usage: ./wolf3d map [-h,--help]", map);
    if (!ft_strcmp(argv[1], "-h") || !ft_strcmp(argv[1], "--help"))
            get_help(map);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		error("Error: failed to open the file\n"
                "Usage: ./wolf3d map [-h,--help]", map);
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
