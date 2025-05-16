/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_me.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:51:24 by seb               #+#    #+#             */
/*   Updated: 2025/05/16 14:18:30 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	usleep_eat(unsigned long last, unsigned long tte, t_philo *philo)
{
	while (get_current_time_ms() < last + tte)
	{
		if (get_current_time_ms() < last + tte - 10)
		{
			usleep(10000);
			if (is_dead(philo))
				return (0);
		}
		else
		{
			usleep(get_current_time_ms() - last + tte);
			if (is_dead(philo))
				return (0);
		}
	}
	return (1);
}

int	eat_me(t_philo *philo)
{
	unsigned long	last_meal;
	unsigned long	time_to_eat;

	if (take_fork(philo) == 0)
		return (0);
	print_status(philo->arg, philo->id, "is eating");
	philo->last_meal = get_current_time_ms();
	last_meal = philo->last_meal;
	time_to_eat = philo->arg->time_to_eat;
	philo->time_eaten++;
	if (philo->arg->infinite == 0
		&& philo->time_eaten == philo->arg->nb_time_eat)
		check_meal(philo->arg);
	if (!usleep_eat(last_meal, time_to_eat, philo))
		return (0);
	drop_fork(philo);
	return (1);
}
