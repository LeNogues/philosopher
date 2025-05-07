/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:16:24 by seb               #+#    #+#             */
/*   Updated: 2025/05/05 14:37:55 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    *philosopher_routine(void *argument)
{
    t_philo *me;

    me = (t_philo *)argument;
    while(1)
    {
        if(is_dead(me))
            break;
        if (!check_simulation_continue(me->arg))
            break;
        eat_me(me);
        if (!check_simulation_continue(me->arg))
            break;
        sleep_me(me);
        if (!check_simulation_continue(me->arg))
            break;
        think_me(me);
    }
    return (NULL);
}
