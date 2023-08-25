/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 02:20:02 by elel-yak          #+#    #+#             */
/*   Updated: 2023/08/07 22:25:17 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_died(t_vars *vars, int *finished, int index)
{
	*finished = 1;
	pthread_mutex_lock(vars->general);
	*(vars->flag) = 1;
	pthread_mutex_unlock(vars->general);
	pthread_mutex_lock(vars->writing);
	printf("%ld Philo %d has died\n", ft_timestamps(0)
		- vars->last_meal, index + 1);
	pthread_mutex_unlock(vars->writing);
	pthread_mutex_unlock(vars->eating);
}

void	check_helper(t_vars *vars, int *finished, t_args *args)
{
	if (args->max_meals != -1)
	{
		if (check_all_ate(args->all_ate, args->number_of_philos))
		{
			pthread_mutex_lock(vars->general);
			*(vars->flag) = 1;
			pthread_mutex_unlock(vars->general);
			*finished = 1;
		}
	}
}

int	check_philosopher(t_vars *philo, t_args *args, int index)
{
	pthread_mutex_lock(philo->eating);
	if (ft_timestamps(0) - philo->last_meal > args->time_to_die)
	{
		philo_died(philo, &philo->fin, index);
		return (-1);
	}
	if (philo->max_meals == args->max_meals)
		args->all_ate[index] = 1;
	pthread_mutex_unlock(philo->eating);
	return (0);
}

void	finishing(t_vars *vars, t_args *args)
{
	int	i;

	i = 0;
	while (i < args->number_of_philos)
	{
		pthread_join(vars[i].philo_threads, NULL);
		i++;
	}
}

void	check_philosophers(t_vars *help, t_args *number)
{
	int	i;

	help->fin = 0;
	i = 0;
	while (help->fin == 0)
	{
		i = 0;
		while (i < number->number_of_philos)
		{
			if (check_philosopher(&help[i], number, i) == -1)
				return ;
			i++;
		}
		check_helper(help, &help->fin, number);
	}
}
