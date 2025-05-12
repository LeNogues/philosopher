/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:40:15 by seb               #+#    #+#             */
/*   Updated: 2025/05/12 19:23:52 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_arg		*arg;
	t_philo		*philo;
	t_fork		*fork;
	pthread_t	*thread_ids;

	arg = malloc(sizeof(t_arg) * 1);
	if (!arg)
		return (-1);
	if (!verif_arg(argc, argv, arg))
		return (printf("bad arguments\n"), -1);
	arg->start_time = get_current_time_ms();
	philo = malloc(sizeof(t_philo) * arg->nb_philo + 1);
	if (!philo)
		return (0);
	if (!init(arg, &philo, &fork))
		return (free(arg), -1);
	thread_ids = malloc(sizeof(pthread_t) * arg->nb_philo);
	if (!thread_ids)
		return (free_all(arg, &philo, fork, thread_ids), -1);
	if (!create_thread(arg, philo, thread_ids))
		return (free_all(arg, &philo, fork, thread_ids), -1);
	
	// printf("p arg : %d\n", philo->arg->infinite);
	while(!arg->should_stop)
	{
		if (is_dead(philo))
		{
			pthread_mutex_lock(&arg->stop_lock);
			arg->should_stop = 1;
			pthread_mutex_unlock(&arg->stop_lock);
		}
	}

	if (!wait_thread(arg, thread_ids))
		return (free_all(arg, &philo, fork, thread_ids), -1);
	free_all(arg, &philo, fork, thread_ids);
	return (0);
}
