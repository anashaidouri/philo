/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <ahaidour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:22:08 by ahaidour          #+#    #+#             */
/*   Updated: 2023/08/12 14:49:30 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	informations(t_info *args, int ac, char **av)
{
	if (ft_atoi(av[1]) > INT_MAX || ft_atoi(av[2]) > INT_MAX
		|| ft_atoi(av[3]) > INT_MAX || ft_atoi(av[4]) > INT_MAX)
		return (0);
	if (ft_atoi(av[1]) < 0 || ft_atoi(av[2]) < 0
		|| ft_atoi(av[3]) < 0 || ft_atoi(av[4]) < 0)
		return (0);
	args->nb_philo = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		args->is_given_max = 1;
		args->max_eaten = ft_atoi(av[5]);
		if (ft_atoi(av[5]) > INT_MAX || ft_atoi(av[5]) < 0)
			return (0);
	}
	// info->max = 0;
	return (1);
}

long	get_time_in_millisecond(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void initialize_mutexes(t_data *data, t_info *args) {
    pthread_mutex_init(&data->time_mutex, NULL);
    pthread_mutex_init(&data->print_mutex, NULL);
    pthread_mutex_init(&data->read_mutex, NULL);
    pthread_mutex_init(&data->increment_mutex, NULL);
    int i = 0;
    while (i < args->nb_philo) {
        if (pthread_mutex_init(&data->forks[i], NULL) != 0) {
            retour_erreur("Failed to initialize mutex");
            // Handle error as needed
        }
        i++;
    }
}

void destroy_mutexes(t_data *data, t_info *args) {
    int i = 0;
    while (i < args->nb_philo) {
        pthread_mutex_destroy(&data->forks[i]);
        // Handle any potential error, if necessary
        i++;
    }
    pthread_mutex_destroy(&data->print_mutex);
    pthread_mutex_destroy(&data->time_mutex);
    pthread_mutex_destroy(&data->read_mutex);
    pthread_mutex_destroy(&data->increment_mutex);
}

void	ft_sleep(int time_to_eat)
{
	long	time;

	time = get_time_in_millisecond();
	while (get_time_in_millisecond() - time < time_to_eat)
		usleep(100);
}

// void	print_message(t_philo *philo, char *str, int i)
// {
// 	pthread_mutex_lock(&philo->infos->print_mutex);
// 	printf("%ld %d %s\n", get_current_time() - philo->infos->init_time,
// 		philo->id + 1, str);
// 		// printf("********* %d\n", i);
// 	// if ( !i )
// 		// exit ( 0 );
// 	if (i)
// 	{
// 		pthread_mutex_unlock(&philo->infos->print_mutex);
// 	}
// }

void message(t_philo *philo, char *str, int i)
{
    pthread_mutex_lock(&philo->infos->print_mutex);
    if (i) {
        printf("%ld %d %s\n", get_time_in_millisecond() - philo->infos->init_time,
               philo->id + 1, str);
        printf("********* %d\n", i);
    } else {
        printf("%ld %d %s\n", get_time_in_millisecond() - philo->infos->init_time,
               philo->id + 1, str);
        exit(0);
    }
    pthread_mutex_unlock(&philo->infos->print_mutex);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(200);
	while (1)
	{
		// eating(philo);
		message(philo, "is sleeping", 1);
		ft_sleep(philo->args->time_to_sleep);
		message(philo, "is thinking", 1);
	}
}

void	creating_threads(t_data *data, t_info *args, int i)
{
	while (i < args->nb_philo)
	{
		data->philos[i].id = i;
		data->philos[i].eaten_meals = 0;
		data->philos[i].right_fork = i;
		data->philos[i].args = args;
		data->philos[i].last_eat_time = data->init_time;
		if (i == args->nb_philo - 1)
			data->philos[i].left_fork = data->philos[0].right_fork;
		else
			data->philos[i].left_fork = i + 1;
		if (pthread_create(&data->philos[i].thread, NULL, &routine,
				&data->philos[i]) != 0)
		{
			retour_erreur("creating thread failed");
			return ;
		}
		i++;
	}
}

void	initializing_infos(t_data *data,t_info *args)
{
	int	i;

	i = 0;
	creating_threads(data, args, i);
	while (1)
		if (check_death(args, i))
			return ;
}

int	main(int ac, char **av)
{
	t_info args;
	t_data data;
	if (ac == 5 || ac == 6)
	{
		arg_check(ac, av);
		if (informations(&args, ac, av))
		{
			data.forks = malloc(sizeof(pthread_mutex_t) * args.nb_philo);
			data.philos = malloc(sizeof(t_philo) * args.nb_philo);
			initialize_mutexes(&data, &args);
			data.init_time = get_time_in_millisecond();
			initializing_infos(&data, &args);
			sleep(1);
			destroy_mutexes(&data, &args);
		}
		else
			retour_erreur("Error");
		
	}
	else
		retour_erreur("wrong number of arguments");
}
