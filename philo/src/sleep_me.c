/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:00:03 by seb               #+#    #+#             */
/*   Updated: 2025/05/14 10:14:24 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	sleep_me(t_philo *philo)
{
	int time_sleeped;

	time_sleeped = 0;
	print_status(philo->arg, philo->id, "is sleeping");
	while(time_sleeped < philo->arg->time_to_sleep)
	{
		usleep(5 * 1000);
		time_sleeped += 5;
		if (is_dead(philo))
			return (0);
	}
	return (1);
}
