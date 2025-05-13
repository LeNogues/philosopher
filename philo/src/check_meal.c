/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_meal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:21:19 by seb               #+#    #+#             */
/*   Updated: 2025/05/11 13:43:57 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	check_meal(t_arg *arg)
{
	int	all_done;

	all_done = 0;
	pthread_mutex_lock(&arg->meal_lock);
	arg->philos_finished_eating++;
	if (arg->philos_finished_eating == arg->nb_philo)
		all_done = 1;
	pthread_mutex_unlock(&arg->meal_lock);
	if (all_done)
		stop_simulation(arg, NULL);
}
