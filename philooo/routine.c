/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:00:49 by eleroty           #+#    #+#             */
/*   Updated: 2024/05/07 18:19:13 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_for_death(t_philo *philo)
{
	while (1)
	{
		if (check_dead_flag(philo->table))
		{
			pthread_mutex_unlock(&philo->fork);
			return ;
		}
		usleep(500);
	}
}

int	take_forks(t_philo *philo)
{
	if (!check_dead_flag(philo->table))
	{
		if ((philo->id % 2))
			pthread_mutex_lock(&philo->fork);
		else if (philo->neighbor)
			pthread_mutex_lock(&philo->neighbor->fork);
	}
	print_action("has taken a fork\n", philo);
	if (!check_dead_flag(philo->table))
	{
		if (!(philo->id % 2))
			pthread_mutex_lock(&philo->fork);
		else if (philo->neighbor)
			pthread_mutex_lock(&philo->neighbor->fork);
		else
			return (wait_for_death(philo), 1);
		print_action("has taken a fork\n", philo);
	}
	else
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->neighbor->fork);
	}
	return (0);
}

void	eat(t_philo *philo)
{
	if (take_forks(philo))
		return ;
	print_action("is eating\n", philo);
	pthread_mutex_lock(&philo->table->program_lock);
    //the time when a philo should die if they don't start eating again
	philo->time_to_die = get_program_time(philo->table) \
						+ philo->table->time_to_die;
	pthread_mutex_unlock(&philo->table->program_lock);
	ft_sleep(philo->time_to_eat, philo->table);
	pthread_mutex_lock(&philo->table->program_lock);
	philo->nb_times_to_eat--;
	pthread_mutex_unlock(&philo->table->program_lock);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->neighbor->fork);
}

void	sleep_and_think(t_philo *philo)
{
	print_action("is sleeping\n", philo);
	ft_sleep(philo->time_to_sleep, philo->table);
	print_action("is thinking\n", philo);
}