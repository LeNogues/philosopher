/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:26:26 by seb               #+#    #+#             */
/*   Updated: 2025/05/11 13:59:27 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

unsigned long	get_current_time_ms(void)
{
	struct timeval	tv;
	unsigned long	tv_sec;
	unsigned long	tv_usec;

	if (gettimeofday(&tv, NULL) == -1)
	{
		printf("time of day failed\n");
		return (0);
	}
	tv_sec = tv.tv_sec * 1000;
	tv_usec = tv.tv_usec / 1000;
	return (tv_sec + tv_usec);
}
