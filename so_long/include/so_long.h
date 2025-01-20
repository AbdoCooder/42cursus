/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:34:15 by abenajib          #+#    #+#             */
/*   Updated: 2025/01/20 20:35:30 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdbool.h>
# define WIDTH 500
# define HEIGHT 500
#define ERROR_MAP_NOT_RECTANGULAR 1
#define ERROR_MAP_NOT_SURROUNDED_BY_WALLS 2
#define ERROR_INVALID_NUMBER_OF_PLAYERS 3
#define ERROR_INVALID_NUMBER_OF_EXITS 4
#define ERROR_INVALID_NUMBER_OF_COLLECTIBLES 5
#define ERROR_INVALID_CHARACTER 6
#define ERROR_NO_VALID_PATH 7
#define ERROR_MAP_FILE_EMPTY 8
#define ERROR_FAILED_TO_OPEN_MAP_FILE 9

typedef struct s_map_data
{
	char	**map;
	int		height;
	int		width;
	int		players;
	int		collectables;
	int		exits;
	bool	valid;
}			t_map_data;


void ft_map_errors(int error);
void free_map(t_map_data *map);
void ft_read_map(t_map_data *map, char *file);
bool validate_map(t_map_data *map_data);

#endif // SO_LONG_H

