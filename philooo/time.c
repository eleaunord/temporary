/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:08:02 by eleroty           #+#    #+#             */
/*   Updated: 2024/05/07 18:13:42 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(int time_action, t_table *table)
{
	int	start;
    int  current;
    
	start = get_time();
    current = start;
	while ((current - start) < time_action && !table->dead_flag)
    {
        usleep(50);
        current = get_time();        
    }
}

int	get_time(void)
{
	static struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int	get_program_time(t_table *table)
{
	return (get_time() - table->creation_time);
}