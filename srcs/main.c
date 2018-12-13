#include "fdf.h"

static char	*read_file(int fd, char *content)
{
	char	*line;
	int	ret;

	content = NULL;
	line = NULL;
	while ((ret = get_next_line(fd, &line) == 1))
	{
		if (!(content = ft_stradd(content, line)))
		{
			ft_memdel((void **)&content);
			ft_memdel((void **)&line);
			return (NULL);
		}
		if (!(content = ft_stradd(content, "\n")))
		{
			ft_memdel((void **)&content);
			ft_memdel((void **)&line);
			return (NULL);
		}
		ft_memdel((void **)&line);
	}
	if (ret == -1)
		ft_memdel((void **)&content);
	return (content);
}

static char	**parse_file(char *file)
{
	char	**content_tab;
	char	*content;
	int	fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	if (!(content = read_file(fd, file)))
		return (NULL);
	if (close(fd) == -1)
	{
		ft_memdel((void **)&content);
		return (NULL);
	}
	content_tab = ft_strsplit(content, '\n');
	ft_memdel((void **)&content);
	return (content_tab);
}

int	main(int ac, char **av)
{
	char	**content;

	if (ac != 2)
		trigger_error(ERR_USAGE);
	if (!(content = parse_file(av[1])))
		trigger_error(ERR_FILE);
	ft_print_tab(content);
	ft_free_tab(&content);
	return (0);
}
