/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:27:48 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/28 14:28:06 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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