/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <ahaidour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:24:34 by ahaidour          #+#    #+#             */
/*   Updated: 2023/08/16 13:19:15 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <time.h>
# include <sys/time.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_params
{
	int				num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meal_max;
	long			start_time;
	pthread_mutex_t	console_mutex;
	int				is_dead;
	pthread_mutex_t	m_is_dead;
	pthread_t		death_thread;
}	t_params;

typedef struct s_fork
{
	int				used;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_phil
{
	pthread_t		thread;
	int				pos;
	long			last_meal;
	pthread_mutex_t	m_last_meal;
	int				meal_count;
	t_fork			*r_fork;
	int				r_taken;
	t_fork			*l_fork;
	int				l_taken;
	t_params		*params;
}	t_phil;

int		is_dead(t_phil *phil);
void	*check_philos_death(void *arg);
int		stop_threads(t_phil *phil);
void	take_fork(char fork_name, t_phil *phil);
void	release_fork(char fork_name, t_phil *phil);
void	release_forks_and_sleep(t_phil *phil);
int		create_philos(t_phil **philos, t_fork **forks, t_params	*params);
int		init_params(t_params *params, int argc, char **argv);
void	*philo_life(void *arg);
int		create_threads(t_phil **philos, t_params *params);
int		wait_threads(t_phil **philos, t_params *params);
void	ft_usleep(long int time_in_ms);
void	write_state(char *str, t_phil *phil);
long	get_timestamp(void);
#endif
