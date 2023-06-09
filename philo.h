/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:22:28 by ahaidour          #+#    #+#             */
/*   Updated: 2023/07/10 18:54:11 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct t_info
{
	int nb_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
}			t_info;

void 		retour_erreur(char *str);
void		arg_check(int ac, char **av);
long int	ft_atoi(char *str);

#endif
