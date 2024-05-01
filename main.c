/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:39:53 by eleroty           #+#    #+#             */
/*   Updated: 2024/05/01 19:05:52 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void create_threads(t_program *program, pthread_mutex_t	*forks)
{
    int i;
    pthread_t   waiter;

    if (pthread_create(&waiter, NULL, &waitering, program->philos) != 0)
        stop_it(program, forks);
    i = 0;
    while(i < program->philos[0].nb_philo)
    {
        if (pthread_create(&program->philos[i].thread, NULL, &table_routine, &program->philos[i]) != 0)
        {
            while (i-- >= 0)
                pthread_join(program->philos[i].thread, NULL);
            stop_it(program, forks);
        }
        i++;
    }    
    //CHECK PHILO LIFE
    // if (pthread_create(&waiter, NULL, &waitering, program->philos) != 0)
    //     stop_it(program);
    if (pthread_join(waiter, NULL) != 0)
        stop_it(program, forks);
        
    i = 0;
    while (i < program->philos[0].nb_philo)
    {
        if (pthread_join(program->philos[i].thread, NULL) != 0)
            stop_it(program, forks);
        i++;
    }

}
int	main(int argc, char *argv[])
{
	t_program		program;
	pthread_mutex_t	forks[MAX];
	t_philo			philos[MAX];

    // CHECK ARGS
    if (!argv[1] || argc == 1)
    {
        exit_error("No arguments!\n");
    } 
	check_program_input(argc, argv);
	// init_philosophers(&program, philos, argv, forks);
    
    //INIT PHILOSOPHERS
	init_program(&program, philos);
    init_rules(argv, philos);
	init_forks(forks, ft_atoi(argv[1]));
    init_philos(philos, &program, forks, argv);
    // init_rules(argv, philos);
    //create threads = nb_philo + waiter
    
    //THREADS
    create_threads(&program, forks);
    
    //END IT ALL
    destroy_philosophers(&program, forks);
	return (0);
}
