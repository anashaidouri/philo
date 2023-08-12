/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <ahaidour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:22:28 by ahaidour          #+#    #+#             */
/*   Updated: 2023/08/12 13:19:10 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <sys/time.h>

typedef struct t_philo
{
	pthread_t			thread;
	int					id;
	int					right_fork;
	int					left_fork;
	long				last_eat_time;
	int					eaten_meals;
	struct t_info		*args;
	struct t_data		*data;
}						t_philo;

typedef struct t_info
{
	int nb_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int is_given_max;
	int max_eaten;
}			t_info;

typedef struct t_data
{
	long			init_time;
	pthread_mutex_t time_mutex;
    pthread_mutex_t print_mutex;
    pthread_mutex_t read_mutex;
    pthread_mutex_t increment_mutex;
    pthread_mutex_t *forks;
	struct t_philo	*philos;
}					t_data;

void 		retour_erreur(char *str);
void		arg_check(int ac, char **av);
long int	ft_atoi(const char *str);
int			is_digit(char *str);

#endif
