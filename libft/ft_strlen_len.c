#include <stddef.h>

size_t	ft_strlen_len(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return(i);
}
