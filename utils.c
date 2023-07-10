/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:20:52 by ahaidour          #+#    #+#             */
/*   Updated: 2023/07/10 18:53:47 by ahaidour         ###   ########.fr       */
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

static int	check1(char *str)
{
	int	i;

	i = 0;
	while (str && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	return (i);
}

static int	check2(char *str, int i, int *s)
{
	if (str && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i + 1] == '-' || str[i + 1] == '+' || str[i + 1] == '\0')
			ft_printerror("Error");
		if (str[i] == '-')
			*s = -(*s);
		i++;
	}
	return (i);
}

long int	ft_atoi(char *str)
{
	int		i;
	int		s;
	long	r;

	s = 1;
	r = 0;
	i = check1(str);
	i = check2(str, i, &s);
	while (str && str[i] >= '0' && str[i] <= '9')
	{
		if (r * 10 + str[i] - 48 < r && s == -1)
			ft_printerror("Error");
		else if (r * 10 + str[i] - 48 < r && s == 1)
			ft_printerror("Error");
		r = r * 10 + str[i] - 48;
		i++;
	}
	if (str && (str[i] == '-' || str[i] == '+'))
		ft_printerror("Error");
	return (r * s);
}
