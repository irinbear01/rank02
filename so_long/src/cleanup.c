#include "so_long.h"

void	free_map_only(t_game *game)
{
	free_split(game->map);
	game->map = NULL;
}

void	destroy_images(t_game *game)
{
	if (game->wall.ptr)
		mlx_destroy_image(game->mlx, game->wall.ptr);
	if (game->floor.ptr)
		mlx_destroy_image(game->mlx, game->floor.ptr);
	if (game->player.ptr)
		mlx_destroy_image(game->mlx, game->player.ptr);
	if (game->exit.ptr)
		mlx_destroy_image(game->mlx, game->exit.ptr);
	if (game->collect.ptr)
		mlx_destroy_image(game->mlx, game->collect.ptr);
}

int	close_game(t_game *game)
{
	destroy_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free_map_only(game);
	exit(0);
}