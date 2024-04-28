/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:20:07 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/28 15:08:32 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define MAX 200 // ou 201?

// LIBRAIRES
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
# include <sys/time.h>
// nb_philo time_die time_eat time_sleep
// [nb_must_eat]

// STRUCTURES
// philo structure
typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
    //rules    
    int				nb_philo;
	size_t			time_die;
	size_t			time_sleep;
    int				nb_times_to_eat;    
	int				meals_eaten;
    //var?
	size_t			last_meal;
	size_t			start_time;
	// points to the dead flag in the program struct
	int				*dead;
	// 2 mutex pointers for the forks
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	// 3 mutex pointers that point to the mutex in the program struct
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*write_lock;
}					t_philo;

// program structure
typedef struct s_program
{
	int				dead_flag;
	// 3 mutex
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	// holds all the philo in an array
	t_philo			*philos;
}					t_program;

// FUNCTIONS
// main
int					main(int argc, char *argv[]);
void				check_program_input(int argc, char *argv[]);
void	exit_error(char *message);

// utils
size_t	current_time(long t0);
int					ft_atoi(const char *nptr);
int					is_space(const char num);
int					ft_isdigit(int c);

// init
void				init_program(t_program *program, t_philo *philos);
void				init_rules(char **argv, t_philo *philos);
void				init_philos(t_philo *philos, t_program *program);
void				init_forks(pthread_mutex_t *forks, t_philo *philos);
void				init_philosophers(t_program *program, t_philo *philos,
						char **argv, pthread_mutex_t *forks);
//end
void destroy_philosophers(t_philo *philo, t_program *program, pthread_mutex_t	*forks);
void	exit_error(char *message);

#endif