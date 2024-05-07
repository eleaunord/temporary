/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:01:20 by eleroty           #+#    #+#             */
/*   Updated: 2024/05/07 18:14:02 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_handling(t_table *table, char *message)
{
	printf("%s\n", message);
	free(table->philos);
	exit (0);
}


void	print_action(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->table->program_lock);
	if (!(philo->table->dead_flag))
		printf("%d %d %s\n", get_program_time(philo->table), philo->id, str);
	pthread_mutex_unlock(&philo->table->program_lock);
}
int	is_space(const char num)
{
	if (num == 32 || (num >= 9 && num <= 13))
		return (0);
	else
		return (1);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (is_space(nptr[i]) == 0)
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			sign = -1;
		i++;
	}
	if (nptr[i] >= '0' && nptr[i] <= '9')
	{
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			res = res * 10 + (nptr[i++] - '0');
		}
	}
	else
		return (0);
	return (res * sign);
}

