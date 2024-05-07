/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:02:11 by eleroty           #+#    #+#             */
/*   Updated: 2024/05/07 17:53:20 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	init_philos(t_table *table)
{
	int	i;

	table->philos = (t_philo *)malloc(sizeof(t_philo) * table->nb_philo);
	if (!table->philos)
		return (1);
    i = -1;
	while (++i < table->nb_philo)
	{
		table->philos[i].id = i + 1;
        table->philos[i].table = table;
		table->philos[i].time_to_die = table->time_to_die;
		table->philos[i].time_to_eat = table->time_to_eat;
		table->philos[i].time_to_sleep = table->time_to_sleep;
        table->philos[i].nb_times_to_eat = table->nb_times_to_eat;
		pthread_mutex_init(&table->philos[i].fork, 0);
		if (i != 0)
		{
			if (i + 1 == table->nb_philo)
				table->philos[i].neighbor = &(table->philos[0]);
			table->philos[i - 1].neighbor = &(table->philos[i]);
		}
		else
			table->philos[0].neighbor = NULL;
	}
	return (0);
}

int	init_table(t_table *table, char **argv)
{
	table->nb_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
    table->nb_times_to_eat = -1;
    if (argv[5])
		table->nb_times_to_eat = ft_atoi(argv[5]);
	pthread_mutex_init(&table->program_lock, 0);
	table->creation_time = get_time();
	table->dead_flag = 0;
	return (init_philos(table));
}