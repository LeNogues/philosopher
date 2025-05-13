/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:26:46 by seb               #+#    #+#             */
/*   Updated: 2025/05/13 12:11:39 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	think_me(t_philo *philo)
{
	print_status(philo->arg, philo->id, "is thinking");
	if (philo->arg->nb_philo % 2 != 0)
		usleep(philo->arg->time_to_sleep / 2 * 50);
}
