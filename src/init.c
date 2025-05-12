/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:41:42 by seb               #+#    #+#             */
/*   Updated: 2025/05/11 14:11:13 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	setup_philo_and_forks(t_arg *arg, t_philo *philo, t_fork *fork, int i)
{
	fork[i].id = i;
	if (pthread_mutex_init(&fork[i].lock, NULL) != 0)
		return (0);
	philo[i].id = i;
	philo[i].arg = arg;
	philo[i].left_fork = &fork[i];
	philo[i].right_fork = &fork[(i + 1) % arg->nb_philo];
	philo[i].time_eaten = 0;
	philo[i].last_meal = arg->start_time;
	return (1);
}

int	init(t_arg *arg, t_philo **philo, t_fork **fork)
{
	int	i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * arg->nb_philo);
	if (!*philo)
		return (0);
	*fork = malloc(sizeof(t_fork) * arg->nb_philo);
	if (!*fork)
		return (free(*philo), 0);
	if (pthread_mutex_init(&arg->stop_lock, NULL) != 0)
	{
		free(*fork);
		free(*philo);
		return (0);
	}
	if (pthread_mutex_init(&arg->write_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&arg->stop_lock);
		free(*fork);
		free(*philo);
		return (0);
	}
	if (pthread_mutex_init(&arg->meal_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&arg->write_lock);
		pthread_mutex_destroy(&arg->stop_lock);
		free(*fork);
		free(*philo);
		return (0);
	}
	while (i < arg->nb_philo)
	{
		if (!setup_philo_and_forks(arg, *philo, *fork, i))
		{
			destroy_mutexes_up_to(*fork, i);
			pthread_mutex_destroy(&arg->stop_lock);
			pthread_mutex_destroy(&arg->write_lock);
			free(*philo);
			free(*fork);
			return (0);
		}
		i++;
	}
	return (1);
}
