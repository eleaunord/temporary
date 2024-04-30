/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:27:48 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/30 16:24:55 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//maybe more locks before when exit error?
void game_over(t_philo *philos, int index, t_program *program)
{
    pthread_mutex_lock(&philos->dead_lock);
    program->dead_flag = 1;
    pthread_mutex_unlock(&philos->dead_lock);
    pthread_mutex_lock(&philos->write_lock);
    printf("Philosopher at index : %d has died", index);
    pthread_mutex_unlock(&philos->write_lock);
    exit(EXIT_FAILURE);    
}

void destroy_philosophers(t_philo *philo, t_program *program, pthread_mutex_t	*forks)
{
    int i;
    
    i = 0;
    pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->dead_lock);
	while (i < program->philos[0].nb_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}
void	exit_error(char *message)
{
	printf("%s", message);
    exit(EXIT_FAILURE);
}
void stop_it(t_philo *philos, t_program *program, pthread_mutex_t *forks)
{
    destroy_philosophers(philos, program, forks);
    exit_error("Error creating/joining threads.\n");
}