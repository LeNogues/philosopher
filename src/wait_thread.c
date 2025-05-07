/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:09:44 by seb               #+#    #+#             */
/*   Updated: 2025/04/30 14:15:12 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int wait_thread(t_arg *arg, pthread_t *threads_ids)
{
    int i;

    i = 0;
    while (i < arg->nb_philo)
    {
        if (pthread_join(threads_ids[i], NULL) != 0)
            return (0);
        i++;
    }
    return (1);
}
