/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:13:19 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/20 22:32:23 by abenajib         ###   ########.fr       */
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

bool ft_validate_map(t_map_data *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	//RECTANGULAR
	while (i < map->height)
	{
		if (ft_strlen(map->map[i], '\0') - 1 != map->width)
			return (ft_map_errors(ERROR_MAP_NOT_RECTANGULAR), false);
		i++;
	}
	return (true);
}

//================================================================================
