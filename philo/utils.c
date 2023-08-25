/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 02:20:09 by elel-yak          #+#    #+#             */
/*   Updated: 2023/08/07 22:25:32 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		print_error();
	return ((tv.tv_sec * (long long)1000) + (tv.tv_usec / 1000));
}

int	ft_usleep(int time)
{
	long long	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}

int	ft_atoi(char *str)
{
	int	r;
	int	i;

	i = 0;
	r = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		return (-1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			r = (r * 10) + (str[i] - 48);
			i++;
		}
		else
			return (-1);
	}
	if (r > INT16_MAX)
		return (-1);
	return (r);
}
