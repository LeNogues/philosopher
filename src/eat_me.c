/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_me.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:51:24 by seb               #+#    #+#             */
/*   Updated: 2025/05/12 15:16:08 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	eat_me(t_philo *philo)
{
	take_fork(philo);
	if (!check_simulation_continue(philo->arg))
		return (0) ;
	print_status(philo->arg, philo->id, "is eating");
	philo->last_meal = get_current_time_ms();
	philo->time_eaten++;
	if (philo->arg->infinite == 0 && philo->time_eaten == philo->arg->nb_time_eat)
		check_meal(philo->arg);
	usleep(philo->arg->time_to_eat * 1000);
	drop_fork(philo);
	return (1);
}
