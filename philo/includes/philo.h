/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:59:26 by codespace         #+#    #+#             */
/*   Updated: 2025/02/10 13:44:17 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//colors
# define DEF_COLOR "\033[0;39m"
# define GRAY "\033[0;90m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define MAGENTA "\033[0;95m"
# define CYAN "\033[0;96m"
# define WHITE "\033[0;97m"

//Macros
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define SUCCESS 0
# define PROGRAM_ARG 0
# define NBR_OF_PHILOS_ARG 1
# define TIME_TO_DIE_ARG 2
# define TIME_TO_EAT_ARG 3
# define TIME_TO_SLEEP_ARG 4
# define NBR_OF_TIMES_TO_EAT_ARG 5

//includes
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

//aliases
typedef pthread_mutex_t	t_mtx;
typedef pthread_t		t_trd;

//structures
typedef struct s_fork
{
	t_mtx	fork;
	int		id;
}			t_fork;

typedef struct s_table
{
	long	start;
	long	end;
	long	nbr_of_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_of_times_to_eat;
}			t_table;

typedef struct s_philo
{
	int				id;
	t_trd			t;
	t_table			*table;
	t_fork			*l_fork;
	t_fork			*r_fork;
	long			eaten_m;
	long			last_m;
	bool			is_full;
	struct s_philo	*next;
}					t_philo;

//functions
void		ft_error(char *error, char *warning);
long long	ft_atoi(const char *str);
bool		ft_check_args(int ac, char **av);

#endif
