#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define TILE 32

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		collectibles;
	int		moves;
	t_img	wall;
	t_img	floor;
	t_img	player;
	t_img	exit;
	t_img	collect;
}	t_game;

int		close_game(t_game *game);
int		handle_key(int keycode, t_game *game);
int		error_msg(char *msg);
void	free_split(char **arr);
void	destroy_images(t_game *game);
void	free_map_only(t_game *game);

char	**read_map(char *file);
void	check_file_name(char *file);
void	validate_map(t_game *game);

void	find_player(t_game *game);
void	check_rectangular(t_game *game);
void	check_walls(t_game *game);
void	check_elements(t_game *game);
void	check_path(t_game *game);

void	render_map(t_game *game);
void	move_player(t_game *game, int dx, int dy);

void	create_images(t_game *game);
void	put_pixel(t_img *img, int x, int y, int color);
void	fill_image(t_img *img, int color);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif