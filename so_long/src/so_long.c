/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:06:55 by codespace         #+#    #+#             */
/*   Updated: 2025/01/21 12:33:25 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void print_map(t_map_data *map_data)
{
	int i = 0;

	while (i < map_data->height)
	{
		ft_printf("%s", map_data->map[i]);
		i++;
	}
}

bool ft_check_extention(char *file)
{
	int i = 0;

	while (file[i])
		i++;
	if (i < 5)
		return (false);
	if (file[i - 1] != 'r' || file[i - 2] != 'e' || file[i - 3] != 'b' || file[i - 4] != '.')
		return (false);
	return (true);
}

int main(int argc, char **argv)
{
	t_map_data map_data;

	if (argc != 2)
	{
		ft_printf("Error\nUsage: %s <map.ber>\n", argv[0]);
		return (1);
	}
	//FILE_EXTENSION
	if (!ft_check_extention(argv[1]))
		return (ft_map_errors(ERROR_INVALID_FILE_EXTENTION), false);
	//READ_MAP
	ft_read_map(&map_data, argv[1]);
	if (map_data.height == 0)
	{
		//MAP_FILE_EMPTY
		ft_map_errors(ERROR_MAP_FILE_EMPTY);
		return (free_map(&map_data), 1);
	}
	//VALIDATE_MAP
	if (!ft_validate_map(&map_data))
		return (free_map(&map_data), 1);
	print_map(&map_data);
	ft_printf("\nMap is valid!\n");
	free_map(&map_data);
	return 0;
}
