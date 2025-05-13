/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:37:11 by seb               #+#    #+#             */
/*   Updated: 2025/05/13 17:20:20 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	verif_neg_arg(t_arg *arg)
{
	if (arg->nb_philo <= 0)
		return (0);
	if (arg->time_to_die <= 0)
		return (0);
	if (arg->time_to_eat <= 0)
		return (0);
	if (arg->time_to_sleep <= 0)
		return (0);
	if (arg->infinite == 0)
		if (arg->nb_time_eat <= 0)
			return (0);
	return (1);
}

int	is_numeric(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	verif_arg(int argc, char **argv, t_arg *arg)
{
	if (argc != 5 && argc != 6)
		return (0);
	if (is_numeric(argv) == 0)
		return (0);
	arg->nb_philo = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	arg->should_stop = 0;
	arg->philos_finished_eating = 0;
	if (argv[5])
	{
		arg->infinite = 0;
		arg->nb_time_eat = ft_atoi(argv[5]);
	}
	else
		arg->infinite = 1;
	if (verif_neg_arg(arg) == 0)
		return (0);
	return (1);
}
