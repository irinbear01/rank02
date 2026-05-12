#include "so_long.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	fill_image(t_img *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < TILE)
	{
		x = 0;
		while (x < TILE)
		{
			put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

static t_img	new_color_img(t_game *game, int color)
{
	t_img	img;

	img.ptr = mlx_new_image(game->mlx, TILE, TILE);
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.line_len, &img.endian);
	fill_image(&img, color);
	return (img);
}

void	create_images(t_game *game)
{
	game->wall = new_color_img(game, 0x333333);
	game->floor = new_color_img(game, 0xDDDDDD);
	game->player = new_color_img(game, 0x00AAFF);
	game->exit = new_color_img(game, 0x00CC66);
	game->collect = new_color_img(game, 0xFFCC00);
}