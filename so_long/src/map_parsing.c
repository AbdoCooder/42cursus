/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:13:19 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/20 21:03:42 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void ft_read_map(t_map_data *map, char *file)
{
	int fd;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("ERROR\nFAILED TO OPEN THE MAP FILE (%s)\n", file);
		exit(1);
	}
	map->map = (char **)malloc(sizeof(char *) * 100);
	if (!map->map)
	{
		ft_printf("ERROR\nMemory allocation failed\n");
		close(fd);
		exit(1);
	}
	map->height = 0;
	map->width = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		map->map[map->height] = line;
		map->height++;
		if (map->width == 0)
			map->width = ft_strlen(line, '\0') - 1;
	}
	close(fd);
}

void free_map(t_map_data *map)
{
	int	i;

	i = 0;
	while (i < map->height)
		free(map->map[i++]);
	free(map->map);
}

void ft_map_errors(int error)
{
	if (error == ERROR_MAP_NOT_RECTANGULAR)
		ft_printf("Error\nMap is not rectangular.\n");
	else if (error == ERROR_MAP_NOT_SURROUNDED_BY_WALLS)
		ft_printf("Error\nMap is not surrounded by walls.\n");
	else if (error == ERROR_INVALID_NUMBER_OF_PLAYERS)
		ft_printf("Error\nInvalid number of players (P).\n");
	else if (error == ERROR_INVALID_NUMBER_OF_EXITS)
		ft_printf("Error\nInvalid number of exits (E).\n");
	else if (error == ERROR_INVALID_NUMBER_OF_COLLECTIBLES)
		ft_printf("Error\nInvalid number of collectibles (C).\n");
	else if (error == ERROR_INVALID_CHARACTER)
		ft_printf("Error\nInvalid character in map.\n");
	else if (error == ERROR_NO_VALID_PATH)
		ft_printf("Error\nNo valid path to exit or collectibles.\n");
	else if (error == ERROR_MAP_FILE_EMPTY)
		ft_printf("Error\nMap file is empty.\n");
	else if (error == ERROR_FAILED_TO_OPEN_MAP_FILE)
		ft_printf("Error\nFailed to open map file.\n");
	else
		ft_printf("Error\nUnknown error.\n");
}

//================================================================================
// AI

bool validate_map(t_map_data *map_data)
{


	// Check if the map is surrounded by walls
	for (int i = 0; i < map_data->height; i++)
	{
		// Check first and last character of each line
		if (map_data->map[i][0] != '1' || map_data->map[i][map_data->width - 1] != '1')
		{
			ft_map_errors(ERROR_MAP_NOT_SURROUNDED_BY_WALLS);
			return false;
		}
	}
	// Check first and last line
	for (int j = 0; j < map_data->width; j++)
	{
		if (map_data->map[0][j] != '1' || map_data->map[map_data->height - 1][j] != '1')
		{
			ft_map_errors(ERROR_MAP_NOT_SURROUNDED_BY_WALLS);
			return false;
		}
	}

	// Count players, exits, and collectibles
	map_data->players = 0;
	map_data->exits = 0;
	map_data->collectables = 0;

	for (int i = 0; i < map_data->height; i++)
	{
		for (int j = 0; j < map_data->width; j++)
		{
			if (map_data->map[i][j] == 'P')
			{
				map_data->players++;
				// Check if player is on the border (invalid position)
				if (i == 0 || i == map_data->height - 1 || j == 0 || j == map_data->width - 1)
				{
					ft_map_errors(ERROR_INVALID_CHARACTER);
					return false;
				}
			}
			else if (map_data->map[i][j] == 'E')
				map_data->exits++;
			else if (map_data->map[i][j] == 'C')
				map_data->collectables++;
			else if (map_data->map[i][j] != '0' && map_data->map[i][j] != '1')
			{
				ft_map_errors(ERROR_INVALID_CHARACTER);
				return false;
			}
		}
	}

	// Validate number of players, exits, and collectibles
	if (map_data->players != 1)
	{
		ft_map_errors(ERROR_INVALID_NUMBER_OF_PLAYERS);
		return false;
	}
	if (map_data->exits != 1)
	{
		ft_map_errors(ERROR_INVALID_NUMBER_OF_EXITS);
		return false;
	}
	if (map_data->collectables < 1)
	{
		ft_map_errors(ERROR_INVALID_NUMBER_OF_COLLECTIBLES);
		return false;
	}

	return true;
}

//================================================================================
