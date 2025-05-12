/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:47:20 by seb               #+#    #+#             */
/*   Updated: 2025/05/11 14:03:10 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	create_thread(t_arg *arg, t_philo *philo, pthread_t *thread_ids)
{
	int	i;

	i = 0;
	while (i < arg->nb_philo)
	{
		if (pthread_create(&thread_ids[i], NULL,
				philosopher_routine, (void *)&philo[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}
