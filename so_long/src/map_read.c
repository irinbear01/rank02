#include "so_long.h"

static char	*read_all(int fd)
{
	char	*buf;
	char	*tmp;
	int		bytes;

	buf = ft_strdup("");
	if (!buf)
		return (NULL);
	tmp = malloc(1025);
	if (!tmp)
		return (free(buf), NULL);
	bytes = read(fd, tmp, 1024);
	while (bytes > 0)
	{
		tmp[bytes] = '\0';
		buf = ft_strjoin(buf, tmp);
		if (!buf)
			return (free(tmp), NULL);
		bytes = read(fd, tmp, 1024);
	}
	free(tmp);
	if (bytes < 0)
		return (free(buf), NULL);
	return (buf);
}

static void	check_empty_lines(char *content)
{
	int	i;

	if (!content[0])
	{
		free(content);
		exit(error_msg("empty file"));
	}
	if (content[0] == '\n')
	{
		free(content);
		exit(error_msg("invalid map"));
	}
	i = 0;
	while (content[i])
	{
		if (content[i] == '\n' && content[i + 1] == '\n')
		{
			free(content);
			exit(error_msg("empty line in map"));
		}
		i++;
	}
}

void	check_file_name(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 5 || ft_strncmp(file + len - 4, ".ber", 4) != 0)
		exit(error_msg("file must end with .ber"));
}

char	**read_map(char *file)
{
	int		fd;
	char	*content;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(error_msg("cannot open file"));
	content = read_all(fd);
	close(fd);
	if (!content)
		exit(error_msg("cannot read file"));
	check_empty_lines(content);
	map = ft_split(content, '\n');
	free(content);
	if (!map || !map[0])
		exit(error_msg("invalid map content"));
	return (map);
}