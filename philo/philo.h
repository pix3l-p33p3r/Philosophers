/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 02:21:04 by elel-yak          #+#    #+#             */
/*   Updated: 2023/08/07 22:25:30 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef struct args
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	long			time_start;
	pthread_mutex_t	*writing;
	pthread_mutex_t	*eating;
	pthread_mutex_t	*general;
	pthread_mutex_t	*forks;
	long			last_meal;
	int				*flag;
	int				id;
	int				time;
	int				*all_ate;
}	t_args;

typedef struct s_vars
{
	int				time_to_eat;
	int				id;
	int				time_to_sleep;
	int				max_meals;
	long			time_start;
	pthread_t		philo_threads;
	pthread_mutex_t	*eating;
	pthread_mutex_t	*writing;
	long			last_meal;
	int				*flag;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*general;
	int				fin;
	t_args			*args;
}	t_vars;

int		print_error(void);
int		ft_atoi(char *str);
void	print_message(char *str, int id, long time, t_vars *vars);
void	*routine(void *arg);
int		ft_usleep(int time);
void	check_philosophers(t_vars *vars, t_args *args);
void	finishing(t_vars *vars, t_args *args);
int		check_all_ate(int *tab, int size);
void	allocat(t_args *number);
void	init_philo(t_args *number, t_vars *help);
int		parse_arguments(int ac, char **av, t_args *number);
void	run_philosophers(t_args *number);
int		sleep_think(t_vars *philo);
void	take_left_fork(t_vars *philo);
int		take_right_fork(t_vars *philo);
void	release_forks(t_vars *philo);
int		eat(t_vars *philo);
long	ft_timestamps(long time);
int		parse_max_meals(int ac, char **av, t_args *number);
void	creat_thread(t_args number, t_vars *help);
#endif