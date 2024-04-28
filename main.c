/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:39:53 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/28 15:29:28 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// check nb args, limit 200 for nb_philo, only nbs
void	check_program_input(int argc, char *argv[])
{
	int		i;
	char	*arg;
	int		num;
    
	num = ft_atoi(argv[1]);
	if (argc != 5 && argc != 6)
		exit_error("Error in the number of arguments.\n");
	if (num > 200)
		exit_error("Do not test with more than 200 philosophers.\n");
	i = 1;
	while (i < argc)
	{
		arg = argv[i];
		while (*arg)
		{
			if (!ft_isdigit(*arg))
				exit_error("Command-line arguments must only be unsigned numbers.\n");
			arg++;
		}
		i++;
	}
}
//maybe more locks before when exit error?
void game_over(t_philo *philos, int index, t_program *program)
{
    pthread_mutex_lock(&philos->dead_lock);
    program->dead_flag = 1;
    pthread_mutex_unlock(&philos->dead_lock);
    pthread_mutex_lock(&philos->write_lock);
    printf("Philosopher at index : %d has died", index);
    pthread_mutex_unlock(&philos->write_lock);
    //exit(EXIT_FAILURE);    
}
void check_philo_life(t_philo *philos, t_program *program)
{
    int i;
    int time_since_last_meal;
    
    i = 0;
    while (1)
    {
        //lock and calculate time since last meal
        pthread_mutex_lock(&philos->dead_lock);
        time_since_last_meal = current_time(philos[i].start_time) - philos[i].last_meal;
        pthread_mutex_unlock(&philos->dead_lock);
        if (time_since_last_meal > philos->time_die)
            game_over(philos, i, program);
    }
}

void create_threads(t_philo *philos, t_program *program, pthread_mutex_t *forks)
{
    int i;

    i = 0;
    while(i++ < philos->nb_philo)
    {
        if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]) != 0)
        {
            while (i-- >= 0)
                pthread_join(philos[i].id, NULL);
            destroy_philosophers(philos, program, forks);
            exit_error("Error creating philo thread.\n");
        }
    }
    check_philo_life(philos);
    i = 0;
    while (i++ < philos->nb_philo)
    {
        if (pthread_join(philos[i].thread, NULL) != 0)
        {
            destroy_philosophers(philos, program, forks);
            exit_error("Error joining philo thread.\n");
        }
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
	return (0);
}
