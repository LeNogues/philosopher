/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:40:32 by seb               #+#    #+#             */
/*   Updated: 2025/05/07 13:58:18 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct  s_arg
{
	int nb_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int infinite;
	int nb_time_eat;
	int	should_stop;
	pthread_mutex_t stop_lock;
	pthread_mutex_t write_lock;	
	unsigned long start_time;
}               t_arg;

typedef struct s_fork
{
	pthread_mutex_t lock;
	int             id;
}              t_fork;

typedef struct  s_philo
{
	int             id;
	t_fork          *right_fork;
	t_fork          *left_fork;
	t_arg           *arg;
	unsigned long   last_meal;
	int             time_eaten;
}               t_philo;




//main.c
int main(int argc, char **argv);
///////////////////////////////////////////////////////////////////////////////

//parsing.c
int					verif_arg(int argc, char **argv, t_arg *arg);
int					is_numeric(char **argv);
int					verif_neg_arg(t_arg *arg);
///////////////////////////////////////////////////////////////////////////////

//init.c
int 				init(t_arg *arg, t_philo **philo, t_fork **fork);
///////////////////////////////////////////////////////////////////////////////

//get_time.c
unsigned long 		get_current_time_ms(void);
///////////////////////////////////////////////////////////////////////////////

//create_thread.c
int 				create_thread(t_arg *arg, t_philo *philo, pthread_t *thread_ids);
///////////////////////////////////////////////////////////////////////////////

//free.c
void    free_all(t_arg *arg, t_philo *philo, t_fork *fork, pthread_t *threads_ids);
///////////////////////////////////////////////////////////////////////////////

//destroy_mutex.c
void destroy_mutexes_up_to(t_fork *forks, int n);
///////////////////////////////////////////////////////////////////////////////

//wait_thread.c
int wait_thread(t_arg *arg, pthread_t *threads_ids);
///////////////////////////////////////////////////////////////////////////////

//routine.c
void    *philosopher_routine(void *argument);
///////////////////////////////////////////////////////////////////////////////

//check_simulation.c
int check_simulation_continue(t_arg *arg);
///////////////////////////////////////////////////////////////////////////////

//think_me.c
void   think_me(t_philo *philo);
///////////////////////////////////////////////////////////////////////////////

//sleep_me.c
void    sleep_me(t_philo *philo);
///////////////////////////////////////////////////////////////////////////////

//eat.me
void    eat_me(t_philo *philo);
///////////////////////////////////////////////////////////////////////////////

//print_status.c
void print_status(t_arg *arg, int philo_id, char *status);
///////////////////////////////////////////////////////////////////////////////

//take_and_drop.c
void    drop_fork(t_philo *philo);
void    take_fork(t_philo *philo);
///////////////////////////////////////////////////////////////////////////////

//is_dead.c
int is_dead(t_philo *philo);
///////////////////////////////////////////////////////////////////////////////

//stop_simulation.c
int stop_simulation(t_arg *arg, t_philo *philo);
///////////////////////////////////////////////////////////////////////////////

//ft_atoi.c
int	ft_atoi(const char *nptr);
///////////////////////////////////////////////////////////////////////////////

#endif