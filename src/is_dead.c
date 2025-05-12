/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:31:01 by seb               #+#    #+#             */
/*   Updated: 2025/05/12 17:01:36 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	is_dead(t_philo *philo)
{
	int				time_to_die;
	unsigned long	time_last_meal;
	unsigned long	current_time;
	int i;

	i = 0;
	// printf("id0 : %d\n", philo[0].arg->nb_philo);
	// printf("id3 : %p\n", philo[3].arg);

	while (i < philo[0].arg->nb_philo)
	{
		time_to_die = philo[i].arg->time_to_die;
		time_last_meal = philo[i].last_meal;
		current_time = get_current_time_ms();
		if (current_time - time_last_meal >= (unsigned long)time_to_die)
		{
			stop_simulation(philo[i].arg, philo);
			return (1);
		}
		i++;
	}
	return (0);
}
