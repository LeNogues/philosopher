/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:16:24 by seb               #+#    #+#             */
/*   Updated: 2025/05/16 14:11:15 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	case_one(t_philo *me)
{
	if (me->arg->nb_philo == 1)
	{
		print_status(me->arg, me->id, "has taken a fork");
		usleep(me->arg->time_to_die * 1000);
		stop_simulation(me->arg, me);
		return (0);
	}
	return (1);
}

void	*philosopher_routine(void *argument)
{
	t_philo	*me;

	me = (t_philo *)argument;
	if (!case_one(me))
		return (NULL);
	if (me->id % 2 != 0)
		usleep(500);
	while (1)
	{
		if (is_dead(me))
			break ;
		if (!check_simulation_continue(me->arg))
			break ;
		if (!eat_me(me))
			break ;
		if (!check_simulation_continue(me->arg))
			break ;
		if (!sleep_me(me))
			break ;
		if (!check_simulation_continue(me->arg))
			break ;
		think_me(me);
	}
	return (NULL);
}
