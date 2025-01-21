/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:13:19 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/21 18:49:38 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(char *str)
{
	if (str)
		ft_printf("%s", str);
	exit(1);
}

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
		close(fd);
		ft_error("ERROR\nMemory allocation failed\n");
	}
	map->height = 0;
	map->width = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		map->map[map->height] = line;
		map->height++;
		if (map->width == 0)
			map->width = ft_strlen(line) - 1;
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
		ft_printf("Error\nInvalid number of players (P). (Hint: Only one starting position)\n");
	else if (error == ERROR_INVALID_NUMBER_OF_EXITS)
		ft_printf("Error\nInvalid number of exits (E). (Hint: Only one exit)\n");
	else if (error == ERROR_INVALID_NUMBER_OF_COLLECTIBLES)
		ft_printf("Error\nInvalid number of collectibles (C). (Hint: At least one collectibles)\n");
	else if (error == ERROR_INVALID_CHARACTER)
		ft_printf("Error\nInvalid character in map. (Hint: Valide chars [0, 1, P, C, E])\n");
	else if (error == ERROR_NO_VALID_PATH)
		ft_printf("Error\nNo valid path to exit or collectibles.\n");
	else if (error == ERROR_MAP_FILE_EMPTY)
		ft_printf("Error\nMap file is empty.\n");
	else if (error == ERROR_FAILED_TO_OPEN_MAP_FILE)
		ft_printf("Error\nFailed to open map file.\n");
	else if (error == ERROR_INVALID_FILE_EXTENTION)
		ft_printf("Error\nInvalid file extention.\n");
	else
		ft_printf("Error\nUnknown error.\n");
}

void ft_calculate_elements(t_map_data *map)
{
	int i;
	int j;

	i = 0;
	map->players = 0;
	map->collectables = 0;
	map->exits = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
				map->players++;
			else if (map->map[i][j] == 'C')
				map->collectables++;
			else if (map->map[i][j] == 'E')
				map->exits++;
			j++;
		}
		i++;
	}
}

bool ft_check_requirements(t_map_data *map)
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

char **ft_strdup_2d(char **strs, int height)
{
	char	**copy;
	int		i;

	copy = (char **)malloc(sizeof(char *) * height);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(strs[i]);
		i++;
	}
	return (copy);
}

void ft_find_player(t_map_data *map, t_player *player)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'P')
			{
				player->x = j;
				player->y = i;
				player->collected = 0;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(char **map_copy, int x, int y)
{
	if (map_copy[y][x] == '1')
		return ;
	if (map_copy[y][x] == '0' || map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
		map_copy[y][x] = '1';
	flood_fill(map_copy, x + 1, y);
	flood_fill(map_copy, x - 1, y);
	flood_fill(map_copy, x, y + 1);
	flood_fill(map_copy, x, y - 1);
}

bool ft_check_flood(char **map_copy, int height, int width)
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

bool	ft_check_path(t_map_data *map)
{
	char		**map_copy;
	t_player	player;
	int			i;

	i = 0;
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


bool ft_validate_map(t_map_data *map)
{
	int		i;

	i = 0;

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
