/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:49:38 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/30 16:13:03 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool dead(t_philo *philo)
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

void action(char *s, t_philo *philo, int id, int time_action)
{
    pthread_mutex_lock(philo->write_lock);
    if (dead(philo) == false)
        printf(s, current_time(philo->start_time), philo->id);
    pthread_mutex_unlock(philo->write_lock);
	//wait for the action
	ft_usleep(philo, time_action);
	//update flags
	philo->eating = 0;
}

void eat(t_philo *philo)
{
    if (pthread_mutex_lock(&philo->right_fork) == 0)
		action("%ld %d has taken a fork\n", philo->last_meal, philo->id, 0);
	if (pthread_mutex_lock(&philo->left_fork) == 0)
        action("%ld %d has taken a fork\n", philo->last_meal, philo->id, 0);
	philo->eating = 1;
	action("%ld %d is eating\n", philo->last_meal, philo->id, philo->time_eat);
    //update last meal
    pthread_mutex_lock(&philo->meal_lock);
    philo->last_meal = current_time(philo->start_time);
	philo->meals_eaten++;
    pthread_mutex_unlock(&philo->meal_lock);
	//unlock forks
    pthread_mutex_unlock(&philo->right_fork);
    pthread_mutex_unlock(&philo->left_fork);
    
} 
void	*table_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->id % 2 == 0)
		action("%ld %d is thinking", philo, philo->id, 1);
	else if (philo->id == philo->nb_philo)
		action("%ld %d is thinking", philo, philo->id, 1);
	while (dead == false)
	{
		eat(philo);
		action("%ld %d is sleeping", philo, philo->id, philo->time_sleep);
		action("%ld %d is thinking", philo, philo->id, 1);
	}
	return arg;
}
