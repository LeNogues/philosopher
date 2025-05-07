/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_me.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:51:24 by seb               #+#    #+#             */
/*   Updated: 2025/05/05 15:37:11 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    eat_me(t_philo *philo)
{
    take_fork(philo);
    print_status(philo->arg, philo->id, "is eating");
    philo->last_meal = get_current_time_ms();
    philo->time_eaten++;
    usleep(philo->arg->time_to_eat * 1000);
    drop_fork(philo);
}
