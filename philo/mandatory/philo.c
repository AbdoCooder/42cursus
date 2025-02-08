/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:41:53 by abenajib          #+#    #+#             */
/*   Updated: 2025/02/08 20:21:10 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>

void	*routine()
{
	for (size_t i = 0; i < 9999999/3; i++)
		printf("");
	return (NULL);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	pthread_t thread;
	pthread_t thread2;
	pthread_t thread3;
	pthread_create(&thread, NULL, &routine, NULL);
	pthread_create(&thread2, NULL, &routine, NULL);
	pthread_create(&thread3, NULL, &routine, NULL);
	pthread_join(thread, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	// for (int i = 0; i < 99999999; i++)
	// 	printf("");
	return (0);
}
