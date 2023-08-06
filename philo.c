/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <ahaidour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:22:08 by ahaidour          #+#    #+#             */
/*   Updated: 2023/08/06 19:16:03 by ahaidour         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_info *infos = NULL;
	if (ac == 5 || ac == 6)
	{
		arg_check(ac, av);
		
		if (!informations(infos, ac, av))
		{
			retour_erreur("Error");
		}
		printf("nb philos %d\n", infos->nb_philo);
		printf("time_to_die %d\n", infos->time_to_die);
		printf("time_to_eat %d\n", infos->time_to_eat);
		printf("time_to_sleep %d\n", infos->time_to_sleep);
		printf("is_given_max %d\n", infos->is_given_max);
		printf("max_eaten %d\n", infos->max_eaten);
		
	}
	else
		retour_erreur("wrong number of arguments");
}
