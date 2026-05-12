#include "so_long.h"

static void	try_exit(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E' && game->collectibles == 0)
	{
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
		close_game(game);
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	next;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	next = game->map[new_y][new_x];
	if (next == '1')
		return ;
	if (next == 'E')
		return (try_exit(game, new_x, new_y));
	if (next == 'C')
		game->collectibles--;
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[game->player_y][game->player_x] = 'P';
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_map(game);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_game(game);
	else if (keycode == XK_w || keycode == XK_Up)
		move_player(game, 0, -1);
	else if (keycode == XK_s || keycode == XK_Down)
		move_player(game, 0, 1);
	else if (keycode == XK_a || keycode == XK_Left)
		move_player(game, -1, 0);
	else if (keycode == XK_d || keycode == XK_Right)
		move_player(game, 1, 0);
	return (0);
}