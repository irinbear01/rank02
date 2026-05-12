#include "so_long.h"

static int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	check_rectangular(t_game *game)
{
	int	i;
	int	len;

	game->height = map_height(game->map);
	game->width = ft_strlen(game->map[0]);
	i = 0;
	while (game->map[i])
	{
		len = ft_strlen(game->map[i]);
		if (len != game->width)
		{
			free_map_only(game);
			exit(error_msg("map is not rectangular"));
		}
		i++;
	}
}

void	check_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->width)
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
			return (free_map_only(game), exit(error_msg("map not closed")));
		x++;
	}
	y = 0;
	while (y < game->height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
			return (free_map_only(game), exit(error_msg("map not closed")));
		y++;
	}
}

void	find_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	validate_map(t_game *game)
{
	check_rectangular(game);
	check_walls(game);
	check_elements(game);
	find_player(game);
	check_path(game);
}