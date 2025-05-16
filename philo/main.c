/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:40:15 by seb               #+#    #+#             */
/*   Updated: 2025/05/16 12:35:35 by sle-nogu         ###   ########.fr       */
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
		return (free(arg), printf("bad arguments\n"), -1);
	arg->start_time = get_current_time_ms();
	if (!init(arg, &philo, &fork))
		return (free(arg), -1);
	thread_ids = malloc(sizeof(pthread_t) * arg->nb_philo);
	if (!thread_ids)
		return (free_all(arg, philo, fork, thread_ids), -1);
	if (!create_thread(arg, philo, thread_ids))
		return (free_all(arg, philo, fork, thread_ids), -1);
	if (!wait_thread(arg, thread_ids))
		return (free_all(arg, philo, fork, thread_ids), -1);
	free_all(arg, philo, fork, thread_ids);
	return (0);
}
