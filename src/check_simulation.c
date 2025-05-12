/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:14:56 by seb               #+#    #+#             */
/*   Updated: 2025/05/11 13:44:03 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_simulation_continue(t_arg *arg)
{
	int	continu;

	continu = 1;
	pthread_mutex_lock(&arg->stop_lock);
	if (arg->should_stop == 1)
		continu = 0;
	pthread_mutex_unlock(&arg->stop_lock);
	return (continu);
}
