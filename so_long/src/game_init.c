#include "../include/so_long.h"

bool ft_check_char(t_map_data *map, int x, int y, int num)
{
	if (num == GROUND_TEXTURE)
		return (map->map[y][x] == '0' || map->map[y][x] == 'E' || map->map[y][x] == 'C' || map->map[y][x] == 'P' || map->map[y][x] == '1');
	if (num == WALLS_TEXTURE)
		return (map->map[y][x] == '1');
	if (num == COLECTABLES_TEXTURE)
		return (map->map[y][x] == 'C');
	return (false);
}

char	*ft_write_path(t_textures *textures, int num)
{
	if (num == GROUND_TEXTURE)
		return (textures->ground_path);
	if (num == WALLS_TEXTURE)
		return (textures->walls_path);
	if (num == COLECTABLES_TEXTURE)
		return (textures->colectables_path);
	return (NULL);
}

bool	ft_put_texture(mlx_t *mlx, t_map_data *map, t_textures *textures, int num)
{
	int x;
	int y;
	void *texture;
	void *image;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (ft_check_char(map, x, y, num))
			{
				texture = mlx_load_png(ft_write_path(textures, num));
				image = mlx_texture_to_image(mlx, texture);
				if (mlx_image_to_window(mlx, image, x * 64, y * 64) == -1)
					return (false);
				mlx_delete_texture(texture);
			}
			x++;
		}
		y++;
	}
	return (true);
}

void ft_fill_textures(t_textures *textures)
{
	textures->ground_path = "textures/ground.png";
	textures->walls_path = "textures/wall.png";
	textures->colectables_path = "textures/colectable.png";
}

bool	ft_init_game(t_map_data *map)
{
	mlx_t	*mlx;
	t_textures	textures;

	ft_fill_textures(&textures);
	mlx = mlx_init(map->width * 64, map->height * 64, "so_long", false);
	if (!ft_put_texture(mlx, map, &textures, GROUND_TEXTURE))
		return(ft_printf("Error | Failed to put the GROUND_TEXTURE!\n"), false);
	if (!ft_put_texture(mlx, map, &textures, WALLS_TEXTURE))
		return(ft_printf("Error | Failed to put the WALLS_TEXTURE!\n"), false);
	if (!ft_put_texture(mlx, map, &textures, COLECTABLES_TEXTURE))
		return(ft_printf("Error | Failed to put the COLECTABLES_TEXTURE!\n"), false);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (true);
}

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

	// ft_printf("=============================================\n");
