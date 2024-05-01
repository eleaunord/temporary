/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:21:33 by eleroty           #+#    #+#             */
/*   Updated: 2024/05/01 16:12:15 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_usleep(size_t time_action)
{
	size_t start;
	size_t current;

	start = current_time(0);
	current = start;
	while((current - start) < time_action)
	{
		usleep(500);
		current = current_time(0);
	}
}
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
size_t	current_time(long t0)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		exit_error("Error with gettimeofday() function.\n");
	return (time.tv_usec / 1000 + time.tv_sec * 1000 - t0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
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