/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <ahaidour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:22:08 by ahaidour          #+#    #+#             */
/*   Updated: 2023/08/10 17:04:56 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	informations(t_info *info, int ac, char **av)
{
	if (ft_atoi(av[1]) > INT_MAX || ft_atoi(av[2]) > INT_MAX
		|| ft_atoi(av[3]) > INT_MAX || ft_atoi(av[4]) > INT_MAX)
		return (0);
	if (ft_atoi(av[1]) < 0 || ft_atoi(av[2]) < 0
		|| ft_atoi(av[3]) < 0 || ft_atoi(av[4]) < 0)
		return (0);
	info->nb_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		info->is_given_max = 1;
		info->max_eaten = ft_atoi(av[5]);
		if (ft_atoi(av[5]) > INT_MAX || ft_atoi(av[5]) < 0)
			return (0);
	}
	// info->max = 0;
	return (1);
}

long get_current_time_milliseconds(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

void initialize_mutexes(t_info *infos) {
    pthread_mutex_init(&infos->time_mutex, NULL);
    pthread_mutex_init(&infos->print_mutex, NULL);
    pthread_mutex_init(&infos->read_mutex, NULL);
    pthread_mutex_init(&infos->increment_mutex, NULL);

    int i = 0;
    while (i < infos->nb_philo) {
        if (pthread_mutex_init(&infos->forks[i], NULL) != 0) {
            retour_erreur("Failed to initialize mutex");
            // Handle error as needed
        }
        i++;
    }
}

void destroy_mutexes(t_info *infos) {
    int i = 0;
    while (i < infos->nb_philo) {
        pthread_mutex_destroy(&infos->forks[i]);
        // Handle any potential error, if necessary
        i++;
    }
    pthread_mutex_destroy(&infos->print_mutex);
    pthread_mutex_destroy(&infos->time_mutex);
    pthread_mutex_destroy(&infos->read_mutex);
    pthread_mutex_destroy(&infos->increment_mutex);
}


int	main(int ac, char **av)
{
	t_info infos;
	if (ac == 5 || ac == 6)
	{
		arg_check(ac, av);
		if (informations(&infos, ac, av))
		{
			initialize_mutexes(&infos);
			// create_philos(&infos);
			sleep(1);
			destroy_mutexes(&infos);
		}
		else
			retour_erreur("Error");
		
	}
	else
		retour_erreur("wrong number of arguments");
}
