#include "so_long.h"

static void	put_tile(t_game *game, char c, int x, int y)
{
	void	*img;

	img = game->floor.ptr;
	if (c == '1')
		img = game->wall.ptr;
	else if (c == 'C')
		img = game->collect.ptr;
	else if (c == 'E')
		img = game->exit.ptr;
	else if (c == 'P')
		img = game->player.ptr;
	mlx_put_image_to_window(game->mlx, game->win, img, x * TILE, y * TILE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			put_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}