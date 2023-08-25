/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 02:20:44 by elel-yak          #+#    #+#             */
/*   Updated: 2023/08/07 22:25:28 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	creat_thread(t_args number, t_vars *help)
{
	int	i;
	int	res;

	i = 0;
	while (i < number.number_of_philos)
	{
		res = pthread_create(&help[i].philo_threads, NULL, routine, &help[i]);
		if (res)
			print_error();
		usleep(50);
		i++;
	}
}

int	parse_max_meals(int ac, char **av, t_args *number)
{
	if (ac == 6)
	{
		number->max_meals = ft_atoi(av[5]);
		if (number->max_meals <= 0)
		{
			print_error();
			return (1);
		}
		number->all_ate = malloc(sizeof(int) * number->number_of_philos);
		if (number->all_ate == NULL)
		{
			print_error();
			return (1);
		}
	}
	return (0);
}

void	*routine(void *arg)
{
	t_vars	*philo;

	philo = (t_vars *)arg;
	while (1)
	{
		take_left_fork(philo);
		if (take_right_fork(philo) == -1)
			break ;
		eat (philo);
		if (sleep_think(philo) == -1)
			break ;
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_args	number;

	if (ac < 5 || ac > 6)
	{
		print_error();
		return (1);
	}
	if (parse_arguments(ac, av, &number) == 0)
		run_philosophers(&number);
	else
		return (1);
}
