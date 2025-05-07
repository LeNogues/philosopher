/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:01:59 by seb               #+#    #+#             */
/*   Updated: 2025/05/07 14:44:20 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void print_status(t_arg *arg, int philo_id, char *status)
{
    unsigned long timestamp_ms;

    pthread_mutex_lock(&arg->write_lock);
    if (check_simulation_continue(arg) || strcmp(status, "died") == 0)
    {
        timestamp_ms = get_current_time_ms() - arg->start_time;
        printf("%lu %d %s\n", timestamp_ms, philo_id + 1, status);
    }
    pthread_mutex_unlock(&arg->write_lock);
}