#include "../include/so_long.h"

void ft_start_game(t_map_data *map)
{
	if (!map->valid)
	{
		ft_printf("Map is not valid\n");
		return;
	}
	ft_printf("Game Start!\n");
	ft_init_game(map);
}

static mlx_image_t* player_image;
// static mlx_image_t* img;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
	(void)param;
	uint32_t i = 0;
	uint32_t y = 0;
	uint32_t color = 0xFF;
	while (i < player_image->width)
	{
		y = 0;
		while (y < player_image->height)
			mlx_put_pixel(player_image, i, y++, color);
		i++;
	}
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		player_image->instances[0].y -= 10;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		player_image->instances[0].y += 10;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		player_image->instances[0].x -= 10;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		player_image->instances[0].x += 10;
}


void ft_init_game(t_map_data *map)
{
	mlx_t* mlx;
	t_player player;

	ft_find_player(map, &player);
	if (!(mlx = mlx_init(map->width * 50, map->height * 50, "so_long", false)))
	{
		puts(mlx_strerror(mlx_errno));
		return ;
	}
	if (!(player_image = mlx_new_image(mlx, 50, 50)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return ;
	}
	if (mlx_image_to_window(mlx, player_image, player.x * 50, player.y * 50) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return ;
	}
	mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
