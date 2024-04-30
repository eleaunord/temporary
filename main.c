/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:39:53 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/30 16:39:15 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void create_threads(t_philo *philos, t_program *program, pthread_mutex_t *forks)
{
    int i;
    pthread_t   waiter;

    if (pthread_create(&waiter, NULL, &waitering, program->philos) != 0)
        stop_it(philos, program, forks);
    i = 0;
    while(i++ < philos->nb_philo)
    {
        if (pthread_create(&philos[i].thread, NULL, &table_routine, &philos[i]) != 0)
        {
            while (i-- >= 0)
                pthread_join(philos[i].id, NULL);
            stop_it(philos, program, forks);
        }
    }
    if (pthread_join(waiter, NULL) != 0)
        stop_it(philos, program, forks);
    i = 0;
    while (i++ < philos->nb_philo)
    {
        if (pthread_join(philos[i].thread, NULL) != 0)
            stop_it(philos, program, forks);
    }
}
int	main(int argc, char *argv[])
{
	t_program		program;
	pthread_mutex_t	forks[MAX];
	t_philo			philos[MAX];

    if (!argv[1] || argc == 1)
    {
        exit_error("No arguments!\n");
    } 
	check_program_input(argc, argv);
	init_philosophers(&program, philos, argv, forks);
    //create threads = nb_philo + waiter
    create_threads(philos, &program, forks);
    destroy_philosophers(philos, program, forks);
	return (0);
}
