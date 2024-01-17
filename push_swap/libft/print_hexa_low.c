/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_low.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:48:22 by eleroty           #+#    #+#             */
/*   Updated: 2024/01/17 17:45:46 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hexa_low(va_list lst, int base)
{
	unsigned int	count;
	unsigned int	x;

	x = (unsigned int)va_arg(lst, unsigned int);
	if (x == 0)
	{
		write(1, "0", 1);
		count = 1;
	}
	else
		count = hexa_converter(x, base);
	return (count);
}
