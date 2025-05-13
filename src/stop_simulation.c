/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:48:50 by seb               #+#    #+#             */
/*   Updated: 2025/05/13 11:45:12 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	stop_simulation(t_arg *arg, t_philo *philo)
{
	pthread_mutex_lock(&arg->stop_lock);
	if (arg->should_stop == 1)
	{
		pthread_mutex_unlock(&arg->stop_lock);
		return (0);
	}
	arg->should_stop = 1;
	pthread_mutex_unlock(&arg->stop_lock);
	if (philo != NULL)
	{
		print_status(arg, philo->id + 1, "died");
	}
	return (1);
}
