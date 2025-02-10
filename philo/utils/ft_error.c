/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:15:09 by codespace         #+#    #+#             */
/*   Updated: 2025/02/10 13:34:37 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_error(char *error, char *warning)
{
	if (error)
		printf(RED"Error: %s\n"DEF_COLOR, error);
	if (warning)
		printf(MAGENTA"%s\n"DEF_COLOR, warning);
}
