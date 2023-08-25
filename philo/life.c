/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 02:20:38 by elel-yak          #+#    #+#             */
/*   Updated: 2023/08/07 22:25:21 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sleep_think(t_vars *philo)
{
	print_message("is sleeping\n", philo->id,
		ft_timestamps(philo->time_start), philo);
	ft_usleep(philo->time_to_sleep);
	pthread_mutex_lock(philo->general);
	if (*(philo->flag))
	{
		pthread_mutex_unlock(philo->general);
		return (-1);
	}
	pthread_mutex_unlock(philo->general);
	print_message("is thinking\n", philo->id,
		ft_timestamps(philo->time_start), philo);
	return (0);
}

void	take_left_fork(t_vars *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->general);
	pthread_mutex_unlock(philo->general);
	print_message("has taken left fork\n", philo->id,
		ft_timestamps(philo->time_start), philo);
}

int	take_right_fork(t_vars *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->general);
	if (philo->left_fork == philo->right_fork)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (-1);
	}
	return (0);
}

void	release_forks(t_vars *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	eat(t_vars *philo)
{
	pthread_mutex_unlock(philo->general);
	print_message("has taken right fork\n", philo->id,
		ft_timestamps(philo->time_start), philo);
	pthread_mutex_lock(philo->eating);
	print_message("is eating\n", philo->id, ft_timestamps(0), philo);
	philo->last_meal = ft_timestamps(0);
	philo->max_meals++;
	pthread_mutex_unlock(philo->eating);
	ft_usleep(philo->time_to_eat);
	release_forks(philo);
	return (0);
}
