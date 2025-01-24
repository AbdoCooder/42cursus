/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:31:37 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/24 12:21:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	ft_check_requirements(t_map_data *map)
{
	ft_calculate_elements(map);
	if (map->players != 1)
		return (ft_map_errors(ERROR_INVALID_NUMBER_OF_PLAYERS), false);
	if (map->collectables < 1)
		return (ft_map_errors(ERROR_INVALID_NUMBER_OF_COLLECTIBLES), false);
	if (map->exits != 1)
		return (ft_map_errors(ERROR_INVALID_NUMBER_OF_EXITS), false);
	return (true);
}

bool	ft_check_flood(char **map_copy, int height, int width)
{
	int i;
	int j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map_copy[i][j] == 'E' || map_copy[i][j] == 'C')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	ft_check_path(t_map_data *map)
{
	char		**map_copy;
	t_player	player;

	map_copy = ft_strdup_2d(map->map, map->height);
	if (!map_copy)
		return (false);
	ft_find_player(map, &player);
	flood_fill(map_copy, player.x, player.y);
	if (!ft_check_flood(map_copy, map->height, map->width))
	{
		ft_free_2d(map_copy, map->height);
		return (false);
	}
	ft_free_2d(map_copy, map->height);
	return (true);
}

void	ft_free_2d(char **array, int height)
{
	int	i;

	i = 0;
	if (array == NULL)
		return;
	while (i < height)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

bool	ft_validate_map(t_map_data *map)
{
	//RECTANGULAR
	if (!ft_check_rectangular(map))
		return (ft_map_errors(ERROR_MAP_NOT_RECTANGULAR), false);

	//SURROUNDED_BY_WALLS
	if (!ft_check_walls(map))
		return (ft_map_errors(ERROR_MAP_NOT_SURROUNDED_BY_WALLS), false);

	//INVALID_CHARACTER
	if (!ft_check_chars(map))
		return (ft_map_errors(ERROR_INVALID_CHARACTER), false);

	//INVALID_REQUIRED_ELEMENTS
	if (!ft_check_requirements(map))
		return (false);

	//INVALID_PATH
	if (!ft_check_path(map))
		return (ft_map_errors(ERROR_NO_VALID_PATH), false);
	return (true);
}
