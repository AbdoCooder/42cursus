/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:06:55 by codespace         #+#    #+#             */
/*   Updated: 2025/01/20 20:36:05 by abenajib         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_map_data map_data;

	if (argc != 2)
	{
		ft_printf("Error\nUsage: %s <map.ber>\n", argv[0]);
		return (1);
	}
	ft_read_map(&map_data, argv[1]);
	if (map_data.height == 0)
	{
		ft_map_errors(ERROR_MAP_FILE_EMPTY);
		free_map(&map_data);
		return (1);
	}
	if (!validate_map(&map_data))
	{
		free_map(&map_data);
		return (1);
	}
	print_map(&map_data);
	ft_printf("\nMap is valid!\n");
	free_map(&map_data);
	return 0;
}
