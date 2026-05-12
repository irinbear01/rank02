#include "so_long.h"

static void	check_char(t_game *game, char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
	{
		free_map_only(game);
		exit(error_msg("invalid character in map"));
	}
}

void	check_elements(t_game *game)
{
	int	x;
	int	y;
	int	p;
	int	e;

	p = 0;
	e = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			check_char(game, game->map[y][x]);
			p += (game->map[y][x] == 'P');
			e += (game->map[y][x] == 'E');
			game->collectibles += (game->map[y][x] == 'C');
			if (game->map[y][x] == 'E')
				game->exit_x = x, game->exit_y = y;
			x++;
		}
		y++;
	}
	if (p != 1 || e != 1 || game->collectibles < 1)
		return (free_map_only(game), exit(error_msg("bad P/E/C count")));
}