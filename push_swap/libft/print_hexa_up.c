/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:48:33 by eleroty           #+#    #+#             */
/*   Updated: 2024/01/17 17:45:56 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hexa_up(va_list lst, int base)
{
	unsigned int	count;
	unsigned int	up_x;

	up_x = (unsigned int)va_arg(lst, unsigned int);
	if (up_x == 0)
	{
		write(1, "0", 1);
		count = 1;
	}
	else
		count = hexa_converter(up_x, base);
	return (count);
}
