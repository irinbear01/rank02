#include "so_long.h"

static char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	copy = ft_calloc(game->height + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < game->height)
	{
		copy[i] = ft_strdup(game->map[i]);
		if (!copy[i])
			return (free_split(copy), NULL);
		i++;
	}
	return (copy);
}

static void	flood(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || x >= (int)ft_strlen(map[y]))
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood(map, x + 1, y);
	flood(map, x - 1, y);
	flood(map, x, y + 1);
	flood(map, x, y - 1);
}

static void	check_after_flood(t_game *game, char **copy)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (copy[y][x] == 'C' || copy[y][x] == 'E')
			{
				free_split(copy);
				free_map_only(game);
				exit(error_msg("no valid path in map"));
			}
			x++;
		}
		y++;
	}
}

void	check_path(t_game *game)
{
	char	**copy;

	copy = copy_map(game);
	if (!copy)
	{
		free_map_only(game);
		exit(error_msg("malloc failed"));
	}
	flood(copy, game->player_x, game->player_y);
	check_after_flood(game, copy);
	free_split(copy);
}