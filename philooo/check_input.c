/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:08:00 by eleroty           #+#    #+#             */
/*   Updated: 2024/05/07 18:31:28 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_digit_string(char *s)
{
    while (*s)
    {
        if (*s < '0' || *s > '9')
            return (0);
        s++;
    }
    return (1);
}

int	check_input(int argc, char **argv)
{
    int i;
    
	if (argc < 5 || argc > 6)
		return (1);
    i = 1;
	while (i < argc)
    {
        if (!is_digit_string(argv[i]))
            return (1);
        i++;
    }
	return (0);
}