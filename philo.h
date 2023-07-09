/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:22:28 by ahaidour          #+#    #+#             */
/*   Updated: 2023/07/08 15:25:00 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_info
{
	int		div;
	int		mid;
	int		offset;
	int		start;
	int		end;
	int		position;
}			t_info;

typedef struct all
{
	char	*args;
	char	**arg_2d;
	int		size;
}			t_all;

void		retour_erreur(void);
void		arg_check(int ac, char **av);

#endif
