/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:51:16 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/30 14:44:38 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool check_time_since_last_meal(t_philo *philos, int i)
{
    int time_since_last_meal;
    
    pthread_mutex_lock(&philos->meal_lock);
    time_since_last_meal = current_time(philos[i].start_time) - philos[i].last_meal;
    if (time_since_last_meal >= philos->time_die)
    {
        pthread_mutex_unlock(&philos->meal_lock);
        return false;
    }
    pthread_mutex_unlock(&philos->meal_lock);
    return true;
}

int check_meals_eaten(t_philo *philos, int i)
{
    int philo_finish_eating;

    philo_finish_eating = 0;
    //if there is no extra arg
    if (philos->nb_times_to_eat == -1)
        return 0;
    pthread_mutex_lock(philos[i].meal_lock);
    if (philos[i].meals_eaten >= philos[i].nb_times_to_eat)
        philo_finish_eating++;
    pthread_mutex_unlock(philos[i].meal_lock);
    return (philo_finish_eating);
}

bool check_all_ate(t_philo *philos, int i)
{
    int finish;

    finish = check_meals_eaten(philos, i);
    if (finish == philos->nb_philo)
    {
        pthread_mutex_lock(philos[0].dead_lock);
        *philos->dead = 1;
        pthread_mutex_unlock(philos[0].dead_lock);
        return false;
    }
    return true;
}

void *waitering(void *arg)
{
    t_philo *philo;
    int i;

    philo = (t_philo *)arg;
    while (1)
    {
        i = 0;
        while (i < philo->nb_philo)
        {
            if (check_time_since_last_meal(philo, i) == false)
            {
                print_action("has died", philo[i], philo[i].id);
                pthread_mutex_unlock(&philo->dead_lock);
                *philo->dead = 1;
                pthread_mutex_lock(&philo->dead_lock);
                break ;            
            }
            if (check_all_ate(philo, i) == false)
                break ;
            i++;
        
        }
    }

}

