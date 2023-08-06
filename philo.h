/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <ahaidour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:22:28 by ahaidour          #+#    #+#             */
/*   Updated: 2023/08/06 19:15:02 by ahaidour         ###   ########.fr       */
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
	int is_given_max;
	int max_eaten;
}			t_info;

void 		retour_erreur(char *str);
void		arg_check(int ac, char **av);
long int	ft_atoi(const char *str);
int			is_digit(char *str);

#endif
