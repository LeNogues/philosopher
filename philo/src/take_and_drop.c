/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_and_drop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:20:50 by seb               #+#    #+#             */
/*   Updated: 2025/05/16 13:56:11 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_trylock(pthread_mutex_t *lock, t_philo *philo, t_fork *fork)
{
	while (1)
	{
		pthread_mutex_lock(lock);
		if (fork->status == 1)
		{
			fork->status = 0;
			pthread_mutex_unlock(lock);
			break ;
		}
		pthread_mutex_unlock(lock);
		if (is_dead(philo))
			return (0);
		usleep(500);
	}
	return (1);
}

int	take_fork(t_philo *philo)
{
	if (philo->id + 1 % 2 == 0)
	{
		if (!ft_trylock(&philo->left_fork->lock, philo, philo->left_fork))
			return (0);
		print_status(philo->arg, philo->id, "has taken a fork");
		if (!ft_trylock(&philo->right_fork->lock, philo, philo->right_fork))
			return (0);
		print_status(philo->arg, philo->id, "has taken a fork");
	}
	else
	{
		if (!ft_trylock(&philo->right_fork->lock, philo, philo->right_fork))
			return (0);
		print_status(philo->arg, philo->id, "has taken a fork");
		if (!ft_trylock(&philo->left_fork->lock, philo, philo->left_fork))
			return (0);
		print_status(philo->arg, philo->id, "has taken a fork");
	}
	return (1);
}

void	drop_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->left_fork->lock);
		philo->left_fork->status = 1;
		pthread_mutex_unlock(&philo->left_fork->lock);
		pthread_mutex_lock(&philo->right_fork->lock);
		philo->right_fork->status = 1;
		pthread_mutex_unlock(&philo->right_fork->lock);
	}
	else
	{
		pthread_mutex_lock(&philo->right_fork->lock);
		philo->right_fork->status = 1;
		pthread_mutex_unlock(&philo->right_fork->lock);
		pthread_mutex_lock(&philo->left_fork->lock);
		philo->left_fork->status = 1;
		pthread_mutex_unlock(&philo->left_fork->lock);
	}
}
