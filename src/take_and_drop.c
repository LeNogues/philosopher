/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_and_drop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:20:50 by seb               #+#    #+#             */
/*   Updated: 2025/05/12 19:00:34 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->left_fork->lock);
		print_status(philo->arg, philo->id, "has taken a fork");
		pthread_mutex_lock(&philo->right_fork->lock);
		print_status(philo->arg, philo->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->right_fork->lock);
		print_status(philo->arg, philo->id, "has taken a fork");
		pthread_mutex_lock(&philo->left_fork->lock);
		print_status(philo->arg, philo->id, "has taken a fork");
	}
}

void	drop_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->left_fork->lock);
		pthread_mutex_unlock(&philo->right_fork->lock);
	}
	else
	{
		pthread_mutex_unlock(&philo->right_fork->lock);
		pthread_mutex_unlock(&philo->left_fork->lock);
	}
}
