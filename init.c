/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:52:25 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/30 15:56:21 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_program(t_program *program, t_philo *philos)
{
	program->dead_flag = 0;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	program->philos = philos;
}
void	init_rules(char **argv, t_philo *philos)
{
	philos->nb_philo = ft_atoi(argv[1]);
	philos->time_die = ft_atoi(argv[2]);
	philos->time_eat = ft_atoi(argv[3]);
	philos->time_sleep = ft_atoi(argv[4]);
	if (philos->nb_philo == 1)
    {
        ft_usleep(philos->time_die);
		//stop_simulation
    }
	if (argv[5])
		philos->nb_times_to_eat = ft_atoi(argv[5]);
	else
		philos->nb_times_to_eat = -1;
}

void	init_philos(t_philo *philos, t_program *program)
{
	int	i;

	i = 0;
	while (i < philos->nb_philo)
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].start_time = current_time(0);
		philos[i].last_meal = current_time(0);
		philos[i].write_lock = &program->write_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].dead = &program->dead_flag;
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, t_philo *philos)
{
	int	i;
	int right_fork_id;

	i = 0;
	while (i < philos->nb_philo)
		pthread_mutex_init(&forks[i++], NULL);
	i = 0;
	while (i < philos->nb_philo)
	{
		philos[i].left_fork = &forks[i];
		if (i == 0)
			right_fork_id = &forks[philos[i].nb_philo - 1];
		else
			right_fork_id = &forks[i - 1];
		philos[i].right_fork = &forks[right_fork_id];
		i++;
	}
}

void	init_philosophers(t_program *program, t_philo *philos, char **argv,
		pthread_mutex_t *forks)
{
	init_program(program, philos);
	init_rules(argv, philos);
	init_philos(philos, program);
	init_forks(forks, philos);
}