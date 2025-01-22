#include "../include/so_long.h"

void ft_start_game(t_map_data *map)
{
	if (!map->valid)
	{
		ft_printf("Map is not valid\n");
		return;
	}
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

	// Create a new image that covers the entire window
	mlx_image_t *img = mlx_new_image(mlx_ptr, map->width * 50, map->height * 50);
	if (!img)
	{
		ft_printf("Failed to create image\n");
		return;
	}

	// Color the image based on the map
	for (int y = 0; y < map->height; y++)
	{
		for (int x = 0; x < map->width; x++)
		{
			for (int i = 0; i < 50; i++)
			{
				for (int j = 0; j < 50; j++)
				{
					if (map->map[y][x] == '1')
					{
						mlx_put_pixel(img, x * 50 + j, y * 50 + i, 0x0000FF); // Blue color with full opacity
					}
					else if (map->map[y][x] == '0')
					{
						mlx_put_pixel(img, x * 50 + j, y * 50 + i, 0x000000); // Black color with full opacity
					}
					else if (map->map[y][x] == 'P')
					{
						mlx_put_pixel(img, x * 50 + j, y * 50 + i, 0xFF0000); // Red color with full opacity
					}
					else if (map->map[y][x] == 'C')
					{
						mlx_put_pixel(img, x * 50 + j, y * 50 + i, 0x00FF00); // Green color with full opacity
					}
				}
			}
		}
	}

	// Put the image at the top-left corner of the window
	mlx_image_to_window(mlx_ptr, img, 0, 0);

	// Start the MLX42 loop
	mlx_loop(mlx_ptr);
}
