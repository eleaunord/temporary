/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:49:38 by eleroty           #+#    #+#             */
/*   Updated: 2024/05/01 19:15:25 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (true);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (false);
}
void	action(char *message, t_philo *philo, int time_action)
{
	pthread_mutex_lock(philo->write_lock);
	if (dead(philo) == false)
		printf(message, current_time(philo->start_time), philo->id);
	pthread_mutex_unlock(philo->write_lock);
	// wait for the action
	ft_usleep(time_action);
}

void	eat(t_philo *philo)
{
	if (!pthread_mutex_lock(philo->right_fork) && !pthread_mutex_lock(philo->left_fork))
	{
		// update last meal
		pthread_mutex_lock(philo->meal_lock);
		philo->last_meal = current_time(philo->start_time);
		philo->meals_eaten++;
		philo->eating = 1;
		pthread_mutex_unlock(philo->meal_lock);
		
		//print meal
		pthread_mutex_lock(philo->write_lock);
		printf("%ld %d has taken a fork\n", philo->last_meal, philo->id);
		printf("%ld %d has taken a fork\n", philo->last_meal, philo->id);
		printf("%ld %d is eating\n", philo->last_meal, philo->id);
		pthread_mutex_unlock(philo->write_lock);
		
		// wait eating time
		ft_usleep(philo->time_eat);
		
		//update meal flags
		pthread_mutex_lock(philo->meal_lock);
		philo->eating = 0;//unecessary?
		philo->nb_times_to_eat--;
		pthread_mutex_unlock(philo->meal_lock);
	}
	// unlock forks
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

// void	*table_routine(void *arg)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)arg;
// 	if (philo->nb_philo == 1)
// 	{
// 		action("%ld %d has taken a fork\n", philo, 1);
// 		return (arg);
// 	}
// 	while (dead(philo) == false)
// 	{
// 		// eat(philo);
// 		action("%ld %d is sleeping\n", philo, philo->time_sleep);
// 		action("%ld %d is thinking\n", philo, 1);
// 	}
// 	return (arg);
// }

// void	print_message(char *str, t_philo *philo, int id)
// {
// 	size_t	time;

// 	pthread_mutex_lock(philo->write_lock);
// 	time = current_time(0) - philo->start_time;
// 	if (!dead_loop(philo))
// 		printf("%zu %d %s\n", time, id, str);
// 	pthread_mutex_unlock(philo->write_lock);
// }
// int	dead_loop(t_philo *philo)
// {
// 	pthread_mutex_lock(philo->dead_lock);
// 	if (*philo->dead == 1)
// 		return (pthread_mutex_unlock(philo->dead_lock), 1);
// 	pthread_mutex_unlock(philo->dead_lock);
// 	return (0);
// }

void	think(t_philo *philo)
{
	action("%ld %d is sleeping\n", philo, philo->start_time);
}

// Dream routine funtion

// Thread routine

void	*table_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (dead(philo) == false)
	{
		// eat(philo);
		// dream(philo);
		think(philo);
	}
	return (pointer);
}