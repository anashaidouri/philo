/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:28:26 by ahaidour          #+#    #+#             */
/*   Updated: 2023/07/10 19:11:05 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	retour_erreur(char *str)
{
	printf("%s\n", str);
}

void	is_empty(int ac, char **av)
{
	int	i;
	int	exist;
	int	j;

	i = 0;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			retour_erreur("Error !!");
		exist = 0;
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != 32 && av[i][j] != '\t')
			{
				exist = 1;
				break ;
			}
			j++;
		}
		if (exist == 0)
			retour_erreur("Error !!");
		i++;
	}
}

int	is_digit(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			n = 1;
		i++;
	}
	return (n);
}

void	arg_check(int ac, char **av)
{
	int	i;
	int	count;

	count = 0;
	is_empty(ac, av);
	i = 1;
	while (i < ac)
	{
		if (is_digit(av[i]))
			retour_erreur("Error !!");
		i++;
	}
}
