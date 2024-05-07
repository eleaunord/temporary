/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:52:58 by eleroty           #+#    #+#             */
/*   Updated: 2024/05/07 17:59:11 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
		pthread_join(table->philos[i++].thread, NULL);
	i = 0;
	while (i < table->nb_philo)
		pthread_mutex_destroy(&table->philos[i++].fork);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (check_dead_flag(philo->table))
			break ;
		eat(philo);
		if (check_meals_eaten(philo) || check_dead_flag(philo->table))
			break ;
		sleep_and_think(philo);
	}
	return (NULL);
}
void	create_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_create(&(table->philos[i].thread), NULL, &philo_routine, (void *)&table->philos[i]) != 0)
            exit_handling(table, "Error durring thread creation.");
        i++;
	}
}
void death_loop(t_table *table)
{
    while (!check_all_ate(table))
	{
		if (check_deaths(table))
			break ;
		usleep(200);
	}
}
int	main(int argc, char *argv[])
{
	t_table	table;

	table.philos = NULL;
	if (check_input(argc, argv))
		exit_handling(&table, "Invalid arguments.");
	if (init_table(&table, argv))
		exit_handling(&table, "Error initializing.");
	create_threads(&table);
    death_loop(&table);
	end_threads(&table);
	free(table.philos);
	return (0);
}
