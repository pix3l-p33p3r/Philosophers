/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 02:20:24 by elel-yak          #+#    #+#             */
/*   Updated: 2023/08/07 22:25:25 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(void)
{
	printf("error\n");
	return (1);
}

void	print_message(char *str, int id, long time, t_vars *vars)
{
	time = ft_timestamps(0) - vars->time_start;
	pthread_mutex_lock(vars->writing);
	pthread_mutex_lock(vars->general);
	if (*(vars->flag))
	{
		pthread_mutex_unlock(vars->writing);
		pthread_mutex_unlock(vars->general);
		return ;
	}
	pthread_mutex_unlock(vars->general);
	printf("%ld Philo %d %s", time, id, str);
	pthread_mutex_unlock(vars->writing);
}

long	ft_timestamps(long time)
{
	struct timeval	current;
	long			current_time;

	gettimeofday(&current, NULL);
	current_time = current.tv_sec * 1000 + current.tv_usec / 1000;
	return (current_time - time);
}

int	check_all_ate(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size && tab[i] == 1)
		i++;
	if (i == size)
		return (1);
	return (0);
}
