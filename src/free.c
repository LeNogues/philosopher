/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:02:27 by seb               #+#    #+#             */
/*   Updated: 2025/04/30 13:42:30 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"


void    free_all(t_arg *arg, t_philo *philo, t_fork *fork, pthread_t *threads_ids)
{
    if (fork && arg)
    {
        destroy_mutexes_up_to(fork, arg->nb_philo);
        free(fork);
    }
    if (philo)
        free(philo);
    if (arg)
        free(arg);
    if (threads_ids)
        free(threads_ids);
    
}