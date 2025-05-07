/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:31:01 by seb               #+#    #+#             */
/*   Updated: 2025/05/07 13:58:47 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int is_dead(t_philo *philo)
{
    int time_to_die;
    unsigned long time_last_meal;
    unsigned long current_time;

    time_to_die = philo->arg->time_to_die;
    time_last_meal = philo->last_meal;
    current_time = get_current_time_ms();
    if (current_time - time_last_meal > (unsigned long)time_to_die)
    {
        stop_simulation(philo->arg, philo);
        return (1);
    }
        
    return (0);
}