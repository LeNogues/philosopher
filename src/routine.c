/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:16:24 by seb               #+#    #+#             */
/*   Updated: 2025/05/13 13:19:36 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philosopher_routine(void *argument)
{
	t_philo	*me;

	me = (t_philo *)argument;
	if (me->arg->nb_philo == 1)
	{
		print_status(me->arg, me->id, "has taken a fork");
		usleep(me->arg->time_to_die * 1000);
		stop_simulation(me->arg, me);
		return (NULL);
	}
	if (me->id % 2 != 0)
		usleep(me->arg->time_to_eat / 2 * 1000);
	while (1)
	{
		if (!check_simulation_continue(me->arg))
			break ;
		think_me(me);
		if (is_dead(me))
			break ;
		if (!check_simulation_continue(me->arg))
			break ;
		eat_me(me);
		if (!check_simulation_continue(me->arg))
			break ;
		sleep_me(me);

	}
	return (NULL);
}
