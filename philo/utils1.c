/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 02:21:09 by elel-yak          #+#    #+#             */
/*   Updated: 2023/08/07 22:25:35 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_arguments(int ac, char **av, t_args *number)
{
	number->number_of_philos = ft_atoi(av[1]);
	number->time_to_die = ft_atoi(av[2]);
	number->time_to_eat = ft_atoi(av[3]);
	number->time_to_sleep = ft_atoi(av[4]);
	number->max_meals = -1;
	number->all_ate = NULL;
	if (number->number_of_philos <= 0 || number->time_to_die <= 0
		|| number->time_to_eat <= 0 || number->time_to_sleep <= 0)
	{
		print_error();
		return (1);
	}
	if (parse_max_meals(ac, av, number) == 1)
		return (1);
	return (0);
}

void	allocat(t_args *number)
{
	number->eating = malloc(sizeof(pthread_mutex_t));
	number->writing = malloc(sizeof(pthread_mutex_t));
	number->general = malloc(sizeof(pthread_mutex_t));
	number->forks = malloc(sizeof(pthread_mutex_t) * number->number_of_philos);
	number->flag = malloc(sizeof(int));
	*(number->flag) = 0;
	number->time = ft_timestamps(0);
}

void	init_philo(t_args *number, t_vars *help)
{
	int	j;

	j = 0;
	allocat(number);
	pthread_mutex_init(number->eating, NULL);
	pthread_mutex_init(number->writing, NULL);
	pthread_mutex_init(number->general, NULL);
	while (j < number->number_of_philos)
	{
		help[j].id = j + 1;
		help[j].left_fork = &number->forks[j];
		help[j].right_fork = &number->forks[(j + 1) % number->number_of_philos];
		help[j].last_meal = ft_timestamps(0);
		help[j].eating = number->eating;
		help[j].writing = number->writing;
		help[j].general = number->general;
		help[j].time_start = ft_timestamps(0);
		help[j].max_meals = 0;
		help[j].flag = number->flag;
		help[j].time_to_eat = number->time_to_eat;
		help[j].time_to_sleep = number->time_to_sleep;
		pthread_mutex_init(&number->forks[j], NULL);
		j++;
	}
}

void	run_philosophers(t_args *number)
{
	t_vars	*help;

	help = malloc(sizeof(t_vars) * number->number_of_philos);
	if (help == NULL)
	{
		print_error();
		return ;
	}
	init_philo(number, help);
	creat_thread(*number, help);
	check_philosophers(help, number);
	if (number->number_of_philos != 1)
		finishing(help, number);
}
