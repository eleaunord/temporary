/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:53:39 by eleroty           #+#    #+#             */
/*   Updated: 2024/05/07 18:04:13 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

// Waiter check during meal

int	check_dead_flag(t_table *table)
{
	pthread_mutex_lock(&table->program_lock);
	if (table->dead_flag)
	{
		pthread_mutex_unlock(&table->program_lock);
		return (1);
	}
	pthread_mutex_unlock(&table->program_lock);
	return (0);
}

int	check_meals_eaten(t_philo *philo)
{
	if (philo->table->nb_times_to_eat != -1)
	{
		pthread_mutex_lock(&philo->table->program_lock);
		if (philo->nb_times_to_eat == 0)
		{
			pthread_mutex_unlock(&philo->table->program_lock);
			return (1);
		}
		pthread_mutex_unlock(&philo->table->program_lock);
	}
	return (0);
}

int	check_all_ate(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nb_philo)
	{
		if (!check_meals_eaten(&table->philos[i]))
			return (0);
	}
	return (1);
}

// Death check during loop

int	philo_is_dead(t_philo *philo)
{
	size_t	time;

	if (check_meals_eaten(philo))
		return (0);
	time = get_time() - philo->table->creation_time;
	pthread_mutex_lock(&philo->table->program_lock);
	if (time > philo->time_to_die)
	{
		printf("%zu %d died\n", time, philo->id);
		philo->table->dead_flag = 1;
		pthread_mutex_unlock(&philo->table->program_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->program_lock);
	return (0);
}

int	check_deaths(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		if (philo_is_dead(&table->philos[i++]))
			return (1);
	}
	return (0);
}