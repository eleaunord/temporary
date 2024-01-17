/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:46:27 by eleroty           #+#    #+#             */
/*   Updated: 2024/01/17 17:45:26 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	print_char(va_list lst)
{
	int	c;

	c = (int) va_arg(lst, int);
	ft_putchar(c);
	return (1);
}
