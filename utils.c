/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <ahaidour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:20:52 by ahaidour          #+#    #+#             */
/*   Updated: 2023/08/06 19:13:53 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	c;

	c = '\n';
	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
		write(fd, &c, 1);
	}
}

void	ft_printerror(char *s)
{
	ft_putendl_fd(s, 2);
	exit(1);
}

int	if_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	check(const char *str, long int nb, int isneg, int i)
{
	if ((nb * 10 + str[i] - 48 < nb) && (isneg == 1))
		return (-1);
	if ((nb * 10 + str[i] - 48 + 1 < nb) && (isneg == -1))
		return (-1);
	return (1);
}

int	check_dupl_signs(const char *str, int i)
{
	if (((str[i] == '+' || str[i] == '-') && (str[i + 1] == '+' || str[i
					+ 1] == '-' || str[i + 1] == '\0')))
		return (-1);
	if (str[i] == '-')
		return (-1);
	return (1);
}

long int	ft_atoi(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	while (str[i] == 32 || str[i] == '\t')
		i++;
	if (check_dupl_signs(str, i) < 0)
		return (-1);
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		return (-1);
	while (if_digit(str[i]))
	{
		if (check(str, nb, isneg, i) < 0)
			return (-1);
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb * isneg);
}
