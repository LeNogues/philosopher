/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:00:03 by seb               #+#    #+#             */
/*   Updated: 2025/05/16 14:14:26 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	sleep_me(t_philo *philo)
{
	unsigned long	start_sleep;
	unsigned long	time_to_sleep;

	start_sleep = get_current_time_ms();
	time_to_sleep = philo->arg->time_to_sleep;
	print_status(philo->arg, philo->id, "is sleeping");
	while (get_current_time_ms() < start_sleep + time_to_sleep)
	{
		if (get_current_time_ms() < start_sleep + time_to_sleep - 10)
		{
			usleep(10000);
			if (is_dead(philo))
				return (0);
		}
		else
		{
			usleep(get_current_time_ms() - start_sleep + time_to_sleep);
			if (is_dead(philo))
				return (0);
		}
	}
	return (1);
}
