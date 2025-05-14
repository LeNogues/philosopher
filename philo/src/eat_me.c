/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_me.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:51:24 by seb               #+#    #+#             */
/*   Updated: 2025/05/13 16:11:29 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	eat_me(t_philo *philo)
{
	if (take_fork(philo) == 0)
		return (0);
	print_status(philo->arg, philo->id, "is eating");
	philo->last_meal = get_current_time_ms();
	philo->time_eaten++;
	if (philo->arg->infinite == 0
		&& philo->time_eaten == philo->arg->nb_time_eat)
		check_meal(philo->arg);
	usleep(philo->arg->time_to_eat * 1000);
	drop_fork(philo);
	return (1);
}
