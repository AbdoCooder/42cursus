/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:41:53 by abenajib          #+#    #+#             */
/*   Updated: 2025/02/08 21:33:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t	g_i;

void	*routine()
{
	while (g_i < 10000)
		g_i++;
	return (NULL);
}

int	main(int ac, char **av)
{
	pthread_t	t;
	pthread_t	t2;

	(void)ac;
	(void)av;
	g_i = 0;
	printf("before t1 | i = %zu\n\n\n", g_i);
	if (pthread_create(&t, NULL, &routine, NULL) != 0)
		return (ft_error("pthread_create failed"), 1);

	printf("before t2 | i = %zu\n\n\n", g_i);
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return (ft_error("pthread_create failed"), 1);

	if (pthread_join(t, NULL) != 0)
		return (ft_error("pthread_join failed"), 1);

	printf("after t1 | i = %zu\n\n\n", g_i);
	if (pthread_join(t2, NULL) != 0)
		return (ft_error("pthread_join failed"), 1);

	printf("after t2 | i = %zu\n\n\n", g_i);
	return (0);
}
