/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaidour <ahaidour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:39:17 by ahaidour          #+#    #+#             */
/*   Updated: 2023/08/16 13:21:51 by ahaidour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = 0;
	start_time = get_timestamp();
	while ((get_timestamp() - start_time) < time_in_ms)
		usleep(100);
}

void	write_state(char *str, t_phil *phil)
{
	long	cur_time;

	cur_time = get_timestamp() - phil->params->start_time;
	pthread_mutex_lock(&(phil->params->console_mutex));
	if (!is_dead(phil))
		printf("%09ld %d %s\n", cur_time, phil->pos, str);
	pthread_mutex_unlock(&(phil->params->console_mutex));
}

long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
