/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:26:26 by seb               #+#    #+#             */
/*   Updated: 2025/05/07 14:08:27 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

unsigned long get_current_time_ms(void)
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL) == -1)
    {
        printf("time of day failed\n");
        return (0);
    }
    return ((unsigned long)(tv.tv_sec) * 1000 + (unsigned long)(tv.tv_usec) / 1000);
}