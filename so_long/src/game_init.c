/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:05:20 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/25 12:08:05 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	ft_check_char(t_map_data *map, int x, int y, int num)
{
	if (num == GROUND_TEXTURE)
		return (map->map[y][x] == '0' || map->map[y][x] == 'E'
				|| map->map[y][x] == 'C' || map->map[y][x] == 'P'
				|| map->map[y][x] == '1');
	if (num == WALLS_TEXTURE)
		return (map->map[y][x] == '1');
	if (num == COLECTABLES_TEXTURE)
		return (map->map[y][x] == 'C');
	if (num == EXITS_TEXTURE)
		return (map->map[y][x] == 'E');
	if (num == PLAYER_TEXTURE)
		return (map->map[y][x] == 'P');
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
	if (num == EXITS_TEXTURE)
		return (textures->exit_path);
	if (num == PLAYER_TEXTURE)
		return (textures->player_path);
	return (NULL);
}

bool	ft_put_texture(mlx_t *mlx, t_map_data *map,
						t_textures *textures, int num)
{
	int		x;
	int		y;
	void	*texture;
	void	*image;

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

void	ft_fill_textures(t_textures *textures)
{
	textures->ground_path = "textures/ground.png";
	textures->walls_path = "textures/wall.png";
	textures->colectables_path = "textures/colectable.png";
	textures->exit_path = "textures/exit.png";
	textures->player_path = "textures/player.png";
}

void	**ft_get_textures(void **texture)
{
	texture = malloc(6 * sizeof(void *));
	texture[GROUND_TEXTURE] = mlx_load_png("textures/ground.png");
	texture[WALLS_TEXTURE] = mlx_load_png("textures/wall.png");
	texture[PLAYER_TEXTURE] = mlx_load_png("textures/player.png");
	texture[EXITS_TEXTURE] = mlx_load_png("textures/exit.png");
	texture[COLECTABLES_TEXTURE] = mlx_load_png("textures/colectable.png");
	return (texture);
}

void	ft_remove_textures(void **texture)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (texture[i] == NULL)
			i++;
		else
		{
			mlx_delete_texture(texture[i]);
			i++;
		}
	}
	free(texture);
	texture = NULL;
}

bool	ft_check_textures(void)
{
	void	**texture;
	int		i;

	i = 0;
	texture = NULL;
	texture = ft_get_textures(texture);
	while (i < 5)
	{
		if (texture[i] == NULL)
		{
			ft_remove_textures(texture);
			return (false);
		}
		i++;
	}
	ft_remove_textures(texture);
	return (true);
}

bool	ft_init_game(t_map_data *map)
{
	mlx_t		*mlx;
	t_textures	textures;

	ft_fill_textures(&textures);
	if (!ft_check_textures())
		return (ft_printf("Error | Failed to load textures!\n"), false);
	mlx = mlx_init(map->width * 64, map->height * 64, "so_long", false);
	if (!ft_put_texture(mlx, map, &textures, GROUND_TEXTURE))
		return (ft_printf("Error | Failed to put the GROUND_TEXTURE!\n"), false);
	if (!ft_put_texture(mlx, map, &textures, WALLS_TEXTURE))
		return (ft_printf("Error | Failed to put the WALLS_TEXTURE!\n"), false);
	if (!ft_put_texture(mlx, map, &textures, COLECTABLES_TEXTURE))
		return (ft_printf("Error | Failed to put the COLECTABLES_TEXTURE!\n"),
			false);
	if (!ft_put_texture(mlx, map, &textures, EXITS_TEXTURE))
		return (ft_printf("Error | Failed to put the EXITS_TEXTURE!\n"), false);
	if (!ft_put_texture(mlx, map, &textures, PLAYER_TEXTURE))
		return (ft_printf("Error | Failed to put the PLAYER_TEXTURE!\n"), false);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (true);
}

void	ft_start_game(t_map_data *map)
{
	if (!map->valid)
	{
		ft_printf("Map is not valid\n");
		return ;
	}
	ft_printf("Game Start!\n");
	ft_init_game(map);
}

	// ft_printf("=============================================\n");
