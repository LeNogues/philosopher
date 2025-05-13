/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:02:27 by seb               #+#    #+#             */
/*   Updated: 2025/05/13 15:39:26 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_tab(t_philo **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_all(t_arg *arg, t_philo **phil, t_fork *fork, pthread_t *thread_id)
{
	if (fork && arg)
	{
		destroy_mutexes_up_to(fork, arg->nb_philo);
		free(fork);
	}
	free_tab(phil);
	if (arg)
		free(arg);
	(void)thread_id;
	// if (thread_id)
	// 	free(thread_id);
}
