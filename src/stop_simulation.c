/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:48:50 by seb               #+#    #+#             */
/*   Updated: 2025/05/11 13:52:11 by seb              ###   ########.fr       */
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
		print_status(arg, philo->id, "died");
	}
	return (1);
}
