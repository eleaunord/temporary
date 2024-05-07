/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:52:36 by eleroty           #+#    #+#             */
/*   Updated: 2024/05/07 18:19:17 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	struct s_table	*table;
	pthread_t		thread;
	int				id;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	int				nb_times_to_eat;
	pthread_mutex_t	fork;
	struct s_philo	*neighbor;
}					t_philo;

typedef struct s_table
{
	int				nb_philo;
	t_philo			*philos;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				nb_times_to_eat;
	int				dead_flag;
	pthread_mutex_t	program_lock;
	int				creation_time;
}					t_table;

void				exit_handling(t_table *table, char *msg);
int					init_table(t_table *table, char **argv);
int					check_input(int argc, char *argv[]);
void				sleep_and_think(t_philo *philo);
void				eat(t_philo *philo);
void				ft_sleep(int time_action, t_table *table);
int					check_meals_eaten(t_philo *philo);
int					check_all_ate(t_table *table);
int					get_time(void);
int					get_program_time(t_table *table);
int					check_deaths(t_table *table);
int					check_dead_flag(t_table *table);
void				create_threads(t_table *table);
void				print_action(char *str, t_philo *philo);
int					ft_atoi(const char *nptr);
void				end_threads(t_table *table);
void				create_threads(t_table *table);

#endif
