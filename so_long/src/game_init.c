#include "../include/so_long.h"

void ft_start_game(t_map_data *map)
{
	ft_init_game(map);
}

void ft_init_game(t_map_data *map)
{
	t_player player;
	mlx_t *mlx_ptr;

	ft_printf("\nGame started\n");
	ft_find_player(map, &player);
	mlx_ptr = mlx_init(map->width * 50, map->height * 50, "So Long", false);
	if (!mlx_ptr)
	{
		ft_printf("Failed to initialize MLX42\n");
		return;
	}

	// Create a new image
	mlx_image_t *img = mlx_new_image(mlx_ptr, 50, 50);
	if (!img)
	{
		ft_printf("Failed to create image\n");
		return;
	}

	// Color the image based on the map
	for (int y = 0; y < 50; y++)
	{
		for (int x = 0; x < 50; x++)
		{
			if (map->map[y][x] == '1')
			{
				mlx_put_pixel(img, x, y, 0x0000FFFF); // Blue color with full opacity
			}
			else if (map->map[y][x] == '0')
			{
				mlx_put_pixel(img, x, y, 0x000000FF); // Black color with full opacity
			}
		}
	}

	// Put the image at the player's position
	mlx_image_to_window(mlx_ptr, img, player.x * 50, player.y * 50);

	// Start the MLX42 loop
	mlx_loop(mlx_ptr);
}
