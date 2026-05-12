#include "so_long.h"

static void	init_game(t_game *game, char **map)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = map;
	game->width = 0;
	game->height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->collectibles = 0;
	game->moves = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (error_msg("Usage: ./so_long maps/map.ber"));
	check_file_name(argv[1]);
	init_game(&game, read_map(argv[1]));
	validate_map(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (free_map_only(&game), error_msg("mlx_init failed"));
	game.win = mlx_new_window(game.mlx, game.width * TILE,
			game.height * TILE, "so_long");
	if (!game.win)
		return (free_map_only(&game), error_msg("mlx_new_window failed"));
	create_images(&game);
	render_map(&game);
	mlx_hook(game.win, KeyPress, KeyPressMask, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}